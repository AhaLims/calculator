#include"DynamicModule.h"
#include<qstring.h>
#include<iostream>
#include"LinearEquation_gui.h"
DynamicModule::DynamicModule()
{
	names = nullptr;
	elements = nullptr;
}
QHBoxLayout* DynamicModule::set(int amount, QWidget * parent)//amount must >= 1
{
	int maxwidth = 25;
	QString name;
	if (names != nullptr)
	{
		delete[] names;
	}
	if (elements != nullptr)
	{
		delete[] elements;
	}

	names = new QLabel[amount + 5];
	elements = new QLineEdit[amount + 5];
	for (unsigned int i = 0; i < amount; i++)
	{
		name = "x" + QString::number(i + 1);

		if (i != amount - 1)
		{
			name += "+";
		}
		else name += "=";
		names[i].setParent(parent);
		elements[i].setParent(parent);
		names[i].setText(name);
		names[i].setFixedWidth(30);
		elements[i].setMaximumWidth(maxwidth);
	}
	elements[amount].setMaximumWidth(maxwidth);
	elements[amount].setParent(parent);

	/*set in the HBLayout*/
	for (unsigned int i = 0; i < amount; i++)
	{
		HBoxLayout.addWidget(&(elements[i]));
		HBoxLayout.addWidget(&(names[i]));
	}
	HBoxLayout.addWidget(&(elements[amount]));
	return (&HBoxLayout);
}

DynamicModule::~DynamicModule()
{
	std::cout << "use DynamicModule destruct\n";
	if (names != nullptr)
	{
		delete[] names;
	}
	if (elements != nullptr)
	{
		delete[] elements;
	}
}
