#include"FunctionFormula.h"
using namespace EXPRESSION;
//����Ҫ���ӽǶ� ������
//���ӳ���e�ĸ�ֵ
//���һ���ַ�����...�ᱻ������....
//�����������˳������....
int main()
{
	string str;
	while (true)
	{
		cin >> str;
		int pos = 0;
		int len = str.length();
		string variable[] = { "x" };
		double valua[] = { 1 };
		Expression expression(str,1, variable);
		double ans;
		expression.getAns(ans, valua);
		cout << "the ans is " << ans << endl;
	}
	system("pause");
	return 0;
}