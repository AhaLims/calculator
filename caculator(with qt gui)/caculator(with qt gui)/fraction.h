#pragma once
#include"source.h"
#include<string>
using std::string;
/*The symbol is stored on the molecule*/
class Fraction
{
public:
	Fraction();
	Fraction(int ,int);
	Fraction(double,bool use_d = false);
	Fraction(string);

	void reset(int, int);
	void reset(double);
	void reset(string);
	double toDouble();
	string toString();
	
	Fraction operator + (const Fraction&) const;
	Fraction operator - (const Fraction&) const;
	Fraction operator * (const Fraction&) const;
	Fraction operator / (const Fraction&) const;

	Fraction operator +=(const Fraction&);
	Fraction operator -=(const Fraction&);
	Fraction operator *=(const Fraction&);
	Fraction operator /=(const Fraction&);

	Fraction& operator = (const Fraction&);
	Fraction& operator = (double );

	/////////need to test
	bool operator > (const Fraction& ) const;
	bool operator >= (const Fraction& ) const;
	bool operator < (const Fraction& ) const;
	bool operator <= (const Fraction& ) const;
	bool operator == (const Fraction& ) const;
	bool operator != (const Fraction& ) const;

	Fraction operator + (const double &)const;
	Fraction operator - (const double &)const;
	Fraction operator * (const double &)const;
	Fraction operator / (const double &)const;

	
	friend Fraction operator + (const double &, const Fraction&);
	friend Fraction operator - (const double &, const Fraction&);
	friend Fraction operator * (const double &, const Fraction&);
	friend Fraction operator / (const double &, const Fraction&);
	
	/*debug part*/
	void show();
	int getD()const;
	double getN()const;
	void setD(int );
	void setN(int );
	void setN(double);
	void FractionReduce();//get the simplest formF
	bool use_decimal;
private:
	double numerator; 
	int denominator;

	/*Automatic reduce*/
	int maxFactor(int, int)const;
	int minCom(int nr, int dr)const;  
	


};
