#include "caculator_gui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	caculator_gui w;
	w.show(); //创建控制台函数
	return a.exec();
}
//目前测试只输入整数吧...非整数太麻烦了