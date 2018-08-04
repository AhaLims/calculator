#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_caculator_gui.h"
#include<Matrix.h>
#include<QtCore/QString>
namespace status
{
	const bool WrongInput = 0;
	const bool RightInput = 1;
}
class caculator_gui : public QMainWindow
{
	Q_OBJECT

public:
	caculator_gui(QWidget *parent = Q_NULLPTR);
public slots://信号与槽在这里定义！！！！！
	void push_add_button();
	void push_subtract_button();
	void push_multiply_button();
	void push_swap_button();
	//void push_randomA_button();
	//void push_randomB_button();
	//void push_clearA_button();
	//void push_clearB_button();
	//void push_detA_button();
	//void push_detB_button();
private:
	Ui::caculator_guiClass ui;
	Matrix QString_to_matrix(const QString&,bool &)const;
	QString Matrix_to_QString(const Matrix&)const;
};
