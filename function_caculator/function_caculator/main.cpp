#include"FunctionFormula.h"
using namespace EXPRESSION;
//����Ҫ���ӽǶ� ������
//���ӳ���e�ĸ�ֵ
//���һ���ַ�����...�ᱻ������....


int main()
{
	//string str;
	//while (true)
	//{
	//	cin >> str;
	//	int pos = 0;
	//	int len = str.length();
	//	string variable[] = { "x" };
	//	double valua[] = { 1 };
	//	Expression expression(str,1, variable);
	//	double ans;
	//	expression.getAns(ans, valua);
	//	cout << "the ans is " << ans << endl;
	//}

	Function_2D test("x", "x^x-4");
	//x^3����������
	cout << test.getAns(2);
	system("pause");
	return 0;
}