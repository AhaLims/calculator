#include"source.h"
#include"fraction.h"

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}
Fraction::Fraction(int a, int b)
{
	reset(a, b);
}
Fraction::Fraction(double num)
{
	reset(num);
}
Fraction::Fraction(string str)
{
	reset(str);
}

void Fraction::reset(int a,int b = 1)
{
	if (b < 0)a = 0 - a;
	numerator = a;
	denominator = b;
	FractionReduce();
}

void Fraction::reset(double num)
{
	denominator = 1;
	while (true)
	{
		double tmp = floor(num);
		if (fabs(tmp - num) < math::eps)
			break;
		denominator *= 10;
		num *= 10;
	}
	numerator = num;
	FractionReduce();
}

void Fraction::reset(string str)
{
	unsigned int len = str.length();
	unsigned int tmp = 0;
	for (int i = 0; i < len; i++)
	{
		if ((str.at(i) < '0' || str.at(i) > '9') && str.at(i) != '/')
		{
			std::cout << str.at(i) << std::endl;
			std::cerr << "wrong while translate string to fraction\n";
		}

		if (str.at(i) == '/')
		{
			numerator = tmp;
			tmp = 0;
			for (unsigned int j = i + 1; j < len; j++)
			{
				tmp *= 10;
				tmp += str.at(j) -'0';
			}
			if (tmp == 0) std::cerr << "wrong because denominator != 0" << std::endl;
			denominator = tmp;
			break;
		}
		tmp *= 10;
		tmp += str.at(i) - '0';	
	}
	
	FractionReduce();
}


void Fraction::show()
{
	std::cout << numerator << "/" << denominator << std::endl;
}

/*最大公因数*/
int Fraction::maxFactor(int a,int b)const
{
	int c = a % b;
	while (c != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

/*最小公倍数*/
int Fraction::minCom(int nr, int dr)const
{
	int factor = nr;
	factor /= maxFactor(nr, dr);
	factor *= dr;
	return factor;
}

void Fraction::FractionReduce()
{
	int temp = maxFactor(numerator,denominator);
	numerator /= temp;
	denominator /= temp;
	return;
}