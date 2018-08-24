#pragma once

#include <QtWidgets/QWidget>
#include "ui_choose.h"
class poly_gui;
class QT_OpenGL;
class choose : public QWidget
{
	Q_OBJECT

public:
	choose(QWidget *parent = Q_NULLPTR, poly_gui *p = nullptr, QT_OpenGL *Opengl_gui = nullptr);

private:
	Ui::chooseClass ui;
	poly_gui * poly;
	QT_OpenGL *opengl_gui;
private slots:
	void push_2D_painter();
	void push_poly();
};
