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
	
	Fraction operator+(const Fraction& rv) const;
	Fraction operator-(const Fraction& rv) const;
	Fraction operator*(const Fraction& rv) const;
	Fraction operator/(const Fraction& rv) const;
	Fraction operator-();
	Fraction& operator=(const Fraction& rv);
	bool operator>(const Fraction& rv) const;
	bool operator>=(const Fraction& rv) const;
	bool operator<(const Fraction& rv) const;
	bool operator<=(const Fraction& rv) const;
	bool operator==(const Fraction& rv) const;
	bool operator!=(const Fraction& rv) const;

	
	/*debug part*/
	void show();
private:
	int numerator; 
	int denominator; 

	/*Automatic reduce*/
	int maxFactor(int, int)const;
	int minCom(int nr, int dr)const;  
	void FractionReduce();


};
