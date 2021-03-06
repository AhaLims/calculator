#pragma once
#include"source.h"
class Poly
{
public:
	Poly(string ,string);
	Poly(int, double *, string);
	Poly get_derivative();
	double get_derivative_value(double);
	Poly get_integral();
	double get_intergral_value(double, double);
	string output();
	double get_ans(double);
	void set_MaxTime(int);
	int get_MaxTime();
	void set_coeff(int, double);
	double get_coeff(int);
	bool solve(double*&, int&);//指针的传引用
private:
	int MaxTime;
	vector<double>coefficient;
	double get_one_ans(int );
	int get_ans_amount();
	string variable;
	double newton(double);
};