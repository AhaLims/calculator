#include "LinearEquation_gui.h"
#include<qmessagebox.h>
LinearEquation_gui::LinearEquation_gui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Module = nullptr;
	amount = 3;
	set();//初始化的时候设置为3个变量
	ui.spinBox->setRange(1, 10);  // 范围
	ui.spinBox->setValue(3);//当前值
	ui.spinBox->setWrapping(false);  // 不开启循环
}

LinearEquation_gui::~LinearEquation_gui()
{
	if ((Module != nullptr))
		delete[] Module;
}

void LinearEquation_gui::set()
{
	if (Module != nullptr)
	{
		delete[] Module;//这里出现了断点？
	}
	Module = new DynamicModule[amount];
	//要改变 layout 的长宽高
	ui.verticalLayoutWidget->setGeometry(QRect(30, 140, 90 * amount, 60 *amount));
	for (int i = 0; i < amount; i++)
	{
		ui.verticalLayout->addLayout(Module[i].set(amount,this));
	}
}

void LinearEquation_gui::change_equation()
{
	amount = ui.spinBox->value();
	set();
}

void LinearEquation_gui::push_get_answer_button()
{
	//get data

}

