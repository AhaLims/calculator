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
		//�ֱ��ǵ�ǰ���ֵ���ţ����ڵķ��ţ����׽ڵ����ţ����ڻ��ݣ�
		//����������飬������ǵ�һ������ʱ��һ����ֵ
		//f =  -1�����Ǹ��ڵ�
	{
		index = i;//�������Ҫ���������ֵ����
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

class Point24;//ȫ����

