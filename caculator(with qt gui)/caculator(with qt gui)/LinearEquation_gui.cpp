#include "LinearEquation_gui.h"
#include<qmessagebox.h>
LinearEquation_gui::LinearEquation_gui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Module = nullptr;
	amount = 3;
	set();//��ʼ����ʱ������Ϊ3������
	ui.spinBox->setRange(1, 10);  // ��Χ
	ui.spinBox->setValue(3);//��ǰֵ
	ui.spinBox->setWrapping(false);  // ������ѭ��
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
		delete[] Module;//��������˶ϵ㣿
	}
	Module = new DynamicModule[amount];
	//Ҫ�ı� layout �ĳ����
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

