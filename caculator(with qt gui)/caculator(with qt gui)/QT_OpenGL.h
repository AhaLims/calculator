#pragma once

#include <QtWidgets/QWidget>
#include "ui_QT_OpenGL.h"
#include <GL/glut.h>
//������������������Ϊʲô����extern�Ϳ����ˣ���������
extern class QTOpenGL
{
public:
	QTOpenGL(int, char*[]);//���������в���
	static void draw_axis();//��������
	static void draw_function();
	void start_OpenGL();//����OpenGL ����
	static float getY(float);//ͨ������õ�y��ֵ

	/*ͨ��ƽ�Ʊ任ʵ���ĸ�������ƶ�*/
	void move_left();
	void move_right();
	void move_up();
	void move_down();
	//void enlarge();
	//void lessen();
	//void reset();//��ԭ
private:
	int argc;
	char **argv;
	static const int Width;
	static const int Height;
	static double times;
	static const GLfloat PI;
	static const int centre_x; //���ĵ�
	static const int centre_y;
	static double LevelMovement, ViticalMovement;
	static double factor;//��ʱ����
};

/*����*/
class QT_OpenGL : public QWidget
{
	Q_OBJECT

public:
	QT_OpenGL(QTOpenGL * ptr = nullptr,QWidget *parent = Q_NULLPTR);

private:
	Ui::QT_OpenGLClass ui;
	QTOpenGL * qtopengl_ptr;
private slots:
	void push_help();
	void push_example();
	void push_OK();
	//void push_enlarge();
	//void push_lessen();
	void push_left();
	void push_right();
	void push_up();
	void push_down();
	//void reset();

};


//extern class function_GL :public QGLWidget// ,protected QGLFunctions//QOpenGLFunctions
//{
//	Q_OBJECT
//public:
//	function_GL( QWidget *);
//	~function_GL();
//protected:
//
//	void initializeGL();
//	void paintGL();
//	void resizeGL(int width, int height);
//private:
//	const int Width;
//	const int Height;
//	const GLfloat PI;
//	const float correction_factor;////��֪��Ϊʲô�����ƫ���ϵ�� 
//	const float translation_factor;
//	double times;
//};
//
//class QT_OpenGL : public QWidget
//{
//	Q_OBJECT
//
//public:
//	QT_OpenGL(QWidget *parent = Q_NULLPTR);
//	function_GL function_paint;
//private:
//	Ui::QT_OpenGLClass ui;
//
//	
//};


