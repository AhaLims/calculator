#include "Point24_gui.h"
#include"qmessagebox.h"
#include"Point24.h"
#include<algorithm>
#include<iostream>
Point24_gui::Point24_gui(QWidget *parent)
	: QWidget(parent),point24(nullptr)
{
	ui.setupUi(this);
}

Point24_gui::~Point24_gui()
{
	//if (point24 != nullptr)delete point24;
}

void Point24_gui::caculate_button()
{
	int tmp[4];
	if (ui.num1->text() == "" || ui.num2->text() == "" || ui.num3->text() == "" || ui.lineEdit_4->text() == "")
	{
		QMessageBox::about(NULL, "wrong", "please input figures");
		return;
	}
	tmp[0] = ui.num1->text().toInt();
	tmp[1] = ui.num2->text().toInt();
	tmp[2] = ui.num3->text().toInt();
	tmp[3] = ui.lineEdit_4->text().toInt();
	std::sort(tmp, tmp + 4);
	for (int i = 0; i < 4; i++)
	{
		if (tmp[i] <= 0 ||tmp[i] > 13)
		{
			QMessageBox::about(NULL, "wrong", "wrong input");
			return;
		}
	}
	string answer = "";
	while (std::next_permutation(tmp, tmp + 4))
	{
		if (point24 != nullptr)delete point24;
		point24 = new Point24(tmp);
		point24->getAns(answer);
	}
	if (point24 != nullptr) delete point24;
	point24 = nullptr;
	QString qstr = QString::fromStdString(answer);
	qstr += "=====End======\n";
	ui.textBrowser->setText(qstr);
}
void Point24_gui::clear()
{
	ui.num1->clear();
	ui.num2->clear();
	ui.num3->clear();
	ui.lineEdit_4->clear();
}
