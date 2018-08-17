#include"FunctionFormula.h"
using namespace EXPRESSION;
using namespace std;
delete[];
/*Operator[0] is function(like sin cos and so on)*/
const string Expression::Operator[OPERATOR_AMOUNT] = 
{"", "+" , "-" , "*" , "/" , "(" , ")" , "#" };
const int Expression::OperatorNeedAmount[OPERATOR_AMOUNT] =
{0 ,  2   , 2 ,   2   , 2  ,  0  ,  0  ,  0 };
const int Expression::OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT] =
{ //判断优先级 OperatorMap[后一个符号][前一个符号] 例子：3 + 5 * 7 则 operatormap[*][+] = 1 
// = 0 意味着同级
  // fun(等价于"("   2 * ( 5 + (2 + 2 ) 则operator[(][(] = 1
//operator[(][]
//operator[任意除了)][(] = 1
	//异常情况 2
	//好像暂时不能处理 省略✖的情况
//{f(,  ,  +,  -,  *,  /,  (,  ), #}
	{ -1, -1, -1, -1, -1, -1,  1, 1 },  //f(
{ -1,    1,  1,  -1, -1, -1, 1, 1 },  //+
{ -1,    1,  1,  -1, -1, -1, 1, 1 },  //-
{ -1,    1,  1,  1,  1,  -1, 1, 1 },  //*
{ -1,    1,  1,  1,  1,  -1, 1, 1 },  ///
{ -1,  -1, -1, -1, -1,  -1, 0, 1 },  //(
{ 1,    1,  1,  1,  1,   1, 1, 1 },  //)
{ -1,   -1, -1, -1, -1,  -1,-1, 0 },  //#


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
//int Expression::getAns(double&ans, double Value[] )// Value[] 未知数的值
//{
//	ans = 0;
//	/*judge the amount of  '('  ')'*/
//	int judge_ = 0;//判断括号是否成对
//	stack<string>OperatorStack;
//	stack<double>OperandStack;
//	
//
//
//	/*get value of variables*/
//	if (VariableAmount > 0)
//	{
//		for (int i = 0; i < VariableAmount; i++)
//		{
//			VariableMap[VariableName[i]] = Value[i];
//		}
//	}
//	int pos = 0;
//	read(pos);
//	OperatorStack.push("#");
//
//	while (type != END_TYPE || !OperatorStack.empty())
//	{
//		
//		//if (OperatorStack.empty())cout << "empty of Operator stack\n";
//		//if (type == END_TYPE) cout << "end type\n";
//		//if (!OperatorStack.empty())
//		//	cout << "the top element is "<<OperatorStack.top() << endl;
//		if (type == UNKNOW_TYPE)
//		{
//			check_input = false;
//			return -1;
//		}//return
//		if (type == NUM_TYPE)
//		{
//			double num = atof(token.c_str());/*string to double*/
//			OperandStack.push(num);
//			read(pos);
//		}
//		else if (type == VARIABLE_TYPE)
//		{
//			double num = VariableMap[token];
//			OperandStack.push(num);
//			read(pos);
//		}
//
//		else// if (type == OPERATOR_TYPE || type == FUNCTION_TYPE || type == END_TYPE)//function equal to "("
//		{
//			if (!check_input)
//			{
//				cout << "check_input = 0?\n";
//				return -1;
//			}//return
//
//			//operator or function
//			int order = compare(token, OperatorStack.top());
//			
//			
//			double x[2] = { 0,0 };
//			double tmp = 0;
//			switch (order)
//			{
//			case 1:
//			{
//				string top_element = OperatorStack.top();
//				OperatorStack.pop();
//
//				int index = isOperator(top_element);
//				int NeedAmount = 0;
//				//double res, a[10];
//				double res;
//				if (index != -1)//it's operator
//				{
//					if (OperatorNeedAmount[index] != 0)
//					{
//						NeedAmount = OperatorNeedAmount[index];
//						if (!getValue(OperandStack, x, NeedAmount)) //这里不明白
//						{
//							return -2;//表达式错误 
//						}
//						res = OperatorCalculate(top_element, x);
//						OperandStack.push(res);
//					}
//				}
//				else//function 
//				{
//					int index = isFunction(top_element);
//					int NeedAmount = functionNeedAmount[index];
//					if (!getValue(OperandStack, x, NeedAmount)) //这里不明白
//					{
//						return -2;//表达式错误 
//					}
//					res = FunctionCalculate(top_element, x);
//					OperandStack.push(res);
//					read(pos);
//				}
//				break;
//			}
//			case 0:
//				OperatorStack.pop();
//				read(pos);
//				break;
//			case -1:
//				OperatorStack.push(token);
//				read(pos);
//				break;
//			}
//			read(pos);
//		}
//	}
//	ans = OperandStack.top();
//	return 0;
//	//}
//}

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
	std::stack<std::string> optr;  //算符栈 
	std::stack<double> opnd;       //算数栈 

	optr.push("#");
	int pos = 0;
	read(pos);//分割分割
				//先读入一个字符或数字（或未知数
	while (type != END_TYPE || !optr.empty()) //还没读完 或者操作符栈里面还有元素
	{
		/*#ifdef EXP_DEBUG
		std::cout << "TkT = " << tkType << ", ";
		std::cout << "Pos = " << pos << "/" << length << ", ";
		std::cout << "Token = '" << token << "'" << std::endl;
		#endif*/
		//std::cout << "token is" << token << std::endl;
		if (type == UNKNOW_TYPE)
		{
			return -1; //未知符号 错误的输入
		}

		if (type == NUM_TYPE)
		{
			opnd.push(atof(token.c_str()));//直接转换了！ 不用手写
			read(pos);//再进入循环 读下一个字符
		}
		if (type == VARIABLE_TYPE)
		{
			double val = VariableMap[token];
			opnd.push(val);
			read(pos);
		}
		else
		{
			//token不是数字的情况
			//判断top 与token的优先级关系
			int comRes = compare(optr.top(), token);//token 与栈顶的元素进行优先级判断
														 /*#ifdef EXP_DEBUG
														 std::cout << "compare('" << optr.top() << "', '" << token << "') = " << comRes << std::endl;
														 #endif*/
			switch (comRes)//说明token优先 所以放到栈里面
			{
			case -1://top是落后于token的 那么就把token压栈
				optr.push(token);
				read(pos);
				break;

			case 1://top优先于token 那么就出栈进行计算
			{
				std::string ptr = optr.top();
				optr.pop();

				int idx = isOperator(ptr), argCnt;
				double arg[10], res = 0;
				if (-1 != idx)// -1 说明他不是运算符part的
				{
					argCnt = OperatorNeedAmount[idx];//需要的数字
					if (argCnt)
					{
						if (!getValue(opnd, arg, argCnt)) 
						{
							return -2;//表达式错误 
						}
						res = OperatorCalculate(ptr, arg);
						opnd.push(res);
					}
				}
				else
				{
					idx = isFunction(ptr);//判断是不是函数part的
										   //如果idx = -1的话那不是有问题？？
										   //或者说根本不会等于 -1 前面已经判断过了？
					argCnt = functionNeedAmount[idx];
					if (!getValue(opnd, arg, argCnt))
					{
						return -2;//表达式错误 
					}
					res = FunctionCalculate(ptr, arg);
					opnd.push(res);
					read(pos);
				}
#ifdef EXP_DEBUG
				if (argCnt) {
					std::cout << "('" << ptr << "', ";
					for (int i = 0; i < argCnt; ++i) {
						std::cout << arg[i];
						if (i + 1 < argCnt) {
							std::cout << ", ";
						}
					}
					std::cout << ") = " << res << std::endl;
				}
#endif
				break;
			}

			case 0:
				optr.pop();
				read(pos);
				break;
			}
		}
	}
	res = opnd.top();
	return 0;
}

void Expression::read(int & pos)//注意最后一个字符可能会输出两次...
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
#ifdef DEBUG
		cout <<"token is"<< token << endl;
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
		cout << "token is "<<token << endl;
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
			cout << "token is " << token << endl;
#endif // DEBUG
			return;
		}
		else if (isOperator(token) != -1)
		{
			type = OPERATOR_TYPE;
			pos = next_pos;
#ifdef DEBUG
			cout << "token is " << token << endl;
#endif // DEBUG
			return;
		}
		else if (isVariable(token) != -1)//是变量
		{
			type = VARIABLE_TYPE;
			pos = next_pos;
#ifdef DEBUG
			cout << "token is " << token << endl;
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