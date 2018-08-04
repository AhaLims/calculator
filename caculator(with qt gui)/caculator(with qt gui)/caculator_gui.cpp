#include "caculator_gui.h"
//#include <QtCore/QDebug>
#include<QtCore/QString>
#include"Matrix.h"
#include"AnalyticFormula.h"
#include"source.h"
#include <QtWidgets/QMessageBox>

bool caculator_gui::number_judge(const char c)const//can judge float and fraction
{
	if (	c == '/'
		|| (c >= '0' && c <= '9')
		||  c == '\\'
		||  c == '.')
		return true;
	else return false;
}

Matrix caculator_gui::get_random_matrix()
{
	Matrix m(4, 4, false);
	return m;
}
///////////////////////////////////////////////////////////////////need to be test
/*manage string to get matrix*/
Matrix caculator_gui::QString_to_matrix(const QString& qstr ,bool &type)const
{
	string str,tmp;
	str = qstr.toStdString();
	unsigned int length,row = 0, column = 0 ,first_column = 0;
	length = str.length();
	char c;

	/*get row and column and check at the same time*/
	for (unsigned int i = 0; i < length; i++)
	{
		c = str.at(i);
		if (c == ' '  || c == ',')
		{
			continue;
			
		}
		else if ( number_judge(c) )
		{
			if (i == 0 || (i != 0 && !number_judge( str.at(i - 1) ))//the signal of number start
				)
			{
				column++;
			}
			tmp += str.at(i);
			//maybe wrong 
			//if (i == length - 1 || !number_judge(str.at(i + 1)))//the signal of number end
			//{

			//}
		}
		else if (c == '\n' && row == 0)//when in the first row ,set first column
		{
			row++;
			first_column = column;
			column = 0;
			
		}
		else if (c == '\n')
		{
			row++;
			if (column != first_column)//error input
			{
				type = status::WrongInput;
				return Matrix(1,1,0);//emmmmm no useful
			}
			else
				column = 0;//reset
		}
	}
	if (str.at(length - 1) != '\n')row++;
	if (row == 0) row = 1;//非常糟糕的输入
	std::cout << row << std::endl << first_column << std::endl;
	//return Matrix(1, 1, true);
	
	/*set matrix*/
	Matrix m(row,first_column ,false);
	for (unsigned int i = 0,j = 0,amount = 0; i < length,j < length; i++)
	{
		c = str.at(i);
		if (!number_judge(c))
		{
			j++;
			continue;
		}
		else
		{
			amount++;
			tmp = "";
			for (; j < i + 1; j++)
				tmp = tmp + c;
			double num = AnalyticFormula::getNum(tmp);
			std::cout << num << std::endl;
			m.setData(amount/row, (amount - 1) % first_column , num);
		}
	}
	//return Matrix(1, 1, true);
	return m;
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
	return qstr;
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
		QMessageBox::about(NULL, "WRONG", "矩阵输入有误");
		return;
	}
	else if (a.getRow() != b.getRow() || a.getColumn() != b.getColumn())
	{
		QMessageBox::about(NULL, "WRONG", "矩阵大小不一");
		return;
	}

	a = a + b;
	strA = "ans of A + B =\n" + Matrix_to_QString(a);
	ui.output_test_browser->setPlainText(strA);//设置
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
		QMessageBox::about(NULL, "WRONG", "矩阵输入有误");
		return;
	}
	else if (a.getRow() != b.getRow() || a.getColumn() != b.getColumn())
	{
		QMessageBox::about(NULL, "WRONG", "矩阵大小不一");
		return;
	}

	a = a - b;
	strA = "ans of A - B =\n" + Matrix_to_QString(a);
	ui.output_test_browser->setPlainText(strA);//设置
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
		QMessageBox::about(NULL, "WRONG", "矩阵输入有误");
		return;
	}
	else if (!a.checkMul(b))
	{
		QMessageBox::about(NULL, "WRONG", "第一矩阵横行数目应该等于第二矩阵直行数目");
		return;
	}
	a = a * b;
	strA = "ans of A * B =\n" + Matrix_to_QString(a);
	ui.output_test_browser->setPlainText(strA);//设置

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
void caculator_gui::push_randomA_button()
{
	Matrix A = get_random_matrix();
	QString qstr = Matrix_to_QString(A);
	ui.MatrixA->setPlainText(qstr);
	return;
}
void caculator_gui::push_randomB_button()
{
	Matrix B = get_random_matrix();
	QString qstr = Matrix_to_QString(B);
	ui.MatrixB->setPlainText(qstr);
	return;
}
void caculator_gui::push_clearA_button()
{
	ui.MatrixA->clear();
}

void caculator_gui::push_clearB_button()
{
	ui.MatrixB->clear();
}
void caculator_gui::push_detA_button()
{

}
void caculator_gui::push_detB_button()
{

}