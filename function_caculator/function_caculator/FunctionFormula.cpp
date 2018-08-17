#include"FunctionFormula.h"
using namespace EXPRESSION;
using namespace std;
/*Operator[0] is function(like sin cos and so on)*/
const string Expression::Operator[OPERATOR_AMOUNT] = 
{"", "+" , "-" , "*" , "/" , "(" , ")" , "#" };
const int Expression::OperatorNeedAmount[OPERATOR_AMOUNT] =
{0 ,  2   , 2 ,   2   , 2  ,  0  ,  0  ,  0 };
const int Expression::OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT] =
{ //判断优先级 OperatorMap[后一个符号][前一个符号] 例子：3 + 5 * 7 则 operatormap[*][+] = 1 
// fun(等价于"("   2 * ( 5 + (2 + 2 ) 则operator[(][(] = 1
//operator[(][]
//operator[任意除了)][(] = 1
	//异常情况 2
	//好像暂时不能处理 省略✖的情况
//  "f(" "+" "-" "*" "/" "(" ")" "#"
	 1,   1,  1 , 1,  1,  1 , 0 ,  0 ,//fun( is similar to 
	-1,  -1, -1 ,-1, -1 , 1 , 2 ,  0 ,// '+'
	-1,  -1, -1 ,-1, -1 , 1 , 2 ,  0 , // '-'
	-1,   1,  1 ,-1, -1 , 1 , 2 ,  0 , // *
	-1,   1,  1 , 1,  1 , 1 , 2 ,  0 ,// '/'
	 1,   1,  1 , 1,  1 , 1 , 0 ,  0 ,// '('
	 0,  -1, -1 ,-1, -1 , 0 , 0 ,  0 ,// ')'
	 0,   0,  0 , 0,  0 , 0 , 0 ,  0// '#'



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
double Expression::getAns(double Value[])// Value[] 未知数的值
{
	/*judge the amount of  '('  ')'*/
	int judge_ = 0;//判断括号是否成对
	double ans = 0;
	stack<string>OperatorStack;
	stack<double>OperandStack;
	int pos = 0;
	read(pos);

	/*get value of variables*/
	if (VariableAmount > 0)
	{
		for (int i = 0; i < VariableAmount; i++)
		{
			VariableMap[VariableName[i]] = Value[i];
		}
	}
	while (token != "" && token !="#" && type != END_TYPE)
	{
		if (type == UNKNOW_TYPE)
		{
			check_input = false;
			return 0;
		}//return
		if (type == NUM_TYPE)
		{
			double num = atof(token.c_str());/*string to double*/
			OperandStack.push(num);
			read(pos);
		}
		else if (type == VARIABLE_TYPE)
		{
			double num = VariableMap[token];
			OperandStack.push(num);
			read(pos);
		}
		else if (type == OPERATOR_TYPE  || type == FUNCTION_TYPE)//function equal to "("
		{
			if (!check_input)
			{
				return 0;
			}//return
			if (OperatorStack.empty())
			{
				OperatorStack.push(token);
			}
			//if (type == FUNCTION_TYPE)
			//{
			//	judge_++;
			//}
			else//operator or function
			{
				if (compare(token, OperatorStack.top()) == -1)
				{
					//先出栈计算
					double x[2] = { 0,0 };
					x[0] = OperandStack.top();
					OperandStack.pop();
					double tmp = 0;
					string top_element = OperatorStack.top();
					OperatorStack.pop();

					if (isOperator(top_element) != -1)//it's operator
					{
						if (OperatorNeedAmount[isOperator(top_element)] == 2)
						{
							x[1] = OperandStack.top();
							OperandStack.pop();
						}
#ifdef DEBUG
						cout << x[1] << " " << top_element << x[0] << endl;
#endif // DEBUG
						tmp = OperatorCalculate(top_element, x);
					}

					else// if(isFunction(OperatorStack.top != -1) its's function
					{
						//if (functionNeedAmount[isFunction(top_element)] == 2)
						if(top_element == "^")
						{
							x[1] = OperandStack.top();
							OperandStack.pop();
						}
#ifdef DEBUG
						cout << x[1] << " " << top_element << x[0] << endl;
#endif // DEBUG
						tmp = FunctionCalculate(top_element, x);
					}
					OperandStack.push(tmp);
					if (token != ")")//  not ')'
					{
						OperatorStack.push(token);
					}
					else//is ')'
					{
						judge_--;
					}
				}
				else if (compare(token, OperatorStack.top()) == 0)//unnessary
				{
					OperatorStack.pop();
					judge_--;
				}
				else if (compare(token, OperatorStack.top()) == 1)
				{
					if (token == "(")//is '('
					{
						judge_++;
					}
					OperatorStack.push(token);

				}
				else if (compare(token, OperatorStack.top()) == 2)//wrong input
				{
					check_input = false;
					return 0;
				}
			}
			read(pos);
		}
	}
	//if (type == END_TYPE ||type )
	//{
	//now at the end
	while (!OperatorStack.empty())
	{
		if (OperandStack.empty())
		{
			check_input = false;
			return 0;
		}
		double x[2] = { 0,0 };
		string top_element = OperatorStack.top();
		OperatorStack.pop();
		if (isOperator(top_element) != -1)
		{
			if (top_element == "#")
				return OperandStack.top();
			if(top_element == "(")
				OperandStack.pop();
			x[0] = OperandStack.top();
			OperandStack.pop();
			x[1] = OperandStack.top();
#ifdef DEBUG
			cout << x[1] << " " << top_element << x[0] << endl;
#endif // DEBUG
			OperandStack.pop();
			double tmp = OperatorCalculate(top_element, x);
			OperandStack.push(tmp);
		}
		else
		{
			x[0] = OperandStack.top();
			OperandStack.pop();
			if (top_element == "^")
			{
				x[1] = OperandStack.top();
				OperandStack.pop();
			}
			double tmp = FunctionCalculate(top_element, x);
			OperandStack.push(tmp);
		}

	}
	if (judge_ == 0)
		return OperandStack.top();
	else
	{
		check_input = false;
		return 0;
	}
	//}
}

void Expression::read(int & pos)//注意最后一个字符可能会输出两次...
{
	token = "";
	//cout << "pos = " << pos << endl;
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
#ifdef DEBUG
		cout << token << endl;
#endif // DEBUG
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
#ifdef DEBUG
		cout << token << endl;
#endif // DEBUG
		return;
	}

	token = exp[pos];
	while (true)
	{
		if (isFunction(token) != -1)
		{
			type = FUNCTION_TYPE;
			pos = next_pos;
#ifdef DEBUG
			cout << token << endl;
#endif // DEBUG
			return;
		}
		else if (isOperator(token) != -1)
		{
			type = OPERATOR_TYPE;
			pos = next_pos;
#ifdef DEBUG
			cout << token << endl;
#endif // DEBUG
			return;
		}
		else if (isVariable(token) != -1)//是变量
		{
			type = VARIABLE_TYPE;
			pos = next_pos;
#ifdef DEBUG
			cout << token << endl;
#endif // DEBUG
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
	case 1:
		return Operand[1] + Operand[0];
	case 2:
		return Operand[1] - Operand[0];
	case 3:
		return Operand[1] * Operand[0];
	case 4:
		if (Operand[0] == 0)
		{
			check_input = false;
			return 0;
		}
		return Operand[1] / Operand[0];
	}
}

double Expression::FunctionCalculate(string Function, double  Operand[])
{
	//目前默认是弧度制
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