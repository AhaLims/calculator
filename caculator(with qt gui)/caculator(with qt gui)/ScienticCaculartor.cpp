#include"QT_OpenGL.h"
#include"source.h"
class scientic_calculator
{
public:
	scientic_calculator(string str);
	~scientic_calculator();
	bool getAns(double &) ;
private:
	Expression * exp;
	string variable[4];
	double value[4];
};

scientic_calculator::scientic_calculator(string str) :variable{ "e","pi","PI","C" },value{ 2.7182818284 ,3.141592654 ,3.141592654 ,0}
{
	int variable_amount = 4;
	exp = new Expression(str, variable_amount, variable);
}

scientic_calculator::~scientic_calculator()
{
	delete exp;
}
bool scientic_calculator::getAns(double & ans)
{
	if (exp->getAns(ans, value)) return false;
	else return true;
}