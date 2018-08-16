#pragma once
#include<iostream>
#include<string>
#include<map>//��map��δ֪��
#include <stack>
#include <cctype>
#include <cstdlib>
#include <cmath>
//δ֪����һ���ַ�ֻ������ĸ �Һ���ֻ�ܳ�����ĸ������
using namespace std;

const int OPERATOR_AMOUNT = 8;
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
	static const int OperatorNeedAmount[OPERATOR_AMOUNT];//��¼�������Ҫ�Ĳ�������
	static const int OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT];//��¼�����֮������ȼ�
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
