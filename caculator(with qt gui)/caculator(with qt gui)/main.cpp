#include "caculator_gui.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include"main_window.h"
#define DEBUG

#ifndef DEBUG
int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	QApplication a(argc, argv);
	main_window surface(argc, argv);
	surface.show();
	return a.exec();
}
//目前测试只输入整数吧...非整数太麻烦了
#endif // DEBUG



#ifdef DEBUG
#include"source.h"
#include"Matrix.h"
#include"fraction.h"
void test()
{
	Matrix m1(2, 2, true);
	Matrix m2(2, 2, false);
	Matrix m3(2, 2, false);
	char order;
	while (true)
	{
		m1.reset();
		std::cout << "enter 1 or 2( 1 means get the propotion ,while 2 means get the operation \n";
		std::cin >> order;
		unsigned int do_nothing[2];
		if (order == '1')
		{
			while (true)
			{
				std::cout << "what you want to get:\n";
				std::cout << "0.break\n";
				std::cout << "1. if symmetric\n";
				std::cout << "2. if anti_sym\n";
				std::cout << "3. get power\n";
				std::cout << "4.get transpsition matrix\n";
				std::cout << "5.get inverse_matrix\n";
				std::cout << "6.get det\n";
				std::cout << "7.get rank\n";
				std::cout << "8.get simpliest matrix\n";
				std::cout << "9 get trace\n";
				std::cout << "a. get adjoint\n";
				std::cout << "b. get Feature value\n";
				std::cin >> order;
				if (order == '0')break;
				else if (order == '1')std::cout << m1.symmetric() << std::endl;
				else if (order == '2') std::cout << m1.antisymmetric() << std::endl;
				else if (order == '4')
				{
					m1 = m1.Transposition();
					m1.show();
				}
				else if (order == '5')
				{
					m3 = m1.inverse_matrix();
					m3.show();
				}
				else if (order == '6')std::cout << m1.determinant() << std::endl;
				else if (order == '7')std::cout << m1.getRank() << std::endl;
				else if (order == '8')
				{
					m3 = m1.getSimplest(m3, do_nothing[0], do_nothing[1]);
					m3.show();
				}
				else if (order == '9')
				{
					std::cout << m1.trace() << std::endl;
				}
				else if (order == 'a')
				{
					m3 = m1.Adjoint();
					m3.show();
				}
				else if (order == 'b')
				{
					Matrix vector;
					double * value;
					m1.showFeatureVector_Value(vector,value);
					vector.show();
					for (int i = 0; i < vector.getRow(); i++)
					{
						std::cout << value[i] << std::endl;
					}
				}
				else if (order == 0)break;
				else continue;
			}
		}
		else if (order == '2')
		{
			m2.reset();
		}
	}
}

void test_simpliest()
{
	Matrix m(3, 3, false);
	m.debug();
	unsigned int do_nothing[2];
	Matrix m1;
	m.getSimplest(m1, do_nothing[0], do_nothing[1]);
	m1.show();
}

using std::cin;
using std::cout;
using std::endl;
#include<iostream>
#include"LinearEqaution.h"
void linear()
{
	Matrix A(3, 3, 0);
	Matrix b(3, 1, 0);
	Matrix ans;
	double tmp;
	int solve;
	while (true)
	{
		cout << "3 * 3 matrix A * x = b\n";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j <= 3; j++)
			{
				cin >> tmp;
				if (j != 3) A.setData(i, j, tmp);
				else b.setData(i, 0, tmp);

			}
		}
		ans = solveLinearEqaution::getSolution(A, b,solve);
		ans.show();
	}
}
int main()
{
	srand((unsigned)time(NULL));
	//test();
	linear();
	system("pause");
	return 0;
}
#endif


