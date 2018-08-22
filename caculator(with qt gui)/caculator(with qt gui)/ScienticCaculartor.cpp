#include"QT_OpenGL.h"
#include"source.h"
#include"ScienticCaculartor.h"

scientic_calculator::scientic_calculator() :digits(2),variable{ "e","pi","PI","C" },value{ 2.7182818284 ,3.141592654 ,3.141592654 ,0}
{
	exp = nullptr;
	//exp = new Expression(str, variable_amount, variable);
}

scientic_calculator::~scientic_calculator()
{
	if(exp != nullptr)
	delete exp;
}
bool scientic_calculator::getAns(double & ans,string str)
{
	if (exp != nullptr) delete exp;
	exp = new Expression(str, 4, variable);
	if (exp->getAns(ans, value)) return false;
	else return true;
}
void scientic_calculator::setC(double t)
{
	value[3] = t;
	return;
}

double scientic_calculator::getC()
{
	return value[3];
}
void  scientic_calculator::change_digits(unsigned int d)
{
	digits = d;
}