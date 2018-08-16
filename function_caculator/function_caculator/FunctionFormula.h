#pragma once
#include<iostream>
#include<string>
#include<map>//用map存未知数
#include <stack>
#include <cctype>
#include <cstdlib>
#include <cmath>
#define DEBUG
//未知数第一个字符只能是字母 且后面只能出现字母和数字
using namespace std;

const int OPERATOR_AMOUNT = 7;
const int FUN_AMOUNT = 10;

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
	
}
class Expression
{
public:
	Expression(string str, int variable_amount = 0, string variable[] = nullptr);
	~Expression();
	//string input(const string str);
	double getAns(double []);//计算的外部接口
	
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
	static const int OperatorNeedAmount[OPERATOR_AMOUNT];//记录运算符需要的参数个数
	static const int OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT];//记录运算符之间的优先级
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
	EXPRESSION::SYSTERM expression_systerm;//弧度或者角度
};
class Function_2D 
{
public://先想想...想想...
	Function_2D(string, string);
	~Function_2D();
	double getAns(double);
	double getDerivativeValue(double);//微分具体的值
	double getIntergralValue(double, double);//积分具体的值
private:
	string VariableName[1];
	string expression;
	Expression *FunctionExpression;
	double eps;
};
