#include "help_window.h"

help_window::help_window(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//ui.about_label->hide();
	//ui.help_label->hide();
}

//void help_window::push_help_button()
//{
//	//ui.about_label->hide();
//	ui.help_label->show();
//}
//void help_window::push_about_button()
//{
//	ui.about_label->show();
//	ui.help_label->hide();
//}
