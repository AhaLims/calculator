#pragma once
#include"source.h"
#include"Matrix.h"
#include"fraction.h"

/*incuding analytic formula*/
namespace AnalyticFormula
{
	Matrix Matrix_formula(string );
	double getNum(string);
	void Computational_formula(string);
	void function_formula(string, string);
	//Fraction getFraction(string); 也许不必要？
}

class express
{
private:
	string expression;
public:
	express(string);
	double getAns();

};