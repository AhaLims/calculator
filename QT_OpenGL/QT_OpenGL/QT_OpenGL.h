#pragma once

#include <QtWidgets/QWidget>
#include "ui_QT_OpenGL.h"

class QT_OpenGL : public QWidget
{
	Q_OBJECT

public:
	QT_OpenGL(QWidget *parent = Q_NULLPTR);

private:
	Ui::QT_OpenGLClass ui;
private slots:
	void push_help();
	void push_example();
	void push_OK();
	void push_enlarge();
	void push_lessen();
	void push_left();
	void push_right();
	void push_up();
	void push_down();
};
