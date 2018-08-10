#include "LinearEquation_gui.h"
#include <QtWidgets/QApplication>
#include<iostream>
#define DEBUG

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LinearEquation_gui w;
	w.show();
	return a.exec();
}
