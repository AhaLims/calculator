#include "LinearEquation_gui.h"
#include<qmessagebox.h>
#include"Matrix.h"
#include"source.h"
#include"LinearEqaution.h"
#include"QT_OpenGL.h"
void LinearEquation_gui::paintEvent(QPaintEvent *e)
{
	setMinimumSize(1167, 967);
	setMaximumSize(1167, 967);
	QPixmap pixmap = QPixmap(":/caculator_gui/picture/background.jpg").scaled(this->size());
	QPalette palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(pixmap));
	this->setPalette(palette);
}
LinearEquation_gui::LinearEquation_gui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Module = nullptr;
	amount = 3;
	set();//初始化的时候设置为3个变量
	ui.spinBox->setRange(2, 9);  // 范围
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
		delete[] Module;
	}
	Module = new DynamicModule[amount];
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

/*problem on b */
void LinearEquation_gui::push_get_answer_button()
{
	/*get data*/
	Matrix A(amount, amount, false), b(amount, 1, false), ans;
	int solve;
	double tmp = 0;
	QString qstr;
	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j <= amount; j++)
		{
			//std::cout << "amount:" << amount << " ";
			//std::cout << "i j = " << i << " " << j << "\n";
			qstr = Module[i].elements[j].text();
			if (qstr == "")
			{
				QMessageBox::about(NULL, "WRONG", tr("please enter a number"));
				return;
			}
			tmp = qstr.toDouble();
			if(j != amount)
				A.setData(i, j, tmp);
			else b.setData(i, 0, tmp);
		}
	}
	ans = solveLinearEqaution::getSolution(A, b, solve);//problem!!
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
		QString qstr;
		for (int i = 0; i < amount; i++)
		{
			qstr += "x" + QString::number(i) + "=" + QString::number(ans.getData(i, 0), 10, 2) + "\n" + "\n";
		}
		ui.answer_show->setText(qstr);
	}
	///*manage*/

}

