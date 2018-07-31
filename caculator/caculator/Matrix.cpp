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

/*next time try to use Gauss elimination method*/
//如果不可逆怎么办...
Matrix Matrix::inverse_matrix()const
{
	if (fabs(determinant()) < math::eps)
	{
		Matrix m(1, 1, 0);
		std::cerr << "it doesn't have inverse matrix\n";
		return m;
	}
	Matrix inv_matrix(row,column,true);
	inv_matrix = Adjoint();
	double temp = determinant();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			inv_matrix.setData(i, j, inv_matrix.getData(i, j) / temp);
		}
	}
	//if (determinant() == 0)
	//{
	//	std::cerr << "wrong because det == 0 ,the matrix does not have inverse matrix\n";
	//	return inv_matrix;
	//}
	//Matrix m;
	//m = *this;
	//double MAX = 0;//mark the max element of each column
	//int t = 0;//the column of the MAX element
	//double temp = 0;

	//for (unsigned int i = 0; i < row; i++)
	//{
	//	MAX = m.getData(i, i);
	//	t = i;

	//	/*find the MAX element of each column*/
	//	for (unsigned int j = i + 1; j < column; j++)
	//	{
	//		if (fabs(MAX) < fabs(m.getData(j, i)))
	//		{
	//			MAX = m.getData(j, i);
	//			t = j;
	//		}
	//	}

	//	if (t != i)	//indicate that they need to be swap
	//	{
	//		for (unsigned int j = 0; j < column; j++)
	//		{
	//			temp = m.getData(i, j);
	//			m.setData(i, j, m.getData(t, j));
	//			m.setData(t, j, temp);

	//			temp = inv_matrix.getData(i, j);
	//			inv_matrix.setData(i, j, inv_matrix.getData(t, j));
	//			inv_matrix.setData(t, j, temp);
	//		}
	//	}

	//	/*eliminate part */

	//	for (unsigned int j = i + 1; j < row; j++)
	//	{
	//		if (m.getData(j, i) == 0)//当前行的这一列不需要减掉了
	//			continue;
	//		else
	//		{
	//			temp = m.getData(j, i) / m.getData(i, i);
	//			for (int k = 0; k < column; k++)
	//			{
	//				m.setData(j, k, m.getData(j, k) - m.getData(i, k) * temp);
	//				inv_matrix.setData(j, k, inv_matrix.getData(j, k) - inv_matrix.getData(i, k) * temp);
	//			}
	//		}
	//	}
	//}	

	///*recall to make matrix m Unitized*/
	//for (unsigned int i = row - 1; i >= 0; i--)
	//{
	//	if (inv_matrix.getData(i, i) != 1)
	//	{
	//		temp = inv_matrix.getData(i, i);
	//	}
	//}
	return inv_matrix;

}

/*only square*/
double Matrix::determinant()const
{
	if (!square())
	{
		std::cerr << "wrong because it's not square and does not have det.\n";
		return 0;
	}
	Matrix simpliest_matrix(row, column);
	unsigned int time = 0, rank = 0;
	getSimplest(simpliest_matrix, time, rank);
	double ans = 1;
	if (rank < row) return 0;
	for (int i = 0; i < row; i++)
	{
		ans *= simpliest_matrix.getData(i, i);
	}
	if (time % 2  == 0)return ans;
	else return -ans;
}

