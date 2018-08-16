#pragma once
#include<iostream>
#include<string>
#include<map>//用map存未知数
#include <stack>
#include <cctype>
#include <cstdlib>
#include <cmath>
//未知数第一个字符只能是字母 且后面只能出现字母和数字
using namespace std;

const int OPERATOR_AMOUNT = 8;
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
}
class Expression
{
public:
	Expression(string str,int variable_amount = 0, string variable[]  = nullptr, int value[] = nullptr);
	~Expression();
	//string input(const string str);
	double getAns();
	void read(int & pos);//read a "word" each time and judge what tpye the word is
	EXPRESSION::TYPE type;
	string token;//"word"
private:
	string input(const string str);
	static const string Operator[OPERATOR_AMOUNT];
	static const int OperatorNeedAmount[OPERATOR_AMOUNT];//记录运算符需要的参数个数
	static const int OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT];//记录运算符之间的优先级
	static const string function[FUN_AMOUNT];
	static const int functionNeedAmount[FUN_AMOUNT];//mark the data of function
	
	int isFunction(string str);//judge if it is function and return the number of function
	int isVariable(string str);
	int isOperator(string str);//judge if it is operator and return the number of operator
	//EXPRESSION::TYPE type;
	map<string, int>VariableMap;
	string *VariableName;
	int VariableAmount;
	string exp;//expression
	//string token;//"word"
	

};
