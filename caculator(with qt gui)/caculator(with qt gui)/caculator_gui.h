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
	void push_randomA_button();
	void push_randomB_button();
	void push_clearA_button();
	void push_clearB_button();
	void push_detA_button();
	void push_detB_button();
	void push_invA_button();
	void push_invB_button();
	void push_tranA_button();
	void push_tranB_button();
	void push_rankA_button();
	void push_rankB_button();
	void push_getSimplestA_button();
	void push_getSimplestB_button();
	void push_FeatureVectorA_button();
	void push_FeatureVectorB_button();
	void push_FeatureValueA_button();
	void push_FeatureValueB_button();
	void push_NumMulA_button();
	void push_NumMulB_button();
	void push_timeA_button();
	void push_timeB_button();
	void push_timeA_button();
	void push_timeB_button();

private:
	Ui::caculator_guiClass ui;
	bool number_judge(char)const;
	//bug
	Matrix get_random_matrix();
	Matrix QString_to_matrix(const QString&,bool &)const;
	QString Matrix_to_QString(const Matrix&, const unsigned int& )const;
	
};
