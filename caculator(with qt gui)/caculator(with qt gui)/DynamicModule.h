#pragma once
#include <QLayout> 
#include<qlabel.h>
#include<qlineedit.h>
#include<qlayout.h>
#include<qlayoutitem.h>

//dynamic module of linear eqaution
class DynamicModule
{
public:
	DynamicModule();
	QHBoxLayout* set(int, QWidget *);
	QLabel * names;
	QLineEdit * elements;
	QHBoxLayout HBoxLayout;
	~DynamicModule();
};

