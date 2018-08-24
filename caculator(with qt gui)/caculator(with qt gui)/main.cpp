#include "caculator_gui.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include"main_window.h"

//#define DEBUG
#ifdef DEBUG
#include"debug.cpp"
int main()
{
	srand((unsigned)time(NULL));
	while (true)
		poly_test();
	system("pause");
	return 0;
}
#endif // DEBUG

#ifndef DEBUG

int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	QApplication a(argc, argv);
	main_window surface(argc, argv);
	surface.show();
	return a.exec();
}
#endif // DEBUG






