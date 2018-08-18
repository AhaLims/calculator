#include <gl\glut.h>    
#include <gl\GLU.h>
#include <gl\GL.h>
#include <math.h>
#include"QT_OpenGL.h"

const int QTOpenGL::Width = 800;
const int QTOpenGL::Height = 800;
double QTOpenGL::times = 1;
const GLfloat QTOpenGL::PI = 3.1415926536f;
const int QTOpenGL::centre_x = Width / 2; //中心点
const int QTOpenGL::centre_y = Height / 2;
double QTOpenGL::LevelMovement = 0;
double QTOpenGL::ViticalMovement = 0;
double QTOpenGL::factor = 1;

QTOpenGL::QTOpenGL(int Argc, char* Argv[]) :
	argc(Argc), argv(Argv)
{
	LevelMovement = 0;
	ViticalMovement = 0;
	factor = 1;
}
void QTOpenGL::draw_axis()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	/*开启虚线模式*/
	glLineStipple(2, 0x5555);
	glEnable(GL_LINE_STIPPLE);



	/*水平线*/
	float pointx1[] = { (-centre_x * times) * factor , (0 + ViticalMovement) * factor};
	float pointx2[] = { centre_x * times * factor, (0 + ViticalMovement) * factor };

	/*垂直线*/
	float pointy1[] = { 0 + LevelMovement * factor, centre_y * times* factor };
	float pointy2[] = { 0 + LevelMovement * factor, -centre_y * times* factor };

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
	for (x = -1.0f; x <= 1.0f; x += deltax)
		glVertex2f(x * centre_x * times * factor, (getY(x - LevelMovement / Width * 2) * centre_y * times + ViticalMovement) * factor);
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
	glutDisplayFunc(&myDisplay_);
	//glutKeyboardFunc(&test(VK_LEFT,0,0));
	//glutKeyboardFunc(void(*func)(unsigned char key, int x, int y));
	glutMainLoop();
}
float QTOpenGL::getY(float x)
{
	//return x;
	return sin (x *PI);
}
void QTOpenGL::move_left()
{
	LevelMovement -= Width * 0.1;
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}
void QTOpenGL::move_right()
{

	LevelMovement += Width * 0.1;
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}
void QTOpenGL::move_up()
{
	ViticalMovement += Height * 0.1;
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}
void QTOpenGL::move_down()
{
	ViticalMovement -= Height * 0.1;
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	glutMainLoop();
}

//void QTOpenGL::reset()
//{
//	factor = 1;
//	ViticalMovement = 0;
//	LevelMovement = 0;
//	glClear(GL_COLOR_BUFFER_BIT);
//	glutDisplayFunc(&myDisplay_);
//	glutMainLoop();
//}


QT_OpenGL::QT_OpenGL( QTOpenGL * ptr , QWidget *parent )
	: QWidget(parent),qtopengl_ptr(ptr)//这里是需要浅复制
{
	ui.setupUi(this);
}
void QT_OpenGL::push_help()
{
	//补充
}
void QT_OpenGL::push_example()
{
	//补充
}
void QT_OpenGL::push_OK()
{
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

//void QT_OpenGL::reset()//不行？？？
//{
//	qtopengl_ptr->reset();
//}