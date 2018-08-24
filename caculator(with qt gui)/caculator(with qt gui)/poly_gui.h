#pragma once

#include <QtWidgets/QWidget>
#include "ui_poly_gui.h"

class poly_gui : public QWidget
{
	Q_OBJECT

public:
	poly_gui(QWidget *parent = Q_NULLPTR);

private:
	Ui::poly_guiClass ui;
};
