#pragma once

#include <QtWidgets/QWidget>
#include "ui_LinearEquation_gui.h"
#include"DynamicModule.h"
class LinearEquation_gui : public QWidget
{
	Q_OBJECT

public:
	LinearEquation_gui(QWidget *parent = Q_NULLPTR);
	~LinearEquation_gui();
private:
	void paintEvent(QPaintEvent * e);
	Ui::LinearEquation_guiClass ui;
	int amount;
	void set();
	DynamicModule *Module;
	QLabel *answer_show;
private slots:
	void change_equation();
	void push_get_answer_button();
};
