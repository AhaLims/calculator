#pragma once
#include<string>
#include <QtWidgets/QWidget>
#include "ui_SicenticCaculator_gui.h"
class scientic_calculator;
class SicenticCaculator_gui : public QWidget
{
	Q_OBJECT

public:
	SicenticCaculator_gui(QWidget *parent = Q_NULLPTR);
	~SicenticCaculator_gui();
private slots:
	void click_num1();
	void click_num2();
	void click_num3();
	void click_num4();
	void click_num5();
	void click_num6();
	void click_num7();
	void click_num8();
	void click_num9();
	void click_num0();
	void click_num00();
	void click_left_bracket();
	void click_right_bracket();
	void click_point();
	void click_tan();
	void click_cos();
	void click_sin();
	void click_arctan();
	void click_arccos();
	void click_arcsin();
	void click_ln();
	void click_log();
	void click_sqrt();
	void click_e();
	void click_pi();
	void click_clear();
	void click_save();
	void click_read();
	void click_add();
	void click_multy();
	void click_sub();
	void click_divide();
	void click_power();
	void click_history();
	void click_ans();
	void change_digits();
private:
	void store_data(double, std::string);
	Ui::Form ui;
	scientic_calculator * caculator;
};
