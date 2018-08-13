#pragma once

#include <QtWidgets/QWidget>
#include "ui_help_window.h"

class help_window : public QWidget
{
	Q_OBJECT

public:
	help_window(QWidget *parent = Q_NULLPTR);

private:
	Ui::help_windowClass ui;
//private slots:
//	void push_help_button();
//	void push_about_button();
};
