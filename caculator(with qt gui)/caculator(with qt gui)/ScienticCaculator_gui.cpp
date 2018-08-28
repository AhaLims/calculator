#include "ScienticCaculator_gui.h"
#include"ScienticCaculartor.h"
#include"qmessagebox.h"
SicenticCaculator_gui::SicenticCaculator_gui(QWidget *parent)
	: QWidget(parent)
{
	caculator = new scientic_calculator;
	
	ui.setupUi(this);
	ui.spinBox->setRange(0, 6);
	ui.spinBox->setValue(2);
	ui.spinBox->setWrapping(false);
	ui.histrory->hide();
}

SicenticCaculator_gui::~SicenticCaculator_gui()
{
	delete caculator;
}
void SicenticCaculator_gui::click_num1()
{
	QString str = ui.textEdit->toPlainText();
	ui.textEdit->cursor();
	str += "1";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_num2()
{
	QString str = ui.textEdit->toPlainText();
	str += "2";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_num3()
{
	QString str = ui.textEdit->toPlainText();
	str += "3";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_num4()
{
	QString str = ui.textEdit->toPlainText();
	str += "4";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_num5()
{
	QString str = ui.textEdit->toPlainText();
	str += "5";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_num6()
{
	QString str = ui.textEdit->toPlainText();
	str += "6";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_num7()
{
	QString str = ui.textEdit->toPlainText();
	str += "7";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_num8()
{
	QString str = ui.textEdit->toPlainText();
	str += "8";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_num9()
{
	QString str = ui.textEdit->toPlainText();
	str += "9";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_num0()
{
	QString str = ui.textEdit->toPlainText();
	str += "0";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_num00()
{
	QString str = ui.textEdit->toPlainText();
	str += "00";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_left_bracket()
{
	QString str = ui.textEdit->toPlainText();
	str += "(";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_right_bracket()
{
	QString str = ui.textEdit->toPlainText();
	str += ")";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_point()
{
	QString str = ui.textEdit->toPlainText();
	str += ".";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_tan()
{
	QString str = ui.textEdit->toPlainText();
	str += "tan(";
	ui.textEdit->setText(str);
}

void  SicenticCaculator_gui::click_cos()
{
	QString str = ui.textEdit->toPlainText();
	str += "cos(";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_sin()
{
	QString str = ui.textEdit->toPlainText();
	str += "sin(";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_arctan()
{
	QString str = ui.textEdit->toPlainText();
	str += "arctan(";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_arccos()
{
	QString str = ui.textEdit->toPlainText();
	str += "arccos(";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_arcsin()
{
	QString str = ui.textEdit->toPlainText();
	str += "arcsin(";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_ln()
{
	QString str = ui.textEdit->toPlainText();
	str += "ln(";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_log()
{
	QString str = ui.textEdit->toPlainText();
	str += "log(";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_sqrt()
{
	QString str = ui.textEdit->toPlainText();
	str += "sqrt(";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_e()
{
	QString str = ui.textEdit->toPlainText();
	str += "e";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_pi()
{
	QString str = ui.textEdit->toPlainText();
	str += "pi";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_clear()
{
	ui.textEdit->clear();
}
void SicenticCaculator_gui::click_save()
{
	double ans;
	string str = ui.textEdit->toPlainText().toStdString();
	if (str == "" ||!caculator->getAns(ans, str))
	{
		QMessageBox::about(NULL, "wrong", tr("wrong intput"));
		return;
	}
	caculator->setC(ans);
}
void SicenticCaculator_gui::click_read()
{
	double ans = caculator->getC();
	QString str = ui.textEdit->toPlainText() + QString::number(ans, 10, caculator->get_digits());
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_add()
{
	QString str = ui.textEdit->toPlainText();
	str += "+";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_multy()
{
	QString str = ui.textEdit->toPlainText();
	str += "*";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_sub()
{
	QString str = ui.textEdit->toPlainText();
	str += "-";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_divide()
{
	QString str = ui.textEdit->toPlainText();
	str += "/";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_power()
{
	QString str = ui.textEdit->toPlainText();
	str += "^";
	ui.textEdit->setText(str);
}
void SicenticCaculator_gui::click_history()
{
	//读历史记录
}
void SicenticCaculator_gui::click_ans()
{
	double eps = 0.0000001;
	double ans;
	string str = ui.textEdit->toPlainText().toStdString();
	if (caculator->getAns(ans, str))
	{
		store_data(ans, str);
		if (fabs(ans) < eps)ans = 0;
		QString qstr = QString::number(ans, 10, caculator->get_digits());
		ui.ans->setText(qstr);
	}
	else
	{
		QMessageBox::about(NULL, "wrong", tr("wrong intput"));
	}
}
void SicenticCaculator_gui::store_data(double ans,string str)
{
	//储存数据part
}
void SicenticCaculator_gui::change_digits()
{
	unsigned int d = ui.spinBox->value();
	caculator->change_digits(d);

}
