#include"source.h"
#include"fraction.h"

Fraction::Fraction():use_decimal(false)
{
	numerator = 0;
	denominator = 1;
}
Fraction::Fraction(int a, int b):use_decimal(false)
{
	reset(a, b);
}
Fraction::Fraction(double num,bool use_d): use_decimal(use_d)
{
	reset(num);
}
Fraction::Fraction(string str): use_decimal(false)
{
	reset(str);
}

void Fraction::reset(int a,int b = 1)
{
	if (b < 0)
	{
		a = 0 - a;
		b = -b;
	}
	numerator = a;
	denominator = b;
	if(!use_decimal)
		FractionReduce();
	return;
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
	if(!use_decimal)
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
	tmp = std::to_string(this->getN());
	tmp += "/";
	tmp += std::to_string(this->getD());
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
		int deno = tmp.getD() * f.getD();
		int nume = tmp.getN() * f.getD() + f.getN() * tmp.getD();
		tmp.reset(nume, deno);
	}
	if (!tmp.use_decimal)
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
	if(!tmp.use_decimal)
		tmp.FractionReduce();
	return tmp;
}

Fraction Fraction::operator / (const Fraction & f)const
{
	Fraction tmp;
	tmp.reset(this -> getN() * f.getD(),this ->getD() * f.getN());
	if (!tmp.use_decimal)
		tmp.FractionReduce();
	return tmp;
}

Fraction Fraction::operator +=(const Fraction& f)
{
	*this = *this + f;
	return *this;
}
Fraction Fraction::operator -=(const Fraction& f)
{
	*this = *this - f;
	return *this;
}
Fraction Fraction::operator *=(const Fraction& f)
{
	*this = *this * f;
	return *this;
}
Fraction Fraction::operator /=(const Fraction& f)
{
	*this = *this / f;
	return *this;
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
	if (!use_decimal)
	{
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
	else numerator = num;
	return *this;
}
bool Fraction::operator > (const Fraction& f) const
{
	if (this->getD() == f.getD())
	{
		return this->getN() > f.getN();
	}
	else
	{
		int gcd = minCom(this->getD(), f.getD());
		int n1 = this->getN() * gcd / this->getD();
		int n2 = f.getN() * gcd / f.getD();
		return n1 > n2;
	}
}

bool Fraction::operator >= (const Fraction&f) const
{
	if (*this == f || *this > f)
		return true;
	else return false;
}

bool Fraction::operator < (const Fraction&f) const
{
	if (*this >= f) return false;
	else return true;
}

bool Fraction::operator <= (const Fraction&f) const
{
	if (*this > f)return false;
	else return true;
}

bool Fraction::operator == (const Fraction&f) const
{
	if (this->getD() == f.getD() && this->getN() == f.getD())
		return true;
	else if (this->getN() * f.getD() == this->getD() * f.getN())
		return true;
	return false;
}

bool Fraction::operator != (const Fraction&f) const
{
	return !(*this == f);
}

Fraction Fraction::operator +(const double &D)const
{
	Fraction f(D);
	return *this + f;
}

Fraction Fraction::operator -(const double &D)const
{
	Fraction f(D,false);
	return *this - f;
}

Fraction Fraction::operator *(const double &D)const
{
	Fraction f(D);
	return *this * f;
}

Fraction Fraction::operator /(const double &D)const
{
	Fraction f(D);
	return *this / f;
}


Fraction operator + (const double & D, const Fraction&  f)
{
	Fraction f1(D);
	return f1 + f;
}

Fraction operator - (const double & D, const Fraction&  f)
{
	Fraction f1(D);
	return f1 - f;
}

Fraction operator * (const double & D, const Fraction&  f)
{
	Fraction f1(D);
	return f1 * f;
}

Fraction operator / (const double & D, const Fraction&  f)
{
	Fraction f1(D);
	return f1 / f;
}


void Fraction::show()
{
	if (numerator == 0)
		std::cout << 0 << std::endl;
	else if (denominator == 1)std::cout << numerator << std::endl;
	else
		std::cout << numerator << "/" << denominator << std::endl;
}

int Fraction::getD()const
{
	return denominator;
}
double Fraction::getN()const
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
void Fraction::setN(double n)
{
	numerator = n;
}
/*最大公因数*/
int Fraction::maxFactor(int a,int b)const
{
	if (a > b)//change a b 
	{
		int c = a;
		a = b;
		b = c;
	}
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
	if (temp == 0)
	{
		numerator = 0;
		denominator = 1;
		return;
	}
	numerator /= temp;
	denominator /= temp;
	if (denominator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
	return;
}