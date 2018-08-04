#include "caculator_gui.h"
//#include <QtCore/QDebug>
#include<QtCore/QString>
#include"Matrix.h"
#include"source.h"
#include <QtWidgets/QMessageBox>
Matrix caculator_gui::QString_to_matrix(const QString& qstr ,bool &type)const
{//ͨ��ʲô����ȥ���������һ������
	string str;
	Matrix m;
	str = qstr.toStdString();
	unsigned int length,row = 0, column = 0;
	length = str.length();
	for (unsigned int i = 0,j = 0; i < length,j<length; i++)
	{
		
		if (str.at(i) == ' '  ||str.at == ',')
		{
			j++;
			if(i != j)
			{ 

			}
		}
		else if (str.at(i) == '/')
		{

		}
		else if (str.at(i) == '.')
		{

		}
		else if (str.at(i) == '\n')
		{
			row++;
		}
		else
		{
			type = status::WrongInput;
			return m;
		}

	}
}
QString caculator_gui::Matrix_to_QString(const Matrix& m)const
{
	QString qstr;
	int row = m.getRow();
	int column = m.getColumn();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			//qstr = qstr.toStdString();
		}
		qstr = qstr + "\n";
	}
}
caculator_gui::caculator_gui(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void caculator_gui::push_add_button()
{
	bool type = true;
	QString strA,strB;
	strA = ui.MatrixA->toPlainText();
	strB = ui.MatrixB->toPlainText();
	Matrix a, b;
	a = QString_to_matrix(strA,type);
	b = QString_to_matrix(strB,type);

	/*juudge*/
	if (type == status::WrongInput)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	else if (a.getRow() != b.getRow() || a.getColumn() != b.getColumn())
	{
		QMessageBox::about(NULL, "WRONG", "�����С��һ");
		return;
	}

	a = a + b;
	strA = "ans of A + B =\n" + Matrix_to_QString(a);
	ui.output_test_browser->setPlainText(strA);//����
}

void caculator_gui::push_subtract_button()
{
	bool type = true;
	QString strA, strB;
	strA = ui.MatrixA->toPlainText();
	strB = ui.MatrixB->toPlainText();
	Matrix a, b;
	a = QString_to_matrix(strA,type);
	b = QString_to_matrix(strB,type);

	/*judge*/
	if (type == status::WrongInput)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	else if (a.getRow() != b.getRow() || a.getColumn() != b.getColumn())
	{
		QMessageBox::about(NULL, "WRONG", "�����С��һ");
		return;
	}

	a = a - b;
	strA = "ans of A - B =\n" + Matrix_to_QString(a);
	ui.output_test_browser->setPlainText(strA);//����
}
void caculator_gui::push_multiply_button()
{
	bool type = true;
	QString strA, strB;
	strA = ui.MatrixA->toPlainText();
	strB = ui.MatrixB->toPlainText();
	Matrix a, b;
	a = QString_to_matrix(strA,type);
	b = QString_to_matrix(strB,type);

	/*judge*/
	if (type == status::WrongInput)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	else if (!a.checkMul(b))
	{
		QMessageBox::about(NULL, "WRONG", "��һ���������ĿӦ�õ��ڵڶ�����ֱ����Ŀ");
		return;
	}
	a = a * b;
	strA = "ans of A * B =\n" + Matrix_to_QString(a);
	ui.output_test_browser->setPlainText(strA);//����

}
void caculator_gui::push_swap_button()
{
	QString strA, strB,tmp;
	strA = ui.MatrixA->toPlainText();
	strB = ui.MatrixB->toPlainText();
	ui.MatrixA->setPlainText(strB);
	ui.MatrixB->setPlainText(strA);
	return;
}