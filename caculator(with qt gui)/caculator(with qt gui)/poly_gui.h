#pragma once

#include <QtWidgets/QWidget>
#include "ui_poly_gui.h"
#include<qlayout.h>
class Poly;
class QLabel;
class QLineEdit;


class poly_gui : public QWidget
{
	Q_OBJECT

public:
	poly_gui(QWidget *parent = Q_NULLPTR);
	~poly_gui();
private:
	Ui::poly_guiClass ui;
	Poly * poly_expression;
	QLabel * names;
	QLineEdit * elements;
	void reset(int );
	void get_value(double[]);
	int time;
private slots:
	

	void change_time();
	void get_der();
	void get_inter();
	void get_zero();
};
