#include <QtWidgets/QApplication>
#include <QTextCodec>
#include"main_window.h"

int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	QApplication a(argc, argv);
	main_window surface(argc, argv);
	surface.show();
	return a.exec();
}






