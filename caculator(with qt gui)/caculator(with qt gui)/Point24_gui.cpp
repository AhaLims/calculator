#include "Point24_gui.h"
#include"qmessagebox.h"
Point24_gui::Point24_gui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
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
	tmp[1] = ui.lineEdit_4->text().toInt();
	for (int i = 0; i < 4; i++)
	{
		if (tmp[i] <= 0)
		{
			QMessageBox::about(NULL, "wrong", "wrong input");
			return;
		}
	}
	QString qstr;
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
