#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_caculator_gui.h"

class caculator_gui : public QMainWindow
{
	Q_OBJECT

public:
	caculator_gui(QWidget *parent = Q_NULLPTR);

private:
	Ui::caculator_guiClass ui;
};
