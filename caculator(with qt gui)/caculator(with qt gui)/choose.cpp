#include "choose.h"
#include"poly_gui.h"
#include"QT_OpenGL.h"
choose::choose(QWidget *parent, poly_gui *p, QT_OpenGL *Opengl_gui)
	: QWidget(parent),poly(p),opengl_gui(Opengl_gui)
{
	ui.setupUi(this);
}
void choose::push_2D_painter()
{
	poly->show();
}
void choose::push_poly()
{
	opengl_gui->show();
}
