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
	*this = num;
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

double Fraction::toDouble()
{
	double tmp = double(numerator) / double(denominator);
	return tmp;
}

string Fraction::toString()//to be continue
{
	string tmp;


	return tmp;
}

Fraction Fraction::operator + (const Fraction & f)const
{
	Fraction tmp;
	tmp = *this;
	if (tmp.getD() == f.getD())
		tmp.setN(tmp.getN() + f.getN());
	else
	{
		int deno = tmp.getD() *f.getD();
		int nume = tmp.getN() * f.getD() + f.getN() * tmp.getD();
		tmp.reset(nume, deno);
	}
	tmp.FractionReduce();
	return tmp;
}

Fraction Fraction::operator - (const Fraction & f)const
{
	Fraction tmp;
	tmp = *this;
	Fraction F;
	F = f;
	F.setN(-F.getN());
	return *this + F;
}

Fraction Fraction::operator * (const Fraction & f)const
{
	Fraction tmp;
	tmp.reset(this->getN() * f.getN(), this->getD() *f.getD());
	tmp.FractionReduce();
	return tmp;
}

Fraction Fraction::operator / (const Fraction & f)const
{
	Fraction tmp;
	tmp.reset(this -> getN() * f.getD(),this ->getD() * f.getN());
	tmp.FractionReduce();
	return tmp;
}

Fraction& Fraction::operator = (const Fraction & f)
{
	this->denominator = f.getD();
	this->numerator = f.getN();
	return *this;
}

Fraction& Fraction::operator = ( double num)
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
	return *this;
}

void Fraction::show()
{
	std::cout << numerator << "/" << denominator << std::endl;
}

int Fraction::getD()const
{
	return denominator;
}
int Fraction::getN()const
{
	return numerator;
}
void Fraction::setD(int d)
{
	denominator = d;
}
void Fraction::setN(int n)
{
	numerator = n;
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