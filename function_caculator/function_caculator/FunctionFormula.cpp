#include"FunctionFormula.h"
using namespace EXPRESSION;
using namespace std;
const string Expression::Operator[OPERATOR_AMOUNT] = 
{ "+" , "-" , "*" , "/" , "(" , ")" , "#" };
const int Expression::OperatorNeedAmount[OPERATOR_AMOUNT] =
{  2   , 2 ,   2   , 2  ,  0  ,  0  ,  0 };
const int Expression::OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT] =
{ 
	// +
	// -
	// *
	// /
	// %
	// (
	// )
	// #



};//优先级是怎么判定的...

const string Expression::function[FUN_AMOUNT] =
{  "sin("    , "cos("    , "tan(" , 
   "arcsin(" , "arccos(" , "arctan(",
   "ln("     , "lg("     , "sqrt("  , 
   "^" };
const int Expression::functionNeedAmount[FUN_AMOUNT] 
= { 1,1,1,1,1,1,1,1,1,2 };//记录函数需要的参数个数
//                         变量个数          变量名             变量取的值   表达式
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
			//未知数肯定应该到getAns()再赋值啦
			//VariableMap[variable[i]] = value[i];好乱啊...
			//VariableMap[VariableName[i]] = value[i];//未知数应该一开始就赋值？还是到getAns()再赋值？
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
double Expression::getAns(double Value[])
{
	stack<string>OperatorStack;
	stack<double>OperandStack;
	int pos = 0;
	read(pos);
	/*缺少赋值的过程*/
	if (type == NUM_TYPE )
	{
		double num;
		//token转数字
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




		read(pos);
	}
	else if (type == FUNCTION_TYPE)
	{



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

	}
}

void Expression::read(int & pos)//注意最后一个字符可能会输出两次...
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
		else if (isVariable(token) != -1)//是变量
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
int Expression::isVariable(string str)
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
	FunctionExpression = new Expression(expression,1, VariableName);//会不会有问题啊...感觉会有问题啊...

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
double Function_2D::getDerivativeValue(double Value_)//微分具体的值
{
	double y1 = getAns(Value_);
	double y2 = getAns(Value_ + eps);
	return (y2 - y1) / eps;
}
double Function_2D::getIntergralValue(double x1, double x2)//积分具体的值
{
	double ans = 0;
	for (; x1 < x2; x1 += eps)
	{
		ans += eps * getAns(x1);
	}
	return ans;
}