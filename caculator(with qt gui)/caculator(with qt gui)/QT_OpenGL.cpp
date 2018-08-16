#include <gl\glut.h>    
#include <gl\GLU.h>
#include <gl\GL.h>
#include <math.h>
#include"QT_OpenGL.h"

const int QTOpenGL::Width = 800;
const int QTOpenGL::Height = 800;
double QTOpenGL::times = 1;
const GLfloat QTOpenGL::PI = 3.1415926536f;
const int QTOpenGL::centre_x = Width / 2; //���ĵ�
const int QTOpenGL::centre_y = Height / 2;

QTOpenGL::QTOpenGL(int Argc, char* Argv[]) :
	argc(Argc), argv(Argv)
{

}
void QTOpenGL::draw_axis()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	/*��������ģʽ*/
	glLineStipple(2, 0x5555);
	glEnable(GL_LINE_STIPPLE);

	/*��������ϵ�ĸ��������*/
	float pointx1[] = { -centre_x * times,0 };
	float pointx2[] = { centre_x * times, 0 };
	float pointy1[] = { 0 , centre_y * times };
	float pointy2[] = { 0 , -centre_y * times };



	/*�������� */
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
	/*�������ߵ���ɫ*/
	glColor3f(0.0f, 1.0f, 0.0f);
	float x;
	float deltax = 0.005f; // ��������

						   //Ҳ�������ö��߳� �� + ����
						   /* ���պ�����*/
	glBegin(GL_LINE_STRIP);
	/*��� ����*/
	for (x = -1.0f; x <= 1.0f; x += deltax)
		glVertex2f(x * centre_x * times, getY(x) * centre_y * times);
	glEnd();
}
void myDisplay_(void)//�ص�����
{
	QTOpenGL::draw_axis();
	QTOpenGL::draw_function();
	glFlush();
}
void QTOpenGL::start_OpenGL()
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	/*���ô��ڵĿ���*/
	glutInitWindowSize(Width, Height);

	glutCreateWindow("����ͼ��");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, Width, 0.0, Height);

	/*��������ԭ��*/
	glTranslatef(centre_x, centre_y, 0);

	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(&myDisplay_);
	//glutKeyboardFunc(&test(VK_LEFT,0,0));
	//glutKeyboardFunc(void(*func)(unsigned char key, int x, int y));
	glutMainLoop();
}
float QTOpenGL::getY(float x)
{
	return sin (x *PI);
}


QT_OpenGL::QT_OpenGL( QTOpenGL * ptr , QWidget *parent )
	: QWidget(parent),qtopengl_ptr(ptr)//��������Ҫǳ����
{
	ui.setupUi(this);
}
void QT_OpenGL::push_help()
{

}
void QT_OpenGL::push_example()
{

}
void QT_OpenGL::push_OK()
{
	qtopengl_ptr->start_OpenGL();
}
void QT_OpenGL::push_enlarge()
{

}
void QT_OpenGL::push_lessen()
{

}
void QT_OpenGL::push_left()
{

}
void QT_OpenGL::push_right()
{

}
void QT_OpenGL::push_up()
{

}
void QT_OpenGL::push_down()
{

}


//#include "QT_OpenGL.h"
////#include<QtOpenGL/qgl.h>//����ģ��
////#include <GL/glut.h>
//
////#include <QtOpenGL/QGLWidget>
//
//QT_OpenGL::QT_OpenGL(QWidget *parent)
//	: QWidget(parent),function_paint(this)
//{
//	ui.setupUi(this);
//	function_paint.show();
//
//}
//
//float getY(float x)//δ֪��Ϊx ���뺯�� �õ�y��ֵ
//{
//	return x*x;
//}
//
//
//function_GL::function_GL(QWidget *parent):  QGLWidget(parent), 
//											Width(650), Height(650),PI(3.1415926536f), 
//											correction_factor(2.0625), translation_factor(0.4875f)
//{
//	times = 1;
//	setGeometry(30, 220, Width, Height);
//}
//function_GL::~function_GL()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		i++;/////////delete
//	}
//}
//
//
//void function_GL::initializeGL()
//{
//	glLoadIdentity();
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_SMOOTH);
//}
//void function_GL::paintGL()
//{
//	glColor3f(1.0f, 0.0f, 0.0f);
//
//	/*��������ģʽ*/
//	glLineStipple(2, 0x5555);
//	glEnable(GL_LINE_STIPPLE);
//
//	/*��������ϵ�ĸ��������*///0,0 �����������
//	float pointx1[] = { -1.0f,0 };
//	float pointx2[] = { 1.0f, 0 };
//	float pointy1[] = { -translation_factor , 1.0f};
//	float pointy2[] = { -translation_factor , -1.0f- translation_factor };
//
//
//
//	/*�������� */
//	glBegin(GL_LINES);
//	glVertex2fv(pointx1);
//	glVertex2fv(pointx2);
//
//	glVertex2fv(pointy1);
//	glVertex2fv(pointy2);
//	glEnd();
//	glDisable(GL_LINE_STIPPLE);
//
//	/*�������ߵ���ɫ*/
//	glColor3f(0.0f, 1.0f, 0.0f);
//	float x;
//	float deltax = 0.0005f; // ��������
//
//						   //Ҳ�������ö��߳� �� + ����
//						   /* ���պ�����*/
//	glBegin(GL_LINE_STRIP);
//	/*��� ����*/
//	for (x = -1.0f; x <= 1.0f; x += deltax)
//		glVertex2f(x-0.4875f, getY(x * correction_factor));
//	glEnd();
//	glFlush();
//}
//void function_GL::resizeGL(int width, int height)
//{
//	for (int i = 0; i < 5; i++)
//	{
//		i++;/////////delete
//	}
//}