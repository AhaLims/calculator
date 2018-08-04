#include"Matrix.h"
#include"source.h"
#include"AnalyticFormula.h"

/*make sure the str only has num (has the problem of accuracy)*/
//应该包括小数或者是分数的处理吧（好像目前只有小数的处理呢...
double AnalyticFormula::getNum(string str)
{
	double num = 0;
	unsigned int len = str.length();
	for (unsigned int i = 0; i < len; i++)
	{
		if ((str.at(i) < '0' || str.at(i) > '9') && str.at(i) != '.')
		{
			std::cout << str.at(i) << std::endl;
			std::cerr << "wrong while translate string to num\n";
		}
		if (str.at(i) == '.')
		{
			double divisor = 10;
			double tmp = 0;
			for (unsigned int j = i + 1; j < len; j++)
			{
				tmp = str.at(j) - '0';
				num += (tmp / divisor);
				divisor *= 10;
			}
			break;
		}
		num *= 10;
		num += str.at(i) - '0';
	}
	return num;
}
void AnalyticFormula::Computational_formula(string expression)
{
	stack<string> operation, operand;

}







//void AnalyticFormula::function_formula(string expression,string variable)

