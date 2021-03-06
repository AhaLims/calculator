#include <gl\glut.h>    
#include <gl\GLU.h>
#include <gl\GL.h>
#include <QtWidgets/QMessageBox>
#include"QT_OpenGL.h"
#include<qpainter.h>
#include"source.h"

const double QTOpenGL::NormalFactor  = 0.25;
const int QTOpenGL::Width = 800;
const int QTOpenGL::Height = 800;
double QTOpenGL::times = 1;
const GLfloat QTOpenGL::PI = 3.1415926536f;
const int QTOpenGL::centre_x = Width / 2; //中心点
const int QTOpenGL::centre_y = Height / 2;
double QTOpenGL::LevelMovement = 0;
double QTOpenGL::ViticalMovement = 0;
double QTOpenGL::factor = 0.25;
Function_2D *function = nullptr;
double INF = 10e9;


QTOpenGL::QTOpenGL(int Argc, char* Argv[])://, string VariableName_, string expression_) :
	argc(Argc), argv(Argv)//, FunctionExpression(VariableName_,expression_)
{
	LevelMovement = 0;
	ViticalMovement = 0;
	factor = NormalFactor;
}
void QTOpenGL::draw_axis()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	/*开启虚线模式*/
	glLineStipple(2, 0x5555);
	glEnable(GL_LINE_STIPPLE);

	/*水平线*/
	//float pointx1[] = { (-centre_x * times) * factor , (0 + ViticalMovement) * factor};
	//float pointx2[] = { centre_x * times * factor, (0 + ViticalMovement) * factor };
	float pointx1[] = { (-centre_x * times)  , (0 + ViticalMovement)};
	float pointx2[] = { centre_x * times, (0 + ViticalMovement)  };

	/*垂直线*/
	//float pointy1[] = { 0 + LevelMovement * factor, centre_y * times* factor };
	//float pointy2[] = { 0 + LevelMovement * factor, -centre_y * times* factor };
	float pointy1[] = { 0 + LevelMovement , centre_y * times };
	float pointy2[] = { 0 + LevelMovement , -centre_y * times};

	/*画坐标轴 */
	glBegin(GL_LINES);
	glVertex2fv(pointx1);
	glVertex2fv(pointx2);

	glVertex2fv(pointy1);
	glVertex2fv(pointy2);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}
void QTOpenGL::draw_function()
{
	/*设置曲线的颜色*/
	glColor3f(0.0f, 1.0f, 0.0f);
	float x;
	float deltax = 0.005f; // 横坐标间隔

						   //也许可以用多线程 算 + 画？
	/* 不闭合折线*/

	glBegin(GL_LINE_STRIP);
	/*打点 连线*/
	double y;

	for (x = -1.0f; x <= 1.0f; x += deltax)
	{	
		if (!getY((x / factor - LevelMovement / Width * 2 / factor), function, y))
		{
			glEnd();
			return;
		}
		if (fabs(y) >= INF)
		{
			glEnd();
		    glBegin(GL_LINE_STRIP);

			continue;
		}
		glVertex2f(x * centre_x * times, (y * centre_y * times) * factor + +ViticalMovement);
		//(getY((x / factor - LevelMovement / Width * 2 / factor), function) * centre_y * times) * factor + +ViticalMovement);
	}
	glEnd();
}
void myDisplay_(void)//回调函数
{
	QTOpenGL::draw_axis();
	QTOpenGL::draw_function();
	glFlush();
}
void QTOpenGL::start_OpenGL()
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	/*设置窗口的宽高*/
	glutInitWindowSize(Width, Height);

	glutCreateWindow("函数图像");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	gluOrtho2D(0.0, Width, 0.0, Height);

	/*设置坐标原点*/
	glTranslatef(centre_x, centre_y, 0);

	glClear(GL_COLOR_BUFFER_BIT);

	glutKeyboardFunc(&KeyBoards);

	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}
