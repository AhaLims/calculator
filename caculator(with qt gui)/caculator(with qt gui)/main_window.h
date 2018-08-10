#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"
#include"caculator_gui.h"
class main_window : public QMainWindow
{
	Q_OBJECT

public:
	main_window(QWidget *parent = Q_NULLPTR);
	caculator_gui matrix_caculator;
private:
	Ui::main_windowClass ui;
public slots:
	void push_matrix_caculator_button();
	void push_scientic_caculator_button();
	void push_function_caculator_button();
	void push_help_button();
	void push_linear_equation_button();
};
