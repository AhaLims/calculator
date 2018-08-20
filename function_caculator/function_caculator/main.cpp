#include"FunctionFormula.h"
using namespace EXPRESSION;
//还需要增加角度 弧度制
//增加常量e的赋值
//最后一个字符可能...会被读两遍....


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
	//x^3画不出？？
	cout << test.getAns(2);
	system("pause");
	return 0;
}