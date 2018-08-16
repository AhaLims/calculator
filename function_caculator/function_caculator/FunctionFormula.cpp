#include"FunctionFormula.h"
using namespace EXPRESSION;
using namespace std;
/*Operator[0] is function(like sin cos and so on)*/
const string Expression::Operator[OPERATOR_AMOUNT] = 
{"", "+" , "-" , "*" , "/" , "(" , ")" , "#" };
const int Expression::OperatorNeedAmount[OPERATOR_AMOUNT] =
{0 ,  2   , 2 ,   2   , 2  ,  0  ,  0  ,  0 };
const int Expression::OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT] =
{ //�ж����ȼ� OperatorMap[��һ������][ǰһ������] ���ӣ�3 + 5 * 7 �� operatormap[*][+] = 1 
// fun(�ȼ���"("   2 * ( 5 + (2 + 2 ) ��operator[(][(] = 1
//operator[(][]
//operator[�������)][(] = 1
//  "f(" "+" "-" "*" "/" "(" ")" "#"
	  1,  1,  1 , 1,  1,  1 , 0 ,0//��������е���...//fun( is similar to 
	  -1,-1, -1 ,-1 -1 , 1 , 0 ,0,// +
	  // -
	// *
	// /
	// %
	1,1,1,1,1,1,1,0,       // (
	-1,-1                 // )
	// #



};//���ȼ�����ô�ж���...

const string Expression::function[FUN_AMOUNT] =
{  "sin("    , "cos("    , "tan(" , 
   "arcsin(" , "arccos(" , "arctan(",
   "ln("     , "lg("     , "sqrt("  , 
   "^" };
const int Expression::functionNeedAmount[FUN_AMOUNT] 
= { 1,1,1,1,1,1,1,1,1,2 };//��¼������Ҫ�Ĳ�������
//                         ��������          ������             ����ȡ��ֵ   ���ʽ
Expression::Expression(string str,int variable_amount,string variable[])
	:VariableAmount(variable_amount),check_input(true),expression_systerm(RADIAN_SYSTERM)
{
	exp = this->input(str);
	if (VariableAmount != 0)
	{
		VariableName = new string[VariableAmount];
		for (int i = 0; i < variable_amount; i++)
		{
			VariableName[i] = variable[i];
			//δ֪���϶�Ӧ�õ�getAns()�ٸ�ֵ��
			//VariableMap[variable[i]] = value[i];���Ұ�...
			//VariableMap[VariableName[i]] = value[i];//δ֪��Ӧ��һ��ʼ�͸�ֵ�����ǵ�getAns()�ٸ�ֵ��
		}
	}
}
Expression::~Expression()
{
	if (VariableAmount != 0)
		delete VariableName;
}
string Expression::input(const string str)
{
	int len = str.length();
	string exp;
	char c;
	for (int i = 0; i < len; i++)
	{
		c = str.at(i);
		if (c == '\n' || c == ' ')//delete space
			continue;
		
		exp += c;
	}
	exp += "#";
	return exp;
}
double Expression::getAns(double Value[])//��...�����Ȼ�ȥдα�����...���Ұ�
{
	int judge_ = 0;//�ж������Ƿ�ɶ�
	stack<string>OperatorStack;
	stack<double>OperandStack;
	int pos = 0;
	read(pos);
	/*ȱ�ٸ�ֵ�Ĺ���*/
	if (type == NUM_TYPE )
	{
		double num;
		//tokenת����
		OperandStack.push(num);
		read(pos);
	}
	else if (type == VARIABLE_TYPE)
	{
		double num = VariableMap[token];
		OperandStack.push(num);
		read(pos);
	}
	else if (type == OPERATOR_TYPE)
	{
		if (OperatorStack.empty())
		{
			OperatorStack.push(token);
		}
		else
		{
			if (compare(token,OperatorStack.top()) == -1)
			{
				//�ȳ�ջ����
				double x[2];
				x[0] = OperandStack.top();
				OperandStack.pop();
				x[1] = OperandStack.top();
				double tmp = OperatorCalculate(OperatorStack.top(), x);
				OperandStack.push(tmp);
			}
			else if (compare(token, OperatorStack.top()) == 0)
			{

			}
			else if (compare(token, OperatorStack.top()) == 1)
			{

			}
		}



		read(pos);
	}
	else if (type == FUNCTION_TYPE)
	{
		if (OperatorStack.empty())
		{
			OperatorStack.push(token);
		}
		else
		{
			if (compare(token, OperatorStack.top()) == -1)
			{

			}
			else if (compare(token, OperatorStack.top()) == 0)
			{

			}
			else if (compare(token, OperatorStack.top()) == 1)
			{

			}
		}


		read(pos);
	}
	else if (type == UNKNOW_TYPE)
	{
		return 0;
	}
	else if (!check_input)
	{
		return 0;
	}
	else if (type == END_TYPE)
	{
		if (OperatorStack.empty())//ջ���� ��õ���
		{
			return OperandStack.top();
		}
		else
		{
			//ջû�п� ����

		}
	}
}