/*only square */
unsigned int Matrix::getRank()const
{
	unsigned int time = 0, rank = 0;
	Matrix sim(row, column);
	getSimplest(sim, time, rank);
	if (rank > std::min(row, column))
		rank = std::min(row, column);
	return rank;
}
/*only square */
/*Gauss elimination method to get the simplest matrix*/
Matrix Matrix::getSimplest(Matrix &m,unsigned int & time,unsigned int &rank)const
{
	m = *this;
	time = 0;
	double MAX = 0;//mark the max element of each column
	int t = 0;//the column of the MAX element
	rank = std::min(row, column);//problem!!!!!
	if (row <= column)
	{
		for (unsigned int i = 0; i < row; i++)
		{
			MAX = m.getData(i, i);
			t = i;
			/*find the MAX element of each column*/
			for(unsigned int j = i + 1;j < column;j++)
			{
				if (fabs(MAX) < fabs(m.getData(j,i)) )
				{
					//std::cout << MAX << " " << m.getData(j, i) << std::endl;
					MAX = m.getData(j,i);
					t = j;
				}
			}
			if (fabs(MAX) < math::eps)//0
				rank--;
			else
			{
				if (t != i)			//indicate that they need to be swap
				{
					//std::cout << "swap" << t << "to" << i << std::endl;
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
				for (unsigned int j = i + 1; j < row; j++)
				{
					if (m.getData(j,i) == 0)//当前行的这一列不需要减掉了
						continue;
					else
					{
						temp = m.getData(j, i) / m.getData(i, i);
						for (int k = 0; k < column; k++)
						{
							m.setData(j, k, m.getData(j, k) - m.getData(i, k) * temp );
						}
						//m.show();
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

Matrix Matrix::Adjoint()const
{
	if (row <= 1 || column <= 1 ||!square())return *this;//wrong
	Matrix m(row - 1, column - 1, false);
	Matrix residualSubtype(row, column, false);
	for (unsigned int i = 0; i < row; i++)
	{
		for (unsigned int j = 0; j < column; j++)
		{
			for (unsigned int k = 0,true_k = 0; k < row; k++,true_k++)
			{
				//true_k,true_k means the real position of m
				if (k == i)
				{
					true_k--;
					continue;
				}
				for (unsigned int g = 0 ,true_g = 0; g < column; g++,true_g++)
				{
					if (g == j)
					{
						true_g--;
						continue;
					}
					m.setData(true_k, true_g, getData(k, g));
				}
			}
			if( (i+j) % 2 == 0)
				residualSubtype.setData(i, j, m.determinant());
			else
				residualSubtype.setData(i, j, -m.determinant());
		}	
	}
	return residualSubtype.Transposition();
}


/*maybe have problem*/
/*refer to https://blog.csdn.net/zhouxuguang236/article/details/40212143 */
Matrix Matrix::getFeatureVector(Matrix &characteristicValueMatrix)const
{
	Matrix FeatureVetor(row, column, true);//特征向量
	Matrix m(row, column, false);
	Matrix U(row, column, true);
	m = *this;
	double MAX = getData(0, 1);
	double Angle,sinAngle, cosAngle;
	unsigned MAXRow = 0, MAXColumn = 1;
	unsigned int time = 0,maxTime = 100;//迭代次数
	while (true)//主循环 迭代
	{
		for (unsigned int i = 0; i < row; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				if (i == j)continue;//it can't be diagonal element
				if (fabs(MAX) < fabs(m.getData(i, j)))
				{
					MAX = m.getData(i, j);
					MAXRow = i;
					MAXColumn = j;
				}
			}//find the max element of matrix
		}
		if (fabs(MAX) < math::eps) break;
		//if (time >= maxTime) break;
		//time++;//暂时不控制迭代次数

		/*get the rotation angle */
		Angle = 0.5 *atan2(-2 * m.getData(MAXRow, MAXColumn), m.getData(MAXColumn, MAXColumn) - m.getData(MAXRow, MAXRow));
		sinAngle = sin(Angle);
		cosAngle = cos(Angle);

		/*set the element of rotation matrix*/
		U.setData(MAXRow, MAXRow, cosAngle);
		U.setData(MAXRow, MAXColumn, -sinAngle);
		U.setData(MAXColumn, MAXColumn, cosAngle);
		U.setData(MAXColumn, MAXRow, sinAngle);

		/*updata the feature vector*/
		FeatureVetor = FeatureVetor * U;

		/*
		get new matrix m
		only p,q row and p,q column element change
		*/
		double tmp = m.getData(MAXRow, MAXRow) * cosAngle * cosAngle + m.getData(MAXColumn, MAXColumn) * sinAngle * sinAngle;
		tmp += 2 * m.getData(MAXRow, MAXRow) * m.getData(MAXColumn, MAXColumn) *cosAngle *sinAngle;
		m.setData(MAXRow, MAXRow, tmp);

		tmp = m.getData(MAXRow, MAXRow) * sinAngle * sinAngle + m.getData(MAXColumn, MAXColumn) * cosAngle * cosAngle;
		tmp -= 2 * m.getData(MAXRow, MAXRow) * m.getData(MAXColumn, MAXColumn) *cosAngle *sinAngle;
		m.setData(MAXColumn, MAXColumn, tmp);

		for (unsigned int i = 0; i < column; i++)
		{
			if (i == MAXRow || i == MAXColumn)continue;
			tmp = cosAngle * m.getData(MAXRow, i) + sinAngle * m.getData(MAXColumn, i);
			m.setData(MAXRow, i, tmp);
			tmp = -sinAngle * m.getData(MAXRow, i) + cosAngle * m.getData(MAXColumn, i);
			m.setData(MAXColumn, i, tmp);
		}
		for (unsigned int j = 0; j < row; j++)
		{
			if (j == MAXRow || j == MAXColumn)continue;
			tmp = cosAngle * m.getData(j, MAXRow) + sinAngle * m.getData(j, MAXColumn);
			m.setData(j, MAXRow, tmp);
			tmp = -sinAngle * m.getData(j, MAXRow) + cosAngle * m.getData(j, MAXColumn);
			m.setData(j, MAXColumn, tmp);
		}
		
	}
	characteristicValueMatrix = m;//对角线上的元素就是特征值
	return FeatureVetor;//特征向量
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


void Matrix::debug()
{
	std::fstream file;
	//file.open("file.txt");
	for (unsigned int i = 0; i < row; i++)
	{
		for (unsigned int j = 0; j < column; j++)
			//file >> data[i][j];
			std::cin >> data[i][j];
	}
	return;
}