bool QTOpenGL::getY(float x,Function_2D* function,double & y)
{
	if (function->getAns(x,y))return true;
	else return false;
	//return function->getAns(x);
}
void QTOpenGL::move_left()
{
	LevelMovement += Width * 0.1;
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}
void QTOpenGL::move_right()
{
	LevelMovement -= Width * 0.1;
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}
void QTOpenGL::move_up()
{
	ViticalMovement -= Height * 0.1;
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}
void QTOpenGL::move_down()
{
	ViticalMovement += Height * 0.1;
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}

void QTOpenGL::enlarge()
{
	factor *= (1 + 0.2);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}

void QTOpenGL::lessen()
{
	factor /= (1 + 0.2);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}
void QTOpenGL::reset()
{
	factor = NormalFactor;
	ViticalMovement = 0;
	LevelMovement = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}

void QT_OpenGL::paintEvent(QPaintEvent *e)
{
	QPixmap pixmap = QPixmap(":/caculator_gui/picture/background.jpg").scaled(this->size());
	QPalette palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);
}


QT_OpenGL::QT_OpenGL( QTOpenGL * ptr , QWidget *parent )
	: QWidget(parent),qtopengl_ptr(ptr)//这里是需要浅复制
{
	setMinimumSize(1060, 900);
	setMaximumSize(1060, 900);
	ui.setupUi(this);
}

QT_OpenGL::~QT_OpenGL()
{
	if (function != nullptr) delete function;
}

void QT_OpenGL::push_help()
{
	QMessageBox::about(NULL,"help",tr("enter your function and get graphic\nUse 'A' 'S' 'D' 'W' to move\nUse 'J' / 'K' to enlarge / lessen\nUse 'R' to reset."));
}
void QT_OpenGL::push_example()
{
	ui.variabl_name->setText("x");
	ui.function_edit->setText("sin(x)");
}
void QT_OpenGL::push_OK()
{
	//if (function != nullptr) delete function;
	string str1, str2;
	str1 = ui.variabl_name->text().toStdString();
	str2 = ui.function_edit->text().toStdString();
	if (function != nullptr) function->reset(str1, str2);
	else function = new Function_2D(str1,str2);
	double test;
	if (!function->getAns(0,test))//just to see if the expression is right
	{
		QMessageBox::about(NULL, "wrong", tr("wrong input"));
		return;
	}
	qtopengl_ptr->start_OpenGL();
}
void QT_OpenGL::push_left()
{
	qtopengl_ptr->move_left();
}
void QT_OpenGL::push_right()
{
	qtopengl_ptr->move_right();
}
void QT_OpenGL::push_up()
{
	qtopengl_ptr->move_up();
}
void QT_OpenGL::push_down()
{
	qtopengl_ptr->move_down();
}
void QT_OpenGL::push_enlarge()
{
	qtopengl_ptr->enlarge();
}
void QT_OpenGL::push_lessen()
{ 
	qtopengl_ptr->lessen(); 
}
void QT_OpenGL::push_reset()
{
	qtopengl_ptr->reset();
}

void KeyBoards(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':
	case 'D':
		QTOpenGL::LevelMovement -= QTOpenGL::Width * 0.1;
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(&myDisplay_);
		glutMainLoop();
		break;
	case 'a':
	case 'A':
		QTOpenGL::LevelMovement += QTOpenGL::Width * 0.1;
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(&myDisplay_);
		glutMainLoop();
		break;
	case 's':
	case 'S':
		QTOpenGL::ViticalMovement += QTOpenGL::Height * 0.1;
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(&myDisplay_);
		glutMainLoop();
		break;
	case 'w':
	case 'W':
		QTOpenGL::ViticalMovement -= QTOpenGL::Height * 0.1;
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(&myDisplay_);
		glutMainLoop();
		break;
	case 'r':
	case 'R':
		QTOpenGL::factor = QTOpenGL::NormalFactor;
		QTOpenGL::ViticalMovement = 0;
		QTOpenGL::LevelMovement = 0;
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(&myDisplay_);
		glutMainLoop();
		break;
	case 'J':
	case'j':
		QTOpenGL::factor *= (1 + 0.2);
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(&myDisplay_);
		glutMainLoop();
		break;
	case'k':
	case'K':
		QTOpenGL::factor /= (1 + 0.2);
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(&myDisplay_);
		glutMainLoop();
		break;
	}
}


