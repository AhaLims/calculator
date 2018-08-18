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
double QTOpenGL::LevelMovement = 0;
double QTOpenGL::ViticalMovement = 0;

QTOpenGL::QTOpenGL(int Argc, char* Argv[]) :
	argc(Argc), argv(Argv)
{
	LevelMovement = 0;
	ViticalMovement = 0;
}
void QTOpenGL::draw_axis()
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	/*��������ģʽ*/
	glLineStipple(2, 0x5555);
	glEnable(GL_LINE_STIPPLE);


	///*������ƽ�Ʊ任��*/
	//float pointx1[] = { -centre_x * times + LevelMovement,0 };
	//float pointx2[] = { centre_x * times + LevelMovement, 0 };
	//float pointy1[] = { 0 + LevelMovement, centre_y * times };
	//float pointy2[] = { 0 + LevelMovement, -centre_y * times };

	/*ˮƽ��*/
	float pointx1[] = { -centre_x * times ,0 + ViticalMovement };
	float pointx2[] = { centre_x * times, 0 + ViticalMovement };

	/*��ֱ��*/
	float pointy1[] = { 0 + LevelMovement, centre_y * times };
	float pointy2[] = { 0 + LevelMovement, -centre_y * times };

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

						   //Ҳ������ö��߳� �� + ����
						   /* ���պ�����*/
	//glBegin(GL_LINE_STRIP);
	/*��� ����*/
	//for (x = -1.0f; x <= 1.0f; x += deltax)
	//	glVertex2f(x * centre_x * times + LevelMovement, getY(x) * centre_y * times + ViticalMovement);

	//glEnd();

	glBegin(GL_LINE_STRIP);
	/*��� ����*/
	for (x = -1.0f; x <= 1.0f; x += deltax)
		glVertex2f(x * centre_x * times, getY(x - LevelMovement / Width * 2) * centre_y * times + ViticalMovement);
		//û̫Ū�������� *2�ĺ���..
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

	/*���ô��ڵĿ��*/
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



QT_OpenGL::QT_OpenGL( QTOpenGL * ptr , QWidget *parent )
	: QWidget(parent),qtopengl_ptr(ptr)//��������Ҫǳ����
{
	ui.setupUi(this);
}
void QT_OpenGL::push_help()
{
	//����
}
void QT_OpenGL::push_example()
{
	//����
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