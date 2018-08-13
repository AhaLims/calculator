#include "main_window.h"
#include"QT_OpenGL.h"
#include <QtWidgets/QMessageBox>
#include"help_window.h"
main_window::main_window(int Argc,
	char *Argv[], QWidget *parent)
	: QMainWindow(parent),argc(Argc),argv(Argv)
{
	matrix_caculator = new caculator_gui;
	//应该没错吧.....
	qtopengl = new QTOpenGL(argc, argv);
	qtopengl_widget = new QT_OpenGL(qtopengl);
	Help_window = new help_window();
	ui.setupUi(this);
	//QT_OpenGL_function = new QT_OpenGL(this);
}
main_window::~main_window()
{
	delete qtopengl;
	delete matrix_caculator;
	delete qtopengl_widget;
	delete Help_window;
}

void  main_window::push_matrix_caculator_button()
{
	matrix_caculator->show();
}

void main_window::push_scientic_caculator_button()
{

}
void main_window::push_function_caculator_button()
{
	qtopengl_widget->show();
}
void main_window::push_help_button()
{
	Help_window->show();
	//QMessageBox::about(NULL, "help", "这是一个多功能的计算器\n选择一个功能进行计算吧");
}
void main_window::push_linear_equation_button()
{

}