/*data initialize*/

/*Operator[0] is function(like sin cos and so on)*/
const string Expression::Operator[OPERATOR_AMOUNT] =
{ "", "+" , "-" , "^"  , "*" , "/" , "(" , ")" , "#" };
const int Expression::OperatorNeedAmount[OPERATOR_AMOUNT] =
{ 0 ,  2   , 2 ,   2   ,  2  , 2  ,  0  ,  0  ,  0 };

//used to judge the pres
const int Expression::OperatorMap[OPERATOR_AMOUNT][OPERATOR_AMOUNT] =
{
   //{f(,  +,  -, "^"  *,  /,  (,  ),  #}
	{ -1, -1, -1, -1, -1, -1, -1,  1,  1 },  //f(
	{ -1,  1,  1, -1, -1, -1, -1,  1,  1 },  //+
	{ -1,  1,  1, -1, -1, -1, -1,  1,  1 },  //-
	{ -1,  1,  1,  1,  1,  1, -1,  1,  1 },//"^"
	{ -1,  1,  1,  1,  1,  1, -1,  1,  1 },  //*
	{ -1,  1,  1,  1,  1,  1, -1,  1,  1 },  ///
	{ -1, -1, -1, -1, -1, -1, -1,  0,  1 },  //(
	{ 1,  1,  1,  1,  1,  1,  1,  1,  1 },  //)
	{ -1, -1, -1, -1, -1, -1, -1,-1,  0 },  //#


};

const string Expression::function[FUN_AMOUNT] =
{ "sin("    , "cos("    , "tan(" ,
"arcsin(" , "arccos(" , "arctan(",
"ln("     , "lg("     , "sqrt("  ,
};
const int Expression::functionNeedAmount[FUN_AMOUNT]
= { 1,1,1,1,1,1,1,1,1 };//mark the amount of variable that the fucntion need 


						  /*function part*/
Expression::Expression(string expression, int variable_amount, string variable[])
	:VariableAmount(variable_amount), check_input(true),
	expression_systerm(EXPRESSION::RADIAN_SYSTERM),brackets_amount(0)
{
	
	if (VariableAmount != 0)
	{
		/*get the name of each variable*/
		VariableName = new string[VariableAmount];
		for (int i = 0; i < variable_amount; i++)
		{
			VariableName[i] = variable[i];
		}
	}
	exp = this->input(expression);//////////////
}

Expression::~Expression()
{
	if (VariableAmount != 0)
		delete[] VariableName;
}

