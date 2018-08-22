#pragma once
#include"source.h"
class Expression;
class scientic_calculator
{
public:
	scientic_calculator();
	~scientic_calculator();
	bool getAns(double &,string str);
	void setC(double);
	double getC();
	void change_digits(unsigned int );
	unsigned int get_digits() { return digits; };
private:
	Expression * exp;
	string variable[4];
	double value[4];
	unsigned int digits;
};
