#include "LinearEquation_gui.h"

LinearEquation_gui::LinearEquation_gui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Module = nullptr;
	amount = 3;
	set();//初始化的时候设置为3个变量
	ui.spinBox->setRange(1, 10);  // 范围
	ui.spinBox->setValue(1);//当前值
	ui.spinBox->setWrapping(false);  // 不开启循环
}

void LinearEquation_gui::set()
{
	if (Module != nullptr)
		delete Module;
	Module = new DynamicModule[amount];
	for (int i = 0; i < amount; i++)
	{
		ui.verticalLayout->addLayout(Module[i].set(amount));
	}
}

void LinearEquation_gui::change_equation()
{
	amount = ui.spinBox->value();
	set();
}
LinearEquation_gui::~LinearEquation_gui()
{
	if(Module != nullptr)
		delete Module;
}
