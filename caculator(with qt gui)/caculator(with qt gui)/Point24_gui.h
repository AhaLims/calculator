#pragma once

#include <QtWidgets/QWidget>
#include "ui_Point24_gui.h"
class Point24;
class Point24_gui : public QWidget
{
	Q_OBJECT

public:
	Point24_gui(QWidget *parent = Q_NULLPTR);
	~Point24_gui();
private:
	Ui::Point24_guiClass ui;
	Point24 * point24;
private slots:
	void caculate_button();
	void clear();
};
