#pragma once

#include <QtWidgets/QWidget>
#include "ui_QT_OpenGL.h"
#include <GL/glut.h>
//？？？？？？？？？为什么加了extern就可以了？？？？？
extern class QTOpenGL
{
public:
	QTOpenGL(int, char*[]);//传递命令行参数
	static void draw_axis();//画坐标轴
	static void draw_function();
	void start_OpenGL();//开启OpenGL 窗口
	static float getY(float);//通过计算得到y的值

	/*通过平移变换实现四个方向的移动*/
	void move_left();
	void move_right();
	void move_up();
	void move_down();
	//void enlarge();
	//void lessen();
	//void reset();//还原
private:
	int argc;
	char **argv;
	static const int Width;
	static const int Height;
	static double times;
	static const GLfloat PI;
	static const int centre_x; //中心点
	static const int centre_y;
	static double LevelMovement, ViticalMovement;
	static double factor;//暂时不用
};

/*界面*/
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
//	const float correction_factor;////不知道为什么会出现偏差的系数 
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