void Expression::read(int & pos)//ע�����һ���ַ����ܻ��������...
{
	token = "";
	cout << "pos = " << pos << endl;
	if (exp[pos] == '#'||pos >= exp.length())
	{
		type = END_TYPE;
		return;
	}
	int next_pos = pos + 1;

	/*judge number*/
	if (pos == 0 && (exp[pos] == '-' || exp[pos] == '+'))//process the first -
	{
		type = NUM_TYPE;
		token = exp[pos];
		while ( isdigit(exp[next_pos]) || exp[next_pos] == '.')
		{
			token += exp[next_pos];
			next_pos++;
			
		}
		pos = next_pos;
		return;
	}
	else if(isdigit(exp.at(pos)))
	{
		type = NUM_TYPE;
		token = exp[pos];
		while (isdigit(exp[next_pos]) || exp[next_pos] == '.')
		{
			token += exp[next_pos];
				next_pos++;
		}
		pos = next_pos;
		return;
	}

	token = exp[pos];
	while (true)
	{
		if (isFunction(token) != -1)
		{
			type = FUNCTION_TYPE;
			pos = next_pos;
			return;
		}
		else if (isOperator(token) != -1)
		{
			type = OPERATOR_TYPE;
			pos = next_pos;
			return;
		}
		else if (isVariable(token) != -1)//�Ǳ���
		{
			type = VARIABLE_TYPE;
			pos = next_pos;
			return;
		}
		else if (exp[next_pos - 1] == '#')
		{
			check_input = false;
			type = UNKNOW_TYPE;//WRONG TYPE
			return;
		}
		else
		{
			token += exp[next_pos];
			next_pos++;
		}

	}
}

int Expression::compare(string str1, string str2)const
{
	int a = isOperator(str1);
	int b = isOperator(str2);
	if (a == -1)
	{
		a = 0;
	}
	if (b == -1)
	{
		b = 0;
	}
	return OperatorMap[a][b];
}

double Expression::OperatorCalculate(string Operator, double Operand[])
{
	int index = isOperator(Operator);
	switch (index)
	{
	case 0:
		return Operand[0] + Operand[1];
	case 1:
		return Operand[0] - Operand[1];
	case 2:
		return Operand[0] * Operand[1];
	case 3:
		if (Operand[1] == 0)
		{
			check_input = false;
			return 0;
		}
		return Operand[0] / Operand[1];
	}
}

double Expression::FunctionCalculate(string Function, double  Operand[])
{
	int index = isFunction(Function);
	switch (index)
	{
	case 0:
		return sin(Operand[0]);
	case 1:
		return cos(Operand[0]);
	case 2:
		//if(Operand[0] == )
		return tan(Operand[0]);
	case 3:
		return asin(Operand[0]);
	case 4:
		return acos(Operand[0]);
	case 5:
		return atan(Operand[0]);
	case 6:
		if (Operand[0] < 0)
		{
			check_input = false;
			return 0;
		}
		return log(Operand[0]);
	case 7:
		if (Operand[0] < 0)
		{
			check_input = false;
			return 0;
		}
		return log10(Operand[0]);
	case 8:
		if (Operand[0] < 0)
		{
			check_input = false;
			return 0;
		}
		return sqrt(Operand[0]);
	case 9:
		pow(Operand[0], Operand[1]);
	}
}

int Expression::isFunction(string str)//judge if it is function and return the number of function
{
	//cout << str << endl;
	for (int i = 0; i < FUN_AMOUNT; i++)
	{
		if (str == function[i])
			return i;
	}
	return -1;
}
int Expression::isVariable(string str)const
{
	if (VariableName == nullptr)return -1;
	for (int i = 0; i < VariableAmount; i++)
	{
		if (str == VariableName[i])
			return i;
	}
	return -1;
}
int Expression::isOperator(string str)//judge if it is operator and return the number of operator
{
	for (int i = 0; i < OPERATOR_AMOUNT;i++)
	{
		if (str == Operator[i])
			return i;
	}
	return -1;
}








Function_2D::Function_2D(string expression_,string VariableName_):eps(0.00001)
{
	VariableName[0] = VariableName_;
	expression = expression_;
	FunctionExpression = new Expression(expression,1, VariableName);//�᲻�������Ⱑ...�о��������Ⱑ...

}







Function_2D::~Function_2D()
{
	delete FunctionExpression;
}


double Function_2D::getAns(double Value_)
{
	double value[1] = { Value_ };
	return FunctionExpression->getAns(value);
}
double Function_2D::getDerivativeValue(double Value_)//΢�־����ֵ
{
	double y1 = getAns(Value_);
	double y2 = getAns(Value_ + eps);
	return (y2 - y1) / eps;
}
double Function_2D::getIntergralValue(double x1, double x2)//���־����ֵ
{
	double ans = 0;
	for (; x1 < x2; x1 += eps)
	{
		ans += eps * getAns(x1);
	}
	return ans;
}