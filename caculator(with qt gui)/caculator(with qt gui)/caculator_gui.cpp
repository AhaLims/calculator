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
	unsigned int size = 4;
	Matrix m(size, size, false);
	double x = 0; 
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			x = rand() % 10;
			m.setData(i, j, x);
		}
	}
	//m.show();
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

/*digit is the decimal digits*/
QString caculator_gui::Matrix_to_QString(const Matrix& m, const unsigned int& digit)const
{
	QString qstr;
	int row = m.getRow();
	int column = m.getColumn();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			qstr = qstr + QString::number(m.getData(i, j), 10, digit);////////////////////////
			if (j != column - 1) qstr = qstr + " ";
			//qstr = qstr.toStdString();
		}
		if(i != row - 1 )qstr = qstr + "\n";
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
	if (strA == "" || strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "请输入矩阵");
		return;
	}
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
	strA = "ans of A + B =\n" + Matrix_to_QString(a,2);
	ui.output_test_browser->setPlainText(strA);//设置
}

void caculator_gui::push_subtract_button()
{
	bool type = true;
	QString strA, strB;
	strA = ui.MatrixA->toPlainText();
	strB = ui.MatrixB->toPlainText();
	if (strA == "" || strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "请输入矩阵");
		return;
	}
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
	strA = "ans of A - B =\n" + Matrix_to_QString(a,2);
	ui.output_test_browser->setPlainText(strA);//设置
}

void caculator_gui::push_multiply_button()
{
	bool type = true;
	QString strA, strB;
	strA = ui.MatrixA->toPlainText();
	strB = ui.MatrixB->toPlainText();
	if (strA == "" || strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "请输入矩阵");
		return;
	}
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
	strA = "ans of A * B =\n" + Matrix_to_QString(a,2);
	ui.output_test_browser->setPlainText(strA);//设置

}
void caculator_gui::push_swap_button()
{
	QString strA, strB,tmp;
	strA = ui.MatrixA->toPlainText();
	strB = ui.MatrixB->toPlainText();
	if (strA == "" || strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "请输入矩阵");
		return;
	}
	ui.MatrixA->setPlainText(strB);
	ui.MatrixB->setPlainText(strA);
	return;
}
void caculator_gui::push_randomA_button()
{
	Matrix A = get_random_matrix();
	QString qstr = Matrix_to_QString(A,2);
	ui.MatrixA->setPlainText(qstr);
	return;
}
void caculator_gui::push_randomB_button()
{
	Matrix B = get_random_matrix();
	QString qstr = Matrix_to_QString(B,2);
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
	bool type = true;
	QString strA;
	strA = ui.MatrixA->toPlainText();
	if (strA == "" )
	{
		QMessageBox::about(NULL, "WRONG", "请输入矩阵");
		return;
	}
	Matrix a;
	a = QString_to_matrix(strA, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "矩阵输入有误");
		return;
	}
	if (!a.square())
	{
		QMessageBox::about(NULL, "WRONG", "非方阵");
		return;
	}
	double det = a.determinant();
	strA = QString::number(det, 10, 2);
	ui.output_test_browser->setPlainText(strA);//设置
}
void caculator_gui::push_detB_button()
{
	
}

void caculator_gui::push_invA_button()
{
	bool type = true;
	QString strA;
	strA = ui.MatrixA->toPlainText();
	if (strA == "")
	{
		QMessageBox::about(NULL, "WRONG", "请输入矩阵");
		return;
	}
	Matrix a;
	a = QString_to_matrix(strA, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "矩阵输入有误");
		return;
	}
	if (!a.square())
	{
		QMessageBox::about(NULL, "WRONG", "非方阵");
		return;
	}

	int det = a.determinant();
	if (fabs(det) < math::eps)
	{
		QMessageBox::about(NULL, "WRONG", "行列式为零，没有逆矩阵");
		return;
	}
	Matrix inv_matrix = a.inverse_matrix();
	strA = Matrix_to_QString(inv_matrix,2);
	ui.output_test_browser->setPlainText(strA);//设置
}
void caculator_gui::push_invB_button()
{

}
void caculator_gui::push_tranA_button()
{

}
void caculator_gui::push_tranB_button()
{

}
void caculator_gui::push_rankA_button()
{

}
void caculator_gui::push_rankB_button()
{

}
void caculator_gui::push_getSimplestA_button()
{

}
void caculator_gui::push_getSimplestB_button()
{

}
void caculator_gui::push_FeatureVectorA_button()
{

}
void caculator_gui::push_FeatureVectorB_button()
{

}
void caculator_gui::push_FeatureValueA_button()
{

}
void caculator_gui::push_FeatureValueB_button()
{

}
void caculator_gui::push_NumMulA_button()
{

}
void caculator_gui::push_NumMulB_button()
{

}
void caculator_gui::push_timeA_button()
{

}
void caculator_gui::push_timeB_button()
{

}
void caculator_gui::push_timeA_button()
{

}
void caculator_gui::push_timeB_button()
{

}