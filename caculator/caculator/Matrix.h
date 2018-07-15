#pragma once
#include"source.h"

class Matrix
{
	Matrix(ll r, ll c, bool flag = false) :row(r), column(c) {};
	//Matrix(const Matrix&);//�������캯��

	/*�ж������ǲ������*/
	bool check_equal_row_column(const Matrix &)const;

	/*��һ������������ǲ��ǵ��ڵڶ������������*/
	bool check_can_mul(const Matrix &)const;

	/*Judge if it's a Symmetric matrix*/
	bool if_symmetric()const;

	/*Judge if it's an Antisymmetric matrix*/
	bool if_anti_symmetric()const;

	/*Judge if it's a square*/
	bool if_square()const { return row == column; };


	/*Operational part*/
	bool operator ==(const Matrix&)const;

	bool operator !=(const Matrix&)const;

	Matrix operator =(const Matrix&);//��Ϊ��ָ��....Ҫ��������vector���ˣ�

	friend Matrix operator +(const Matrix&, const Matrix&);

	friend Matrix operator -(const Matrix&, const Matrix&);

	/*Matrix multiplication*/
	friend Matrix operator *(const Matrix&, const Matrix&);

	/*Number multiplying*/
	friend Matrix operator *(const Matrix&, const double&);

	/*Number multiplying*/
	friend  Matrix operator*(const t& num, const Matrix &matrix) { return matrix * num; };


	Matrix power(ll time)const;

	Matrix fast_power(ll time)const;

	friend std::ostream & operator<<(std::ostream &os, const Matrix &m);
	friend std::istream & operator>>(std::istream &is, Matrix &m);//��istream��: ������������������ʹ�á�friend��????


	/*Matrix properties*/
	/*get Transposed matrix*/
	Matrix Transposition()const;

	/*get inverse matrix*/
	Matrix inverse_matrix()const;

	/*get det*/
	double determinant()const;

	/*get Rank*/
	ll get_rank()const;

	/*Staircase simplest*/
	Matrix get_simplest_matrix()const;//���������

	/*trace(The sum of the main diagonal lines)*/
	double trace()const;//����ļ������Խ���֮�ͣ�

	/*Adjoint matrix*/
	Matrix Adjoint()const;

	/*LU decomposition*/
	void LU_decomposition(Matrix & ,Matrix &)const;

	Matrix Cholesky_decomposition();//��һ���Գ������ľ����ʾ��һ�������Ǿ���L����ת�õĳ˻��ķֽ�


	ll get_data(ll i, ll j) const { return data[i][j]; };

	ll get_row()const { return row; };

	ll get_column()const { return column; };

	void set_data(ll i, ll j, double x) { data[i][j] = x; };

	void set_row(ll);
	void set_column(ll);
private:
	vector <vector <double>  >data;
	ll row, column;//���� ����
};