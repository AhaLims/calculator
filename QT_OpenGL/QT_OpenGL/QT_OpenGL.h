#pragma once

#include <QtWidgets/QWidget>
#include "ui_QT_OpenGL.h"
#include <qgl.h>
class function_GL :public QGLWidget
{
	Q_OBJECT
public:
	function_GL( QWidget *);
	~function_GL();
protected:

	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
private:
	const int Width;
	const int Height;
	const GLfloat PI;
	const float correction_factor;////不知道为什么会出现偏差的系数 
	const float translation_factor;
	double times;
};

class QT_OpenGL : public QWidget
{
	Q_OBJECT

public:
	QT_OpenGL(QWidget *parent = Q_NULLPTR);
	function_GL function_paint;
private:
	Ui::QT_OpenGLClass ui;

	
};

