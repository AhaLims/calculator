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

void LinearEquation_gui::set()
{
	if (Module != nullptr)
	{
#ifdef DEBUG
		std::cout << "delete module\n";
#endif // DEBUG
		delete Module;//这里出现了断点？
	}
#ifdef DEBUG
	std::cout << "new dynamic module\n";
#endif // DEBUG
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

void LinearEquation_gui::push_get_answer_button()
{

}
LinearEquation_gui::~LinearEquation_gui()
{
#ifdef DEBUG
	std::cout << "use linear Equation gui destruct\n";
#endif // DEBUG
	if(Module != nullptr)
		delete Module;
}
