#include"DynamicModule.h"
#include<qstring.h>
#include<iostream>
DynamicModule::DynamicModule()
{
#ifdef DEBUG
	std::cout << "use DynamicModule construct\n";
#endif // DEBUG

	names = nullptr;
	elements = nullptr;
}
QHBoxLayout* DynamicModule::set(int amount)//amount must >= 1
{
#ifdef DEBUG
	std::cout << "use set function\n";
#endif // DEBUG
	int maxwidth = 25;
	QString name;
	if (names != nullptr)
	{
		delete names;
	}
	if (elements != nullptr)
	{
		delete elements;
	}
	names = new QLabel[amount];
	elements = new QLineEdit[amount + 1];

	for (unsigned int i = 0; i < amount; i++)
	{
		name = "x" + QString::number(i + 1);

		if (i != amount - 1)
		{
			name += "+";
		}
		else name += "=";
		names[i].setText(name);
		names[i].setFixedWidth(30);
		elements[i].setMaximumWidth(maxwidth);
	}
	elements[amount].setMaximumWidth(maxwidth);

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
#ifdef DEBUG
	std::cout << "use DynamicModule destruct\n";
#endif // DEBUG
	if (names != nullptr)
	{
		delete names;
	}
	if (elements != nullptr)
	{
		delete elements;
	}
}
