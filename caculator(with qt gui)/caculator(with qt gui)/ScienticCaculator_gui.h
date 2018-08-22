#pragma once

#include <QtWidgets/QWidget>
#include "ui_SicenticCaculator_gui.h"

class SicenticCaculator_gui : public QWidget
{
	Q_OBJECT

public:
	SicenticCaculator_gui(QWidget *parent = Q_NULLPTR);
private slots:
	//void click_num1();

private:
	Ui::Form ui;
};
