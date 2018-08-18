#pragma once
#include"source.h"

class Matrix
{
public:
	Matrix(unsigned int r, unsigned int c, bool ) ;
	Matrix();
	//Matrix(const Matrix&);//拷贝构造函数

	bool check(const Matrix & )const;

	bool checkMul(const Matrix &)const;

	bool symmetric()const;

	bool antisymmetric()const;

	/*Judge if it's a square*/
	bool square()const { return row == column; };


	/*Operational part*/
	bool operator == (const Matrix&)const;

	bool operator !=(const Matrix&)const;

	Matrix operator = (const Matrix&);

	friend Matrix operator + (const Matrix&, const Matrix&);

	friend Matrix operator - (const Matrix&, const Matrix&);

	/*Matrix multiplication*/
	friend Matrix operator *(const Matrix&, const Matrix&);

	/*Number multiplying*/
	friend Matrix operator *(const Matrix&, const double&);

	/*Number multiplying*/
	friend  Matrix operator *(const int &num, const Matrix &matrix) { return (matrix * num); };


	Matrix power(unsigned int time)const;

	Matrix FastPower(unsigned int time)const;

	friend std::ostream & operator<<(std::ostream &os, const Matrix &m);
	friend std::istream & operator>>(std::istream &is, Matrix &m);//“istream”: 不允许在数据声明中使用“friend”????


	/*Matrix properties*/
	/*get Transposed matrix*/
	Matrix Transposition()const;

	/*get inverse matrix*/
	Matrix inverse_matrix()const;

	/*get det*/
	double determinant()const;//problem

	/*get Rank*/
	unsigned int getRank()const;

	/*Staircase simplest*/
	Matrix getSimplest(Matrix &,unsigned int &,unsigned int &)const;//阶梯最简型 返回交换次数

	/*trace(The sum of the main diagonal lines)*/
	double trace()const;

	/*Adjoint matrix*/
	Matrix Adjoint()const;

	/*LU decomposition*/
	void LUdecomposition(Matrix & ,Matrix &)const;

	Matrix Choleskydecomposition();//把一个对称正定的矩阵表示成一个下三角矩阵L和其转置的乘积的分解

	/*Jacobi iterative method to get characteristic value and feature vector*/
	/*only get Real area value*/
	bool getFeatureVector(Matrix &,Matrix &,int )const;

	bool showFeatureVector_Value(Matrix &,double * )const;//Matrix stores the vactor ,double * stores the value,string stroes the value as well
	double getData(int i, int j) const { return data[i][j]; };

	unsigned int getRow()const { return row; };

	unsigned int getColumn()const { return column; };

	void setData(unsigned int i, unsigned int j, double x) { data[i][j] = x; };

	void setRow(unsigned int r) { row = r; };
	void setColumn(unsigned int c) { column = c; };

	/*test part*/
	void reset();
	void show();
	void debug();
private:
	vector <vector <double>  >data;
	unsigned int row, column;
};