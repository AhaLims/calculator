#include "QT_OpenGL.h"
#include<qgl.h>
QT_OpenGL::QT_OpenGL(QWidget *parent)
	: QWidget(parent),function_paint(this)
{
	ui.setupUi(this);
	function_paint.show();

}
float getY(float x)//δ֪��Ϊx ���뺯�� �õ�y��ֵ
{
	return x*x;
}


//function_GL::function_GL(QWidget* parent = 0, bool fs = false):QGLWidget(parent)
function_GL::function_GL(QWidget *parent):  QGLWidget(parent), 
											Width(650), Height(650),PI(3.1415926536f), 
											correction_factor(2.0625), translation_factor(0.4875f)
{
	times = 1;
	setGeometry(30, 220, Width, Height);
}
function_GL::~function_GL()
{

}


void function_GL::initializeGL()
{
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
}
void function_GL::paintGL()
{
	glColor3f(1.0f, 0.0f, 0.0f);

	/*��������ģʽ*/
	glLineStipple(2, 0x5555);
	glEnable(GL_LINE_STIPPLE);

	/*��������ϵ�ĸ��������*///0,0 �����������
	float pointx1[] = { -1.0f,0 };
	float pointx2[] = { 1.0f, 0 };
	float pointy1[] = { -translation_factor , 1.0f};
	float pointy2[] = { -translation_factor , -1.0f- translation_factor };



	/*�������� */
	glBegin(GL_LINES);
	glVertex2fv(pointx1);
	glVertex2fv(pointx2);

	glVertex2fv(pointy1);
	glVertex2fv(pointy2);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	/*�������ߵ���ɫ*/
	glColor3f(0.0f, 1.0f, 0.0f);
	float x;
	float deltax = 0.0005f; // ��������

						   //Ҳ������ö��߳� �� + ����
						   /* ���պ�����*/
	glBegin(GL_LINE_STRIP);
	/*��� ����*/
	for (x = -1.0f; x <= 1.0f; x += deltax)
		glVertex2f(x-0.4875f, getY(x * correction_factor));
	glEnd();
	glFlush();
}
void function_GL::resizeGL(int width, int height)
{

}
