#include"FunctionFormula.h"
using namespace EXPRESSION;
using namespace std;

/*data initialize*/

/*Operator[0] is function(like sin cos and so on)*/
const string Expression::Operator[OPERATOR_AMOUNT] = 
{"", "+" , "-" , "*" , "/" , "(" , ")" , "#" };
const int Expression::OperatorNeedAmount[OPERATOR_AMOUNT] =
{0 ,  2   , 2 ,   2   , 2  ,  0  ,  0  ,  0 };

//used to judge the pres
const int Expression::OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT] =
{ 
//  {f(,   +, -,   *,  /,  (,  ),  #}
	{ -1, -1, -1, -1, -1, -1,  1,  1 },  //f(
    { -1,  1,  1, -1, -1, -1,  1,  1 },  //+
	{ -1,  1,  1, -1, -1, -1,  1,  1 },  //-
	{ -1,  1,  1,  1,  1, -1,  1,  1 },  //*
	{ -1,  1,  1,  1,  1, -1,  1,  1 },  ///
	{ -1, -1, -1, -1, -1, -1,  0,  1 },  //(
	{  1,  1,  1,  1,  1,  1,  1,  1 },  //)
	{ -1, -1, -1, -1, -1, -1,- 1,  0 },  //#


};

const string Expression::function[FUN_AMOUNT] =
{  "sin("    , "cos("    , "tan(" , 
   "arcsin(" , "arccos(" , "arctan(",
   "ln("     , "lg("     , "sqrt("  , 
   "^" };
const int Expression::functionNeedAmount[FUN_AMOUNT] 
= { 1,1,1,1,1,1,1,1,1,2 };//mark the amount of variable that the fucntion need 


/*function part*/
Expression::Expression(string expression,int variable_amount,string variable[])
	:VariableAmount(variable_amount),check_input(true),expression_systerm(RADIAN_SYSTERM)
{
	exp = this->input(expression);
	if (VariableAmount != 0)
	{
		/*get the name of each variable*/
		VariableName = new string[VariableAmount];
		for (int i = 0; i < variable_amount; i++)
		{
			VariableName[i] = variable[i];
		}
	}
}

Expression::~Expression()
{
	if (VariableAmount != 0)
		delete[] VariableName;
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

int Expression::getAns(double &res, double Value[])//在这里计算每一次的值
								//return -1 -2的含义不同（虽然都是错误的输入）
{
	if (VariableAmount > 0)
	{
		for (int i = 0; i < VariableAmount; i++)
		{
			VariableMap[VariableName[i]] = Value[i];
		}
	}
	res = 0;
	std::stack<std::string> OperatorStack; 
	std::stack<double> OperandStack;

	OperatorStack.push("#");
	int pos = 0;
	read(pos);//read one word at first

	while (type != END_TYPE || !OperatorStack.empty())
	{
		if (type == UNKNOW_TYPE)
		{
			return -1; // wrong input: undifined 
		}

		if (type == NUM_TYPE)
		{
			OperandStack.push(atof(token.c_str()));//string to double
			read(pos);
		}
		if (type == VARIABLE_TYPE)//replace variable
		{
			double val = VariableMap[token];
			OperandStack.push(val);
			read(pos);
		}
		else
		{
			//token is operator or function
			//judge priority
			int comRes = compare(OperatorStack.top(), token);
			switch (comRes)
			{
			case -1://top() is background  ,so push(token)
				OperatorStack.push(token);
				read(pos);
				break;

			case 1://token is background ,so calculate token
			{
				string ptr = OperatorStack.top();
				OperatorStack.pop();

				int idx = isOperator(ptr), argCnt;
				double arg[10], res = 0;
				if (-1 != idx)// -1 means it not a operator
				{
					argCnt = OperatorNeedAmount[idx];//get the amount of number it need 
					if (argCnt)
					{
						//judge if the expression is right and get the value of number
						if (!getValue(OperandStack, arg, argCnt))
						{
							return -2;//wrong input
						}
						res = OperatorCalculate(ptr, arg);
						OperandStack.push(res);
					}
				}
				else//it is function
				{
					idx = isFunction(ptr);
					argCnt = functionNeedAmount[idx];
					if (!getValue(OperandStack, arg, argCnt))
					{
						return -2;//wrong input
					}
					res = FunctionCalculate(ptr, arg);
					OperandStack.push(res);
					read(pos);
				}
				break;
			}

			case 0://unnecessary word like )
				OperatorStack.pop();
				read(pos);
				break;
			}
		}
	}
	res = OperandStack.top();// the top element is the answer
	return 0;
}

/*divide expression into "word"*/
void Expression::read(int & pos)
{
	token = "";
	//cout << "pos = " << pos << endl;
	if (exp[pos] == '#'||pos >= exp.length())
	{
		type = END_TYPE;
		token = "#";
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
//#ifdef DEBUG
//		cout <<"token is"<< token << endl;
//#endif // DEBUG
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
//#ifdef DEBUG
//		cout << "token is "<<token << endl;
//#endif // DEBUG
		return;
	}

	token = exp[pos];
	while (true)
	{
		if (isFunction(token) != -1)
		{
			type = FUNCTION_TYPE;
			pos = next_pos;
//#ifdef DEBUG
//			cout << "token is " << token << endl;
//#endif // DEBUG
			return;
		}
		else if (isOperator(token) != -1)
		{
			type = OPERATOR_TYPE;
			pos = next_pos;
//#ifdef DEBUG
//			cout << "token is " << token << endl;
//#endif // DEBUG
			return;
		}
		else if (isVariable(token) != -1)//是变量
		{
			type = VARIABLE_TYPE;
			pos = next_pos;
//#ifdef DEBUG
//			cout << "token is " << token << endl;
//#endif // DEBUG
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

//get priority
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

bool Expression::getValue(stack<double>& opnd, double x[], int n)
{
	if (opnd.size() < n)
	{
		return false;
	}
	for (int i = n - 1; i >= 0; --i) {
		x[i] = opnd.top();
		opnd.pop();
	}
	return true;
}

double Expression::OperatorCalculate(string Operator, double Operand[])
{
	//{"fc", "+", "-", "*", "/", "(", ")", "#" };
	int index = isOperator(Operator);
	switch (index)
	{
	case 1:
		return Operand[0] + Operand[1];
	case 2:
		return Operand[0] - Operand[1];
	case 3:
		return Operand[0] * Operand[1];
	case 4:
		if (Operand[0] == 0)
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
		if (expression_systerm == RADIAN_SYSTERM)
			return sin(Operand[0]);
		else //ANGLE_SYSTERM
			return sin(Operand[0] / 360 * pi);
	case 1:
		if (expression_systerm == RADIAN_SYSTERM)
			return cos(Operand[0]);
		else //ANGLE_SYSTERM
			return cos(Operand[0] / 360 * pi);
	case 2:
		if (expression_systerm == RADIAN_SYSTERM)
		{
			return tan(Operand[0]);
		}
		else //ANGLE_SYSTERM
		{
			//if(Operand[0] % 360 == 0)
			return tan(Operand[0] / 360 * pi);
		}
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
	FunctionExpression = new Expression(expression,1, VariableName);//会不会有问题啊...感觉会有问题啊...

}


Function_2D::~Function_2D()
{
	delete FunctionExpression;
}


double Function_2D::getAns(double Value_)
{
	double value[1] = { Value_ };
	double ans;

	if(FunctionExpression->getAns(ans,value) == 0)
		return ans;
	else return 0;//bug here 
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