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
	Fraction(double);
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
	//Fraction operator - ();
	Fraction& operator = (const Fraction&);
	Fraction& operator = (double );

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

	
	friend Fraction operator + (const double &, const Fraction);
	friend Fraction operator - (const double &, const Fraction);
	friend Fraction operator * (const double &, const Fraction);
	friend Fraction operator / (const double &, const Fraction);
	
	/*debug part*/
	void show();
	int getD()const;
	int getN()const;
	void setD(int );
	void setN(int );
	void FractionReduce();//get the simplest formF
private:
	int numerator; 
	int denominator; 

	/*Automatic reduce*/
	int maxFactor(int, int)const;
	int minCom(int nr, int dr)const;  
	


};