string Expression::input(const string str)
{
	brackets_amount = 0;
	int len = str.length();
	string exp;
	char c;
	for (int i = 0; i < len; i++)
	{
		c = str.at(i);
		if (c == '\n' || c == ' ')//delete space and '\n'
			continue;
		//used to coplete the ignore * but is not well
		//int index = isVariable(str, i);
		//if (index != -1)//is variable
		//{
		//	std::cout << exp << "\n";
		//	if (i > 0 && str[i - 1] >= '0' && str[i - 1] <= '9')
		//	{
		//		exp += "*";
		//		std::cout << exp << "\n";
		//	}
		//	exp += VariableName[index];
		//	i += VariableName[index].length() - 1;
		//	if (i < len - 1 && !isOperator(str.at(i + 1)))
		//	{
		//		exp += '*';
		//		std::cout << exp<<"\n";
		//	}
		//	continue;
		//}
		//else if (preposition(c))
		//{
			if (c == '(')//to juedge whether the brackets is mate
			{
				brackets_amount++;
			}
		//	if (i == 0 || !isdigit(str.at(i - 1))|| str.at(i - 1) == ')')//now we don't need to add '*'
		//	{
		//		exp += c;
		//		continue;
		//	}
		//	else if(i != 0 && !isOperator(str.at(i-1)))
		//	{
		//		c = '*';
		//		exp += c;
		//		c = str.at(i);
		//	}
		//}
		//else if(postposition(c))
		//{
			if (c == ')')brackets_amount--;
		//	if(i != len - 1 && !isOperator(str.at(i + 1)) && str.at(i + 1) !=')' )
		//	{
		//		exp += c;
		//		c = '*';
		//	}
		//}
		exp += c;
	}
	while (brackets_amount > 0)//complete brackets auto
	{
		exp += ')';
		brackets_amount--;
	}
	exp += "#";
	std::cout << exp << std::endl;
	return exp;
}

