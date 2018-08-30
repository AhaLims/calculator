#pragma once

#include <QtWidgets/QWidget>
#include "ui_Point24_gui.h"
class Point24_gui : public QWidget
{
	Q_OBJECT

public:
	Point24_gui(QWidget *parent = Q_NULLPTR);

private:
	Ui::Point24_guiClass ui;
private slots:
	void caculate_button();
	void clear();
};
