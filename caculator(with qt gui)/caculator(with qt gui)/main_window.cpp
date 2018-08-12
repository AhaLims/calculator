#include "main_window.h"
#include"QT_OpenGL.h"
#include <QtWidgets/QMessageBox>
main_window::main_window(int Argc,
	char *Argv[], QWidget *parent)
	: QMainWindow(parent),argc(Argc),argv(Argv)
{
	qtopengl = new QTOpenGL(argc, argv);
	ui.setupUi(this);
	//QT_OpenGL_function = new QT_OpenGL(this);
}
main_window::~main_window()
{
	delete qtopengl;
}

void  main_window::push_matrix_caculator_button()
{
	matrix_caculator.show();
}

void main_window::push_scientic_caculator_button()
{

}
void main_window::push_function_caculator_button()
{
	qtopengl->start_OpenGL();
	//QT_OpenGL_function.show();
	//QT_OpenGL_function->show();
}
void main_window::push_help_button()
{
	QMessageBox::about(NULL, "help", "这是一个多功能的计算器\n选择一个功能进行计算吧");
}
void main_window::push_linear_equation_button()
{

}
