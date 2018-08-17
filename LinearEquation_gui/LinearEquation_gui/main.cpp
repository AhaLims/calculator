#include "LinearEquation_gui.h"
#include <QtWidgets/QApplication>
#include<iostream>
#define DEBUG
//内存越界？ 也许是没有delete的问题
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LinearEquation_gui w;
	w.show();
	return a.exec();
}
