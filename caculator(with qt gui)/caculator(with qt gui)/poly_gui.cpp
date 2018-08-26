#include "poly_gui.h"
#include"source.h"
#include"qlineedit.h"
#include"Poly.h"
#include<qlayout.h>
#include <QtWidgets/QWidget>
#include<qmessagebox.h>
poly_gui::poly_gui(QWidget *parent)
	: QWidget(parent),poly_expression(nullptr),names(nullptr),elements(nullptr)
{
	ui.setupUi(this);
	ui.spinBox->setRange(1, 10);
	ui.spinBox->setValue(2);
	ui.spinBox->setWrapping(false);
	reset(2);
}

poly_gui::~poly_gui()
{
	if (poly_expression != nullptr)delete poly_expression;
	if (names != nullptr) delete[] names;
	if (elements != nullptr) delete[]elements;
}

void poly_gui::reset(int num)//reset dynamic module
{
	if (names != nullptr)delete[] names;
	if (elements != nullptr) delete[] elements;
	std::cout << num << std::endl;
	names = new QLabel[num + 1];
	elements = new QLineEdit[num + 1];
	QString tmp;
	ui.horizontalLayout->setGeometry(QRect(30, 140, 90 *num, 60 * num));
	for (int i = 0; i <= num; i++)
	{
		names[i].setParent(this);
		elements[i].setParent(this);
		ui.horizontalLayout->addWidget(&elements[i]);
		if (i != num)tmp = "x^"+ QString::number(num - i) + "+";
		else tmp = "";
		names[i].setText(tmp);
		ui.horizontalLayout->addWidget(&names[i]);
	}
}

void poly_gui::get_value(double value[])
{
	QString qstr;
	double tmp;
	for (int i = time; i >= 0; i--)
	{
		qstr = elements[time - i].text();
		if (qstr == "")
		{
			QMessageBox::about(NULL, "WRONG", tr("please enter a number"));
			return;
		}
		tmp = qstr.toDouble();
		value[i] = tmp;
	}
}
void poly_gui::change_time()
{
	time = ui.spinBox->value();
	reset(time);
}
void poly_gui::get_der()
{
	if (poly_expression != nullptr)
		delete poly_expression;
	double *value = new double[time + 1];
	get_value(value);
	poly_expression = new Poly(time,value,"x");
	string output = poly_expression->get_derivative().output();
	QString qstr = QString::fromStdString(output);
	ui.textBrowser->setText(qstr);
	delete[] value;
}
void poly_gui::get_inter()
{
	if (poly_expression != nullptr)
		delete poly_expression;
	double * value = new double[time + 1];
	get_value(value);
	poly_expression = new Poly(time, value, "x");
	string output = poly_expression->get_integral().output();
	QString qstr = QString::fromStdString(output);
	ui.textBrowser->setText(qstr);
	delete[] value;
}
void poly_gui::get_zero()
{
	if (poly_expression != nullptr)
		delete poly_expression;
	double *ans = nullptr;
	int ans_amount;
	double * value = new double[time + 1];
	get_value(value);
	poly_expression = new Poly(time, value, "x");
	
	if (poly_expression->solve(ans, ans_amount))
	{
		//ans is all the answer of this poly 
		QString qstr;
		
		for (int i = 0; i < ans_amount; i++)
		{
			qstr += "x" + QString::number(i + 1) + " = " + QString::number(ans[i]) + "\n";
		}
		ui.textBrowser->setText(qstr);
		if(ans != nullptr)
			delete[] ans;
	}
	else
	{
		ui.textBrowser->setText("no answer");
	}
	if(value != nullptr)
		delete[] value;
}

