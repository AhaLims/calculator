#include"source.h"
#include"Matrix.h"


int main()
{
	Matrix m1(2,2,true);
	Matrix m2(2, 2, false);
	m1.reset();
	m1.show();
	std::cout << "transposition matrix:\n";
	m2 = m1.Transposition();
	m2.show();
	system("pause");
	return 0;
}