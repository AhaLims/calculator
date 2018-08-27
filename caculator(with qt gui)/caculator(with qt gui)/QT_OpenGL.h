#pragma once

#include <QtWidgets/QWidget>
#include "ui_QT_OpenGL.h"
#include <GL/glut.h>
#include"source.h"

#pragma once
#include<iostream>
#include<string>
#include<map>//用map存未知数
#include <stack>
#include <cctype>
#include <cstdlib>
#include <cmath>
namespace EXPRESSION
{
	enum TYPE
	{
		UNKNOW_TYPE,//错误输入
		OPERATOR_TYPE,//运算符
		NUM_TYPE,//数字
		VARIABLE_TYPE,//变量
		FUNCTION_TYPE,//函数
		END_TYPE//结束符
	};
	enum SYSTERM
	{
		ANGLE_SYSTERM,//角度制
		RADIAN_SYSTERM//弧度制
	};
	const double pi = 3.141592653;

}
//#define DEBUG
//未知数第一个字符只能是字母 且后面只能出现字母和数字
//也许可以加入 pi 和 e
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

/*界面*/
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
	int getAns(double &, double Value[] = nullptr);//计算的外部接口

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
	bool getDerivativeValue(double,double &);//微分具体的值
	bool getIntergralValue(double, double,double &);//积分具体的值
private:
	string VariableName[1];//pi e
	string expression;
	Expression *FunctionExpression;
	double eps;
};