/*	caculate value here each time
*	different meaning of -1 -2(thought they are both wrong input)*/
int Expression::getAns(double &res, double Value[])
{
	if (brackets_amount != 0)return -1;
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

	while (type != EXPRESSION::END_TYPE || !OperatorStack.empty())
	{
		if (type == EXPRESSION::UNKNOW_TYPE)
		{
			return -1; // wrong input: undifined 
		}

		if (type == EXPRESSION::NUM_TYPE)
		{
			OperandStack.push(atof(token.c_str()));//string to double
			read(pos);
		}
		if (type == EXPRESSION::VARIABLE_TYPE)//replace variable
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
	OperandStack.pop();
	if (!OperandStack.empty())return -2;
	else return 0;
}

/*divide expression into "word"*/
void Expression::read(int & pos)
{
	token = "";
	//cout << "pos = " << pos << endl;
	if (exp[pos] == '#' || pos >= exp.length())
	{
		type = EXPRESSION::END_TYPE;
		token = "#";
		return;
	}
	int next_pos = pos + 1;

	/*judge number*/
	if (pos == 0 && (exp[pos] == '-' || exp[pos] == '+'))//process the first -
	{
		type = EXPRESSION::NUM_TYPE;
		token = exp[pos];
		while (isdigit(exp[next_pos]) || exp[next_pos] == '.')
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
	else if (isdigit(exp.at(pos)))
	{
		type = EXPRESSION::NUM_TYPE;
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
			type = EXPRESSION::FUNCTION_TYPE;
			pos = next_pos;
			//#ifdef DEBUG
			//			cout << "token is " << token << endl;
			//#endif // DEBUG
			return;
		}
		else if (isOperator(token) != -1)
		{
			type = EXPRESSION::OPERATOR_TYPE;
			pos = next_pos;
			//#ifdef DEBUG
			//			cout << "token is " << token << endl;
			//#endif // DEBUG
			return;
		}
		else if (isVariable(token) != -1)//是变量
		{
			type = EXPRESSION::VARIABLE_TYPE;
			pos = next_pos;
			//#ifdef DEBUG
			//			cout << "token is " << token << endl;
			//#endif // DEBUG
			return;
		}
		else if (exp[next_pos - 1] == '#')
		{
			check_input = false;
			type = EXPRESSION::UNKNOW_TYPE;//WRONG TYPE
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
	//{"fc", "+", "-", "^" , "*", "/", "(", ")", "#" };
	int index = isOperator(Operator);
	switch (index)
	{
	case 1:
		return Operand[0] + Operand[1];
	case 2:
		return Operand[0] - Operand[1];
	case 3:
		return pow(Operand[0], Operand[1]);
	case 4:
		return Operand[0] * Operand[1];
	case 5:
		if (Operand[0] == 0)
		{
			//check_input = false;
			return INF;
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
		if (expression_systerm == EXPRESSION::RADIAN_SYSTERM)
			return sin(Operand[0]);
		else //ANGLE_SYSTERM
			return sin(Operand[0] / 360 * EXPRESSION::pi);
	case 1:
		if (expression_systerm == EXPRESSION::RADIAN_SYSTERM)
			return cos(Operand[0]);
		else //ANGLE_SYSTERM
			return cos(Operand[0] / 360 * EXPRESSION::pi);
	case 2:
		if (expression_systerm == EXPRESSION::RADIAN_SYSTERM)
		{
			return tan(Operand[0]);
		}
		else //ANGLE_SYSTERM
		{
			//if(Operand[0] % 360 == 0)
			return tan(Operand[0] / 360 * EXPRESSION::pi);
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
			return INF;
			//check_input = false;
			//return 0;
		}
		return log(Operand[0]);
	case 7:
		if (Operand[0] < 0)
		{
			return INF;
			//check_input = false;
			//return 0;
		}
		return log10(Operand[0]);
	case 8:
		if (Operand[0] < 0)
		{
			return INF;
			//check_input = false;
			//return 0;
		}
		return sqrt(Operand[0]);
		//case 9:
		//	pow(Operand[0], Operand[1]);
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
	for (int i = 0; i < OPERATOR_AMOUNT; i++)
	{
		if (str == Operator[i])
			return i;
	}
	return -1;
}

bool Expression::preposition(char c)
{
	if (c == '(')return true;
	for (int i = 0; i < FUN_AMOUNT; i++)
	{
		if (c == function[i].at(0))
			return true;
	}
	return false;
}
bool Expression::postposition( char c)
{
	if (c == ')')return true;
	else return false;
}
bool Expression::isOperator(char c)
{
	for (int i = 1; i < OPERATOR_AMOUNT - 3; i++)// + - ^ * / 
	{
		if (c == Operator[i].at(0))
			return true;
	}
	return false;
}
int Expression::isVariable(string str, int place)//返回序号
{
	//std::cout << "place" << place << std::endl;
	if (VariableAmount == 0)return -1;
	int len = str.length();
	for (int i = 0; i < VariableAmount; i++)
	{
		if (place + VariableName[i].length() > len)continue;
		if (str.substr(place, place + VariableName[i].length()) == VariableName[i])
		{
			return i;
		}
	}
	return -1;
}


Function_2D::Function_2D(string VariableName_, string expression_) :eps(0.00001)
{
	VariableName[0] = VariableName_;
	expression = expression_;
	FunctionExpression = new Expression(expression, 1, VariableName);//会不会有问题啊...感觉会有问题啊...
}
void Function_2D::reset(string VariableName_,string expression_)
{
	VariableName[0] = VariableName_;
	expression = expression_;
	if (FunctionExpression != nullptr)
		delete FunctionExpression;
	FunctionExpression = new Expression(expression, 1, VariableName);
}

Function_2D::~Function_2D()
{
	delete FunctionExpression;
	FunctionExpression = nullptr;
}


bool Function_2D::getAns(double Value_,double & answer)
{
	double value[1] = { Value_ };
	double ans;
	answer = 0;
	if (FunctionExpression->getAns(ans, value) == 0)//good input
	{
		answer = ans;
		return true;
	}
	else return false;//bug here 
}
bool Function_2D::getDerivativeValue(double Value_,double& ans)//微分具体的值
{
	double y1 ,y2;
	ans = 0;
	if (getAns(Value_, y1) == true && getAns(Value_ + eps, y2) == true)
	{
		ans = (y2 - y1) / eps;
		return true;
	}
	else return false;
}
bool Function_2D::getIntergralValue(double x1, double x2,double &ans)//积分具体的值
{
	double tmp = 0;
	for (; x1 < x2; x1 += eps)
	{
		if (getAns(x1, tmp) == true)ans += tmp;
		else return false;
	}
	return false;
}