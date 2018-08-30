#include"Point24.h"
#include<iostream>
const int Point24::Amount = 4;
const int Point24::OperatorAmount = 4;
const double Point24::eps = 0.00001;
const double Point24::TargetValue = 24;
Point24::Point24(int * v):AnsAmount(0)
{
	for (int i = 0; i < Amount; i++)
	{
		value[i] = v[i];
	}
}

void Point24::show(int a )
{
	for (int i = 0; i < a; i++)
	{
		std::cout << i<<" now value is " << s[i].value << ",and now index is " << s[i].index << std::endl;
		std::cout << "his father is " << s[i].FatherIndex << std::endl;
	}
}

void Point24::getAns(string & answer_string)//get all answer and store in vector<string>AnsString
{
	int amount = 0;
	for (int i = 0; i < OperatorAmount; i++,amount++)
	{
		s[amount] = Operator(0, i, -1, value);//传进去的时候就计算了
		s[amount].OperatorIndex = amount;
		OprStack.push(s[amount]);
	}

	Operator now;
	//double tmp;
	while (!OprStack.empty())
	{
		//show(amount);
		//std::cout << "1" << std::endl;
		now = OprStack.top();
		OprStack.pop();
		if (now.index == 2)
		{
			//std::cout << "now.index == 2" << std::endl;
			//if (fabs(fabs(now.value) - TargetValue) < eps)
			if (now.value == TargetValue)
			{
				//std::cout << "now value == TargetValue" << std::endl;
				RecallAns(now,answer_string);
				//找到了一个答案
				//string RecallAns()
			}
		}
		else
		{
			//std::cout << "3" << std::endl;
			for (int i = 0; i < OperatorAmount; i++)
			{
				s[amount] = Operator(now.index + 1, i, now.OperatorIndex, value,now.value);
				s[amount].OperatorIndex = amount;
				OprStack.push(s[amount]);
				amount++;
			}
		}
	}
}

double Point24::caculate( const Operator & o)const
{
	switch (o.NowOperator)
	{
	case 0:
		return o.value + value[o.index];
	case 1:
		return o.value - value[o.index];
	case 2:
		return o.value * value[o.index];
	case 3:
		return o.value / value[o.index];
	}
}
void Point24::RecallAns(Operator o,string & answer_string)
{
	AnsAmount++;
	//std::cout << "now recall answer\n";
	string ans;
	stack<Operator> AnsStack;
	AnsStack.push(o);
	while (o.FatherIndex != -1)
	{
		//std::cout << "father index = "<<o.FatherIndex << std::endl;
		o = s[o.FatherIndex];
		AnsStack.push(o);
	}
	while (!AnsStack.empty())
	{
		o = AnsStack.top();
		AnsStack.pop();
		//std::cout << "o.index = " << o.index << std::endl;
		if (o.index == 0)
		{
			ans = "(((" + std::to_string(value[0]);
			ans += getOperator(o.NowOperator) + std::to_string(value[1]) + ")";
		}
		else
		{
			ans += getOperator(o.NowOperator) + std::to_string(value[o.index + 1]) + ")";
		}
	}
	answer_string += ans + '\n';
	//std::cout << "ans is "<<ans << std::endl;
}

char Point24::getOperator(int i)
{
	switch (i)
	{
	case 0:
		return '+';
	case 1:
		return '-';
	case 2:
		return '*';
	case 3:
		return '/';
	};
}