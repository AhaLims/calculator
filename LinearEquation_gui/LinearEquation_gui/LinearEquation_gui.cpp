#include "LinearEquation_gui.h"

LinearEquation_gui::LinearEquation_gui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Module = nullptr;
	amount = 3;
	set();//��ʼ����ʱ������Ϊ3������
	ui.spinBox->setRange(1, 10);  // ��Χ
	ui.spinBox->setValue(1);//��ǰֵ
	ui.spinBox->setWrapping(false);  // ������ѭ��
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
