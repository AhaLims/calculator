#include"Matrix.h"
#include"source.h"

Matrix::Matrix(unsigned int r, unsigned int c, bool flag = false) :row(r), column(c)
{
	data.resize(row);
	double element[2] = { 0,0 };
	if (flag == true)
		element[1] = 1;//构造单位矩阵 否则构造all 0 的矩阵
	for (unsigned int i = 0; i < row; i++)
	{
		data[i].resize(column);
		for (unsigned int j = 0; j < column; j++)
		{
			if (i == j)
				data[i][j] = element[1];
			else
				data[i][j] = element[0];
		}
	}
}
Matrix::Matrix()
{
	row = column = 2;
	data.resize(row);
	double element[2] = { 0,1 };
	for (unsigned int i = 0; i < row; i++)
	{
		data[i].resize(column);
		for (unsigned int j = 0; j < column; j++)
		{
			if (i == j)
				data[i][j] = element[1];
			else
				data[i][j] = element[0];
		}
	}
}

bool Matrix::check(const Matrix & m)const
{
	if (row == m.getRow() && column == m.getColumn())
		return true;
	else return false;
}

bool Matrix::checkMul(const Matrix &m)const
{
	if (column == m.getRow())
		return true;
	else return false;
}

bool Matrix::symmetric()const
{
	if (!square())return false;
	for (unsigned int i = 0; i < row; i++)
	{
		for (unsigned int j = i + 1; j < column; j++)
			if (data[i][j] != data[j][i])
				return false;
	}
	return true;
}

bool Matrix::antisymmetric()const
{
	if (!square())return false;
	for (unsigned int i = 0; i < row; i++)
	{
		if (data[i][i] != 0)return false;
		for (unsigned int j = i + 1; j < column; j++)
			if (data[i][j] != -data[j][i])
				return false;
	}
	return true;
}
bool Matrix::operator==(const Matrix & m)const
{
	if (!check(m))return  false;
	for (unsigned int i = 0; i < row; i++)
		for (unsigned int j = 0; j < column; j++)
			if (data[i][j] != m.getData(i, j))
				return false;
	return true;
}
bool Matrix::operator!=(const Matrix & m)const
{
	if (*this == m)return false;
	else return true;
}
Matrix Matrix::operator =(const Matrix &m)
{
	data.resize(m.getRow());
	row = m.getRow();
	column = m.getColumn();
	for (unsigned int i = 0; i < row; i++)
	{
		data[i].resize(m.getColumn());
		for (unsigned int j = 0; j < column; j++)
			data[i][j] = m.getData(i, j);
	}
		return *this;
}
Matrix operator +(const Matrix & m1, const Matrix &m2)
{
	Matrix temp(m1.getRow(), m2.getColumn());//unit
	double x = 0;
	if (m1.getRow() != m2.getRow() || m1.getColumn() != m2.getColumn())
	{
		std::cerr << "Wrong\nCan't add or sub.\n";
		return temp;
	}
	for(unsigned int i = 0;i<m1.getRow();i++)
		for (unsigned int j = 0; j < m1.getColumn(); j++)
		{
			x = m1.getData(i, j) + m2.getData(i, j);
			temp.setData(i, j, x);
		}
	return temp;
}

Matrix operator -(const Matrix & m1, const Matrix &m2)
{
	Matrix temp(m1.getRow(), m2.getColumn());//unit
	double x = 0;
	if (m1.getRow() != m2.getRow() || m1.getColumn() != m2.getColumn())
	{
		std::cerr << "Wrong\nCan't add or sub.\n";
		return temp;
	}
	for (unsigned int i = 0; i<m1.getRow(); i++)
		for (unsigned int j = 0; j < m1.getColumn(); j++)
		{
			x = m1.getData(i, j) - m2.getData(i, j);
			temp.setData(i, j, x);
		}
	return temp;
}
Matrix operator *(const Matrix & m1, const Matrix &m2)
{
	Matrix temp(m1.getRow(), m2.getColumn(),false);// all 0 matrix
	if (!m1.checkMul(m2))
	{
		std::cerr << "wrong .";
		return temp;
	}
	double x = 0;
	for (unsigned int i = 0; i < m1.getRow(); i++)
	{
		for (unsigned int j = 0; j < m2.getColumn(); j++)
		{
			for (unsigned int k = 0; k < m1.getColumn(); k++)
				x += m1.getData(i, k)*m2.getData(k, j);
			temp.setData(i, j, x);
			x = 0;
		}
	}
	return temp;
}

