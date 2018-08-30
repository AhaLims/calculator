#include "help_window.h"

help_window::help_window(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.help_button->hide();
	ui.about_button->hide();
}

