//#pragma once
//
//#include <QtWidgets/QWidget>
//#include "ui_QT_OpenGL.h"
//#include <GL/glut.h>
//
//#include <QtOpenGL/QGLWidget>
//
//#include<QtOpenGL/qgl.h>//����ģ��
////class main_window;
////virtual void initializeGL();
////virtual void resizeGL(int w, int h);
////virtual void paintGL();
//
////virtual void initializeOverlayGL();
////virtual void resizeOverlayGL(int w, int h);
////virtual void paintOverlayGL();
////virtual void glInit();
////virtual void glDraw();
//class function_GL :public QGLWidget// ,protected QGLFunctions//QOpenGLFunctions
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
//
extern class QTOpenGL//������������������Ϊʲô����extern�Ϳ����ˣ���������
{
public:
	QTOpenGL(int, char*[]);
	 static void draw_axis();
	//void myDisplay_(void);
	void start_OpenGL();
private:
	int argc;
	char **argv;
};