Matrix operator *(const Matrix &m, const double & num)
{
	Matrix temp(m.getRow(), m.getColumn());
	for (unsigned int i = 0; i < m.getRow(); i++)
		for (unsigned int j = 0; j < m.getColumn(); j++)
			temp.setData(i, j, m.getData(i, j)*num);
	return temp;
}
Matrix Matrix::power(unsigned int time)const
{
	Matrix temp(getRow(), getColumn(), true);
	for (int i = 0; i < time; i++)
	{
		temp = temp * *this;
	}
	return temp;
}

Matrix Matrix::FastPower(unsigned int time)const
{
	Matrix ans(getRow(), getColumn(), true);
	Matrix temp(getRow(), getColumn(), false);
	temp = *this;
	while (time)
	{
		if (time & 1 != 0)
			ans = ans * temp;
		temp = temp * temp;
		time = time >> 1;
	}
	return ans;
}


/*properties part*/
Matrix Matrix::Transposition()const
{
	Matrix m(column, row);
	for (unsigned int i = 0; i < row; i++)
	{
		for (unsigned int j = 0; j < column; j++)
			m.setData(j, i, data[i][j]);
	}
	return m;
}
double Matrix::determinant()const
{
	Matrix simplest_matrix(row, column);
	unsigned int time = 0, rank = 0;
	getSimplest(simplest_matrix, time, rank);
	double ans = 1;
	if (rank < row) return 0;
	for (int i = 0; i < row; i++)
	{
		ans *= simplest_matrix.getData(i, i);
	}
	if (time & 1 == 0)return ans;
	else return -ans;
}
/*trouble*/
/*Gauss elimination method to get the simplest matrix*/
Matrix Matrix::getSimplest(Matrix &m,unsigned int & time,unsigned int &rank)const
{
	m = *this;
	time = 0;
	double MAX = 0;//mark the max element of each column
	int t = 0;//the column of the MAX element
	rank = std::min(row,column);//problem!!!!!
	for (int i = 0; i < row; i++)
	{
		MAX = data[i][i];

		/*find the MAX element of each column*/
		for (unsigned int j = 0; j < column; j++)
		{
			if (fabs(MAX) < fabs(data[i][j]))
			{
				MAX = data[i][j];
				t = j;
			}
		}
		if (fabs(MAX) < math::eps)//0
			rank--;
		else
		{
			if (t != i)			//indicate that they need to be swap
			{
				time++;
				double tmp;
				for (unsigned int j = 0; j < column; j++)
				{
					tmp = m.getData(i, j);
					m.setData(i, j, m.getData(t, j));
					m.setData(t, j, tmp);
				}
			}

			/*eliminate part */

			double temp = 0;
			for (unsigned int j = i + 1; j < row ;j++)
			{
				if (data[j][i] == 0 )//当前行的这一列不需要减掉了
					continue;
				else
				{
					temp = data[j][i] / data[i][i];
					for (int k = 0; k < column; k++)
					{
						m.setData(j, k, data[i][k] * temp - data[j][t]);
					}
				}
			}

		}
		
	}
	return m;
}

double Matrix::trace()const
{
	double temp = 0;
	for (unsigned int i = 0; i < row; i++)
	{
		temp += getData(i,i);
	}
	return temp;
}














void Matrix::reset()
{
	std::cout << "enter row and column:\n";
	std::cin >> row >> column;
	data.resize(row);
	std::cout << "enter the data:\n";
	for (unsigned int i = 0; i < row; i++)
	{
		data[i].resize(column);
		for (unsigned int j = 0; j < column; j++)
		{
			std::cin >> data[i][j];
		}
	}
}


void Matrix::show()
{
	for (unsigned int i = 0; i < row; i++)
	{
		for (unsigned int j = 0; j < column; j++)
			std::cout << data[i][j] << " ";
		std::cout << std::endl;
	}
}