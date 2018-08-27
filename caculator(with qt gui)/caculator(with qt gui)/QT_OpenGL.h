#pragma once

#include <QtWidgets/QWidget>
#include "ui_QT_OpenGL.h"
#include <GL/glut.h>
#include"source.h"

#pragma once
#include<iostream>
#include<string>
#include<map>//��map��δ֪��
#include <stack>
#include <cctype>
#include <cstdlib>
#include <cmath>
namespace EXPRESSION
{
	enum TYPE
	{
		UNKNOW_TYPE,//��������
		OPERATOR_TYPE,//�����
		NUM_TYPE,//����
		VARIABLE_TYPE,//����
		FUNCTION_TYPE,//����
		END_TYPE//������
	};
	enum SYSTERM
	{
		ANGLE_SYSTERM,//�Ƕ���
		RADIAN_SYSTERM//������
	};
	const double pi = 3.141592653;

}
//#define DEBUG
//δ֪����һ���ַ�ֻ������ĸ �Һ���ֻ�ܳ�����ĸ������
//Ҳ����Լ��� pi �� e
//using namespace std;

const int OPERATOR_AMOUNT = 9;
const int FUN_AMOUNT = 9;

class Function_2D;
class Expression;
void KeyBoards(unsigned char key, int x, int y);//register keboard event
extern class QTOpenGL
{
public:
	QTOpenGL(int, char*[]);
	static void draw_axis();
	static void draw_function();
	void start_OpenGL();
	static bool getY(float, Function_2D*,double &);

	void move_left();
	void move_right();
	void move_up();
	void move_down();
	void enlarge();
	void lessen();
	void reset();

private:
	int argc;
	char **argv;
	
	//Function_2D FunctionExpression;
public:
	static const double NormalFactor;
	static const int Width;
	static const int Height;
	static double times;
	static const GLfloat PI;
	static const int centre_x; 
	static const int centre_y;
	static double LevelMovement, ViticalMovement;
	static double factor;//enlarge or lessen
};

/*����*/
class QT_OpenGL : public QWidget
{
	Q_OBJECT

public:
	QT_OpenGL(QTOpenGL * ptr = nullptr,QWidget *parent = Q_NULLPTR);
	~QT_OpenGL();
private:
	void paintEvent(QPaintEvent * e);
	Ui::QT_OpenGLClass ui;
	QTOpenGL * qtopengl_ptr;
private slots:
	void push_help();
	void push_example();
	void push_OK();
	void push_left();
	void push_right();
	void push_up();
	void push_down();
	void push_enlarge();
	void push_lessen();
	void push_reset();

};


class Expression
{
public:
	Expression(string str, int variable_amount = 0, string variable[] = nullptr);
	~Expression();
	//string input(const string str);
	int getAns(double &, double Value[] = nullptr);//������ⲿ�ӿ�

	void read(int & pos);//read a "word" each time and judge what tpye the word is
	EXPRESSION::TYPE type;
	string token;//"word"
private:
	int brackets_amount;

	/*manage the expression*/
	string input(const string str);

	/*read a "word" each time and judge what tpye the word is*/
	//	void read(int & pos);

	/*calculate part*/

	/*compare operator */
	int compare(string, string)const;

	bool getValue(stack<double>& operand, double x[], int n);

	/*caculator*/
	double OperatorCalculate(string, double[]);
	double FunctionCalculate(string, double[]);

	/*judge what kind it is*/
	static int isFunction(string str);
	int isVariable(string str)const;
	static int isOperator(string str);

	/*get word type*/
	//	EXPRESSION::TYPE type;
	/*static operator funtion and the variable they need*/

	/*operator*/
	static const string Operator[OPERATOR_AMOUNT];
	static const int OperatorNeedAmount[OPERATOR_AMOUNT];
	static const int OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT];//prioity

																   /*fucntion*/
	static const string function[FUN_AMOUNT];//function
	static const int functionNeedAmount[FUN_AMOUNT];//mark the data of function

													/*variable:from name to value*/
	map<string, double>VariableMap;
	string *VariableName;
	int VariableAmount;

	/*expression*/
	string exp;

	/*judge if the expression is bad expression*/
	bool check_input;

	/*use radians or degree*/
	EXPRESSION::SYSTERM expression_systerm;



};



class Function_2D
{
public:
	Function_2D(string, string);
	void reset(string,string);
	~Function_2D();
	bool getAns(double,double &);
	bool getDerivativeValue(double,double &);//΢�־����ֵ
	bool getIntergralValue(double, double,double &);//���־����ֵ
private:
	string VariableName[1];//pi e
	string expression;
	Expression *FunctionExpression;
	double eps;
};