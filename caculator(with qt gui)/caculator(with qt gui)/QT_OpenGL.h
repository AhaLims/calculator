#pragma once

#include <QtWidgets/QWidget>
#include "ui_QT_OpenGL.h"
#include <GL/glut.h>
void KeyBoards(unsigned char key, int x, int y);//register keboard event
extern class QTOpenGL
{
public:
	QTOpenGL(int, char*[]);//transmit command line parameter
	static void draw_axis();
	static void draw_function();
	void start_OpenGL();
	static float getY(float);

	void move_left();
	void move_right();
	void move_up();
	void move_down();
	//void enlarge();
	//void lessen();
	//void reset();

private:
	int argc;
	char **argv;
public:
	static const int Width;
	static const int Height;
	static double times;
	static const GLfloat PI;
	static const int centre_x; 
	static const int centre_y;
	static double LevelMovement, ViticalMovement;
	static double factor;//enlarge or lessen
};

/*ΩÁ√Ê*/
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
	void push_left();
	void push_right();
	void push_up();
	void push_down();
	//void push_enlarge();
	//void push_lessen();
	//void reset();

};

