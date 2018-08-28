#include "main_window.h"
#include"QT_OpenGL.h"
#include <QtWidgets/QMessageBox>
#include"help_window.h"
#include"ScienticCaculator_gui.h"
#include"LinearEquation_gui.h"
#include"poly_gui.h"
main_window::main_window(int Argc,
	char *Argv[], QWidget *parent)
	: QMainWindow(parent),argc(Argc),argv(Argv)
{
	scientic_caculator_gui = new SicenticCaculator_gui;
	matrix_caculator = new caculator_gui;
	qtopengl = new QTOpenGL(argc, argv);
	qtopengl_widget = new QT_OpenGL(qtopengl);
	Help_window = new help_window();
	linear_equation_gui = new LinearEquation_gui();
	Poly_gui = new poly_gui;
	ui.setupUi(this);
	//fix 
	setMinimumSize(1000, 800); 
	setMaximumSize(1000, 800);
}
main_window::~main_window()
{
	delete qtopengl;
	delete matrix_caculator;
	delete qtopengl_widget;
	delete Help_window;
	delete scientic_caculator_gui;
	delete linear_equation_gui;
	delete Poly_gui;

}

void  main_window::push_matrix_caculator_button()
{
	matrix_caculator->show();
}

void main_window::push_scientic_caculator_button()
{
	scientic_caculator_gui->show();
}
void main_window::push_function_caculator_button()
{
	qtopengl_widget->show();
}
void main_window::push_help_button()
{
	Help_window->show();
}
void main_window::push_linear_equation_button()
{
	linear_equation_gui->show();
}
void main_window::push_poly_caculator_button()
{
	Poly_gui->show();
}
