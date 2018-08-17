#include"FunctionFormula.h"
using namespace EXPRESSION;
//还需要增加角度 弧度制
//增加常量e的赋值
//最后一个字符可能...会被读两遍....
//减法与除法的顺序问题....
int main()
{
	string str;
	while (true)
	{
		cin >> str;
		int pos = 0;
		int len = str.length();
		Expression expression(str);
		/*while (expression.type != END_TYPE)
		{
			expression.read(pos);
			if (expression.type == UNKNOW_TYPE)
			{
				cout << "wrong input\n";
				break;
			}
			cout << expression.token << endl;
		}*/
		double ans = expression.getAns();
		cout << ans << endl;

	}
	system("pause");
	return 0;
}