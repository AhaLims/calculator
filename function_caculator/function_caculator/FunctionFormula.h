#pragma once
#include<iostream>
#include<string>
#include<map>//��map��δ֪��
#include <stack>
#include <cctype>
#include <cstdlib>
#include <cmath>
#define DEBUG
//δ֪����һ���ַ�ֻ������ĸ �Һ���ֻ�ܳ�����ĸ������
using namespace std;

const int OPERATOR_AMOUNT = 7;
const int FUN_AMOUNT = 10;

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
	
}
class Expression
{
public:
	Expression(string str, int variable_amount = 0, string variable[] = nullptr);
	~Expression();
	//string input(const string str);
	double getAns(double []);//������ⲿ�ӿ�
	
#ifdef DEBUG
	void read(int & pos);//read a "word" each time and judge what tpye the word is
	EXPRESSION::TYPE type;
	string token;//"word"
#endif
protected:

#ifndef DEBUG
	void read(int & pos);//read a "word" each time and judge what tpye the word is
	EXPRESSION::TYPE type;
	string token;//"word"
#endif // !DEBUG


	static const string Operator[OPERATOR_AMOUNT];
	static const int OperatorNeedAmount[OPERATOR_AMOUNT];//��¼�������Ҫ�Ĳ�������
	static const int OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT];//��¼�����֮������ȼ�
	static const string function[FUN_AMOUNT];
	static const int functionNeedAmount[FUN_AMOUNT];//mark the data of function

	string input(const string str);
	double OperatorCalculate(string, double[]);
	double FunctionCalculate(string, double[]);

	static int isFunction(string str);//judge if it is function and return the number of function

	int isVariable(string str);

	static int isOperator(string str);//judge if it is operator and return the number of operator
	map<string, int>VariableMap;
	string *VariableName;
	int VariableAmount;
	string exp;//expression
	bool check_input;//judge if the expression is bad expression
	EXPRESSION::SYSTERM expression_systerm;//���Ȼ��߽Ƕ�
};
class Function_2D 
{
public://������...����...
	Function_2D(string, string);
	~Function_2D();
	double getAns(double);
	double getDerivativeValue(double);//΢�־����ֵ
	double getIntergralValue(double, double);//���־����ֵ
private:
	string VariableName[1];
	string expression;
	Expression *FunctionExpression;
	double eps;
};
