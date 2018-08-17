#include "LinearEquation_gui.h"
#include<qmessagebox.h>
#include"Matrix.h"
#include"source.h"
#include"LinearEqaution.h"
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
	/*get data*/
	Matrix A(amount, amount, false),b(1,amount,false),ans;
	int solve;
	double tmp = 0;
	QString qstr;
	for (int i = 0; i <= amount; i++)
	{
		for (int j = 0; j < amount; j++)
		{
			
			qstr = Module[i].elements[j].text();
			if (qstr == "")
			{
				QMessageBox::about(NULL, "WRONG", tr("please enter a number"));
				return;
			}
			tmp = qstr.toDouble();
			if(i != amount)
				A.setData(i, j, tmp);
			else b.setData(0, j, tmp);
		}
	}
	ans = solveLinearEqaution::getSolution(A, b, solve);
	if (solve == 0)//no solution
	{
		QMessageBox::about(NULL, "Tip", tr("No solution"));
	}
	else if (solve == 2)
	{
		QMessageBox::about(NULL, "Tip", tr("More than one solution"));
	}
	else //if(solve == 1)//only one 
	{
		//use label to show
	}
	/*manage*/

}

