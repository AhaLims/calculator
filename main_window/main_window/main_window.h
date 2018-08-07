#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"

class main_window : public QMainWindow
{
	Q_OBJECT

public:
	main_window(QWidget *parent = Q_NULLPTR);

private:
	Ui::main_windowClass ui;
public slots:
	void push_matrix_caculator_button();
	void push_scientic_caculator_button();
	void push_function_caculator_button();
	void push_help_button();
	void push_linear_equation_button();
};
