#include "main_window.h"
#include <QtWidgets/QMessageBox>
main_window::main_window(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void  main_window::push_matrix_caculator_button()
{

}

void main_window::push_scientic_caculator_button()
{

}
void main_window::push_function_caculator_button()
{

}
void main_window::push_help_button()
{
	QMessageBox::about(NULL, "help", "����һ���๦�ܵļ�����\nѡ��һ�����ܽ��м����");
}
void main_window::push_linear_equation_button()
{

}
