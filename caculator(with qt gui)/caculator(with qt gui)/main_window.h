#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"
#include"caculator_gui.h"
//#include"QT_OpenGL.cpp"
class QTOpenGL;
class caculator_gui;
class QT_OpenGL;
class help_window;
class SicenticCaculator_gui;
//class LinearEquation_gui;
class main_window : public QMainWindow
{
	Q_OBJECT

public:
	main_window(int Argc,
		char *Argv[],QWidget *parent = Q_NULLPTR );
	~main_window();

private:
	Ui::main_windowClass ui;
	int argc;
	char **argv;
	caculator_gui * matrix_caculator;
	help_window *Help_window;

	//LinearEquation_gui *linear_equation_gui;
	QTOpenGL *qtopengl;//实际操作 在QT_OpenGL 界面中
	QT_OpenGL *qtopengl_widget;
	SicenticCaculator_gui * scientic_caculator_gui;
public slots:
	void push_matrix_caculator_button();
	void push_scientic_caculator_button();
	void push_function_caculator_button();
	void push_help_button();
	//void push_linear_equation_button();
};
