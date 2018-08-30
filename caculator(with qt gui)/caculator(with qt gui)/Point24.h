#pragma once
#include<string>
#include<stack>
#include<vector>
using std::vector;
using std::stack;
using std::string;

class Operator
{
public:
	Operator() {};
	Operator(int i, int n, int f,int v[],double formal_val = 0)
		//分别是当前数字的序号，现在的符号，父亲节点的序号（用于回溯）
		//，传入的数组，如果不是第一个数字时上一个的值
		//f =  -1代表是父节点
	{
		index = i;//传入的需要操作的数字的序号
		NowOperator = n;
		FatherIndex = f;
		if (index == 0)formal_val = v[index];
		switch (NowOperator)
		{
		case 0:
			value = formal_val + v[index + 1];
			break;
		case 1:
			value = formal_val - v[index + 1];
			break;
		case 2:
			value = formal_val * v[index + 1];
			break;
		case 3:
			value = formal_val / v[index + 1];
			break;
		}
	};
	int OperatorIndex;
	int index;
	int NowOperator;
	int FatherIndex;//to get answer
	double value;
};
class Point24
{
public:
	Point24(int *);
	void getAns(string &);
	vector<string> getAnsString() { return AnsString; };
	void show(int a);
private:
	int AnsAmount;
	int value[4];
	static const int Amount;
	static const int OperatorAmount;
	static const double eps;
	static const double TargetValue;
	stack<Operator>OprStack;
	vector<string>AnsString;
	double caculate(const Operator & ) const;
	Operator s[100];//use to get all the final answer
	void RecallAns(Operator,string&);
	char getOperator(int);
};

class Point24;//全排列

