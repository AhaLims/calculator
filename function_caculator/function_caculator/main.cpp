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