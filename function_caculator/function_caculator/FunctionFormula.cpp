#include"FunctionFormula.h"
using namespace EXPRESSION;
using namespace std;
const string Expression::Operator[OPERATOR_AMOUNT] = 
{ "+" , "-" , "*" , "/" , "%"  , "(" , ")" , "#" };
const int Expression::OperatorNeedAmount[OPERATOR_AMOUNT] =
{  2   , 2 ,   2   , 2  ,  2   ,  0  ,  0  ,  0 };
const int Expression::OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT] =
{ };

const string Expression::function[FUN_AMOUNT] =
{  "sin("    , "cos("    , "tan(" , 
   "arcsin(" , "arccos(" , "arctan(",
   "ln("     , "lg("     , "sqrt("  , 
   "^" };
const int Expression::functionNeedAmount[FUN_AMOUNT] 
= { 1,1,1,1,1,1,1,1,1,2 };//记录函数需要的参数个数
//                         变量个数          变量名             变量取的值   表达式
//Expression::Expression(string str,int variable_amount = 0, string variable[]  =nullptr, int value[] = nullptr)
//	:VariableAmount(variable_amount)
Expression::Expression(string str,int variable_amount,string variable[],int value[])
	:VariableAmount(variable_amount)
{
	exp = this->input(str);
	if (VariableAmount != 0)
	{
		VariableName = new string[VariableAmount];
		for (int i = 0; i < variable_amount; i++)
		{
			VariableName[i] = variable[i];
			VariableMap[variable[i]] = value[i];
			VariableMap[VariableName[i]] = value[i];//未知数应该一开始就赋值？还是到getAns()再赋值？
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
double Expression::getAns()
{
	return 0.0;
}

void Expression::read(int & pos)
{
	if (exp[pos] == '#'||pos >= exp.length())
	{
		type = END_TYPE;
		return;
	}
	int next_pos = pos + 1;
	//char c = exp[pos];
	//char next_c = exp[next_pos];

	/*judge number*/
	if (pos == 0 && (exp[pos] == '-' || exp[pos] == '+'))//process the first -
	{
		type = NUM_TYPE;
		while ( isdigit(exp[next_pos]) || exp[next_pos] == '.')
		{
			next_pos++;
		}
		token = exp.substr(pos, next_pos - pos);
		pos = next_pos;
		return;
	}
	else if(isdigit(exp.at(pos)))
	{
		type = NUM_TYPE;
		while (isdigit(exp[next_pos]) || exp[next_pos] == '.')
		{
			//if(next_pos <exp.length() && isdigit(exp[next_pos + 1]))
				next_pos++;
		}
		token = exp.substr(pos, next_pos - pos);
		cout << pos << " " << next_pos << endl;
		pos = next_pos;
		return;
	}

	token = exp.substr(pos, next_pos);
	while (true)
	{
		if (isFunction(token) != -1)
		{
			type = FUNCTION_TYPE;
			//token = exp.substr(pos, next_pos);
			pos = next_pos;
			return;
		}
		else if (isOperator(token) != -1)
		{
			type = OPERATOR_TYPE;
			//token = exp.substr(pos, next_pos);
			pos = next_pos;
			return;
		}
		else if (isVariable(token))//是变量
		{
			token = exp.substr(pos, next_pos);
			type = VARIABLE_TYPE;
			pos = next_pos;
			return;
		}
		else if (exp[next_pos] == '#')
		{
			type = UNKNOW_TYPE;//WRONG TYPE
			return;
		}
		else if (!isdigit(exp[next_pos]) && !isalpha(exp[next_pos])  )
		{
			type = UNKNOW_TYPE;
			//pos = next_pos;
			return;
		}
		else
		{
			next_pos++;
			token += exp[next_pos];
		}

	}
}

int Expression::isFunction(string str)//judge if it is function and return the number of function
{
	for (int i = 0; i < FUN_AMOUNT; i++)
	{
		if (str == function[i])
			return i;
	}
	return -1;
}
int Expression::isVariable(string str)
{
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