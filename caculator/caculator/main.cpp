#include"source.h"
#include"Matrix.h"


int main()
{
	Matrix m1(3,3,true);
	Matrix m2(3, 3, false);
	m1.show();
	for(int i = 0;i<3;i++)
		for (int j = 0; j < 3; j++)
		{
			double temp = m1.getData(i,j);
			temp++;
			m1.setData(i, j, temp);
		}
	m1.show();
	m1 = m1 * m1;
	m1.show();
	system("pause");
	return 0;
}