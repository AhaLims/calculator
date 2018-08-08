#include "caculator_gui.h"
#include <QtWidgets/QApplication>
//#define DEBUG
#include <QTextCodec>

#ifndef DEBUG
int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	QApplication a(argc, argv);
	caculator_gui w;
	w.show(); //创建控制台函数
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
					m1.showFeatureVector_Value();
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

void test_fraction()
{
	while (true)
	{
		std::cout << "enter the fraction:\n";
		int d, n;

		std::cin >> n >> d;

		Fraction f(n, d);
		std::cin >> n >> d;
		Fraction ff(n, d);
		ff = 1.145;
		ff.show();

		//std::cout << f.getN() << "/" << f.getD()<<std::endl;
		//std::cout << f.toString()<<std::endl;
	}
	return;
}

int main()
{
	srand((unsigned)time(NULL));
	test();
	system("pause");
	return 0;
}
#endif


