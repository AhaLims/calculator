#include "poly_gui.h"
#include"source.h"
#include"qlineedit.h"
#include"Poly.h"
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
	//ui.horizontalLayout->setGeometry(QRect(80, 140, num * 100, 50));
	ui.horizontalLayout->setGeometry(QRect(80, 140, 940, 440));
	names = new QLabel[num + 1];
	elements = new QLineEdit[num + 1];
	QString tmp;
	for (int i = 0; i <= num; i++)
	{
		names[i].setParent(this);
		ui.horizontalLayout->addWidget(&elements[i]);//为啥子没有了...BUG
		if (i == 0)tmp = "x^"+ QString::number(num);
		else tmp = "+x^" + QString::number(num - i);
		names[i].setText(tmp);
		ui.horizontalLayout->addWidget(&names[i]);
		elements[i].setParent(this);
	}
}
void poly_gui::change_time()
{
	int time = ui.spinBox->value();
	reset(time);
}
void poly_gui::get_der()
{
	if (poly_expression != nullptr)
		delete poly_expression;
}
void poly_gui::get_inter()
{
	if (poly_expression != nullptr)
		delete poly_expression;
}
void poly_gui::get_zero()
{
	if (poly_expression != nullptr)
		delete poly_expression;
}

