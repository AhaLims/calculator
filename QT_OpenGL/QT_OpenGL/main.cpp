#include "QT_OpenGL.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QT_OpenGL w;
	w.show();
	return a.exec();
}
