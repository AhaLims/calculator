#include"Matrix.h"
#include"source.h"
Matrix::Matrix(ll r, ll c, bool flag = false) :row(r), column(c)
{
	data.resize(row);
	double element[2] = { 0,0 };
	if (flag == true)
		element[1] = 1;//���쵥λ���� ������all 0 �ľ���
	for (int i = 0; i < row; i++)
	{
		data[i].resize(column);
		for (int j = 0; j < column; j++)
		{
			if (i == j)
				data[i][j] = element[1];
			else
				data[i][j] = element[0];
		}
	}
}