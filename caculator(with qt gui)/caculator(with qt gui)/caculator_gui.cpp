#include "caculator_gui.h"
#include <QtCore/QDebug>
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
	char c,c_next = 0;

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
	if (row == 0) row = 1;//�ǳ���������
	
	/*set matrix*/
	Matrix m(row,first_column ,false);
	//std::cout << m.getRow() << " " << m.getColumn() << std::endl;
	for (unsigned int i = 0,j = 0,amount = 0; i < length && j < length; i++)
	{
		if (amount == row * first_column) break;
		c = str.at(i);
		if(i != length - 1)
			c_next = str.at(i + 1);
		if (!number_judge(c))
		{
			j++;
			continue;
		}
		else if(i == length - 1 || (number_judge(c) && !number_judge(c_next)))//mark the end of the number 
		//else
		{
			amount++;
			tmp = "";
			for (; j < i + 1; j++)
			{
				c = str.at(j);
				tmp += c;
			}
			double num = AnalyticFormula::getNum(tmp);
			m.setData((amount - 1)/m.getRow(), (amount - 1) % m.getRow() , num);
		}
	}
	return m;
}

/*digit is the decimal digits*/
/*BUG!!!!!!!!!!!!!!!!!!!!!*/
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
	ui.use_float->setCheckable(true);
	ui.use_float->setChecked(true);
	float_use = true;
	DecimalDigit = 2;
	ui.decimals_num->setRange(0, 6);  // ��Χ
	ui.decimals_num->setValue(2);//��ǰֵ
	ui.decimals_num->setWrapping(false);  // ������ѭ��
	//set default states
}

void caculator_gui::push_add_button()
{
	std::cout << "the digits is " << DecimalDigit<<std::endl;
	std::cout << "the status of dicimal:" << float_use << std::endl;
	bool type = true;
	QString strA,strB;
	strA = ui.MatrixA->toPlainText();
	strB = ui.MatrixB->toPlainText();
	if (strA == "" || strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix a, b;
	a = QString_to_matrix(strA,type);
	b = QString_to_matrix(strB,type);
	//return;
	/////////////////////////////////////////////////////////
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
	strA = "ans of A + B =\n" + Matrix_to_QString(a, DecimalDigit ) +"\n";
	ui.output_test_browser->setPlainText(strA);//����
}

void caculator_gui::push_subtract_button()
{
	bool type = true;
	QString strA, strB;
	strA = ui.MatrixA->toPlainText();
	strB = ui.MatrixB->toPlainText();
	if (strA == "" || strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
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
	strA = "ans of A - B =\n" + Matrix_to_QString(a, DecimalDigit) + "\n";
	ui.output_test_browser->setPlainText(strA);//����
}

void caculator_gui::push_multiply_button()
{
	bool type = true;
	QString strA, strB;
	strA = ui.MatrixA->toPlainText();
	strB = ui.MatrixB->toPlainText();
	if (strA == "" || strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
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
	strA = "ans of A * B =\n" + Matrix_to_QString(a, DecimalDigit) +"\n";
	ui.output_test_browser->setPlainText(strA);//����

}
void caculator_gui::push_swap_button()
{
	QString strA, strB,tmp;
	strA = ui.MatrixA->toPlainText();
	strB = ui.MatrixB->toPlainText();
	if (strA == "" || strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
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
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix a;
	a = QString_to_matrix(strA, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	if (!a.square())
	{
		QMessageBox::about(NULL, "WRONG", "�Ƿ���");
		return;
	}
	double det = a.determinant();
	strA = "determination of matrix A is \n" + QString::number(det, 10, DecimalDigit) +"\n";
	ui.output_test_browser->setPlainText(strA);//����
}
void caculator_gui::push_detB_button()
{
	bool type = true;
	QString strB;
	strB = ui.MatrixB->toPlainText();
	if (strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix B;
	B = QString_to_matrix(strB, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	if (!B.square())
	{
		QMessageBox::about(NULL, "WRONG", "�Ƿ���");
		return;
	}
	double det = B.determinant();
	strB = "determination of matrix B is \n" + QString::number(det, 10, DecimalDigit) + "\n";
	ui.output_test_browser->setPlainText(strB);//����
}

void caculator_gui::push_invA_button()
{
	bool type = true;
	QString strA;
	strA = ui.MatrixA->toPlainText();
	if (strA == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix a;
	a = QString_to_matrix(strA, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	if (!a.square())
	{
		QMessageBox::about(NULL, "WRONG", "�Ƿ���");
		return;
	}

	int det = a.determinant();
	if (fabs(det) < math::eps)
	{
		QMessageBox::about(NULL, "WRONG", "����ʽΪ�㣬û�������");
		return;
	}
	Matrix inv_matrix = a.inverse_matrix();
	strA = "the invert matrix of matrix A is \n" + Matrix_to_QString(inv_matrix, DecimalDigit) + "\n";
	ui.output_test_browser->setPlainText(strA);//����
}
void caculator_gui::push_invB_button()
{
	bool type = true;
	QString strB;
	strB = ui.MatrixA->toPlainText();
	if (strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix B;
	B = QString_to_matrix(strB, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	if (!B.square())
	{
		QMessageBox::about(NULL, "WRONG", "�Ƿ���");
		return;
	}

	int det = B.determinant();
	if (fabs(det) < math::eps)
	{
		QMessageBox::about(NULL, "WRONG", "����ʽΪ�㣬û�������");
		return;
	}
	Matrix inv_matrix = B.inverse_matrix();
	strB = "the invert matrix of matrix B is \n" + Matrix_to_QString(inv_matrix, DecimalDigit) + "\n";
	ui.output_test_browser->setPlainText(strB);//����
}
void caculator_gui::push_tranA_button()//get transport matrix
{
	bool type = true;
	QString strA;
	strA = ui.MatrixA->toPlainText();
	if (strA == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix a;
	a = QString_to_matrix(strA, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	Matrix transport_matrix = a.Transposition();
	strA = "the transition matrix of matrix A is \n" + Matrix_to_QString(transport_matrix, DecimalDigit) +"\n";
	ui.output_test_browser->setPlainText(strA);//set
}
void caculator_gui::push_tranB_button()
{
	bool type = true;
	QString strB;
	strB = ui.MatrixB->toPlainText();
	if (strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix B;
	B = QString_to_matrix(strB, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	Matrix transport_matrix = B.Transposition();
	strB = "the transition matrix of matrix B is \n" + Matrix_to_QString(transport_matrix, DecimalDigit);
	ui.output_test_browser->setPlainText(strB);//set
}
void caculator_gui::push_rankA_button()
{
	bool type = true;
	QString strA;
	strA = ui.MatrixA->toPlainText();
	if (strA == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix a;
	a = QString_to_matrix(strA, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	unsigned int rank = a.getRank();
	//strA = "�������Ϊ\n" + QString::number(rank, 10, 0);
	strA = "the rank of the matrix A is\n" + QString::number(rank, 10, 0) + "\n";
	ui.output_test_browser->setPlainText(strA);//set
}

void caculator_gui::push_rankB_button()
{
	bool type = true;
	QString strB;
	strB = ui.MatrixB->toPlainText();
	if (strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix B;
	B = QString_to_matrix(strB, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	unsigned int rank = B.getRank();
	strB = "the rank of the matrix B is\n" + QString::number(rank, 10, 0) + "\n";
	ui.output_test_browser->setPlainText(strB);//set
}
void caculator_gui::push_getSimplestA_button()
{
	bool type = true;
	QString strA;
	strA = ui.MatrixA->toPlainText();
	if (strA == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix a;
	a = QString_to_matrix(strA, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	Matrix m;
	unsigned int time, rank;
	a.getSimplest(m, time, rank);
	//strA = "��������������Ϊ\n" + ;
	strA = "the simplest matrix of matrix A is \n" + Matrix_to_QString(m, DecimalDigit) + "\n";
	ui.output_test_browser->setPlainText(strA);//set
}
void caculator_gui::push_getSimplestB_button()
{
	bool type = true;
	QString strB;
	strB = ui.MatrixB->toPlainText();
	if (strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix B;
	B = QString_to_matrix(strB, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	Matrix m;
	unsigned int time, rank;
	B.getSimplest(m, time, rank);
	//strA = "��������������Ϊ\n" + ;
	strB = "the simplest matrix of matrix A is \n" + Matrix_to_QString(m, DecimalDigit) + "\n";
	ui.output_test_browser->setPlainText(strB);//set
}


/*NO BUILD PART*/
void caculator_gui::push_FeatureVectorA_button()
{
	QMessageBox::about(NULL, "WRONG", "NO BUILD");
	//�ӿڻ�û��ƺ�....�ȿ�������Ľӿ���д
	bool type = true;
	QString strA;
	strA = ui.MatrixA->toPlainText();
	if (strA == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	Matrix a;
	a = QString_to_matrix(strA, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	Matrix vector,value;
	////strA = "��������������Ϊ\n" + ;
	//strA = Matrix_to_QString(m, 2);
	//ui.output_test_browser->setPlainText(strA);//set
}
void caculator_gui::push_FeatureVectorB_button()
{
	QMessageBox::about(NULL, "WRONG", "NO BUILD");
}
void caculator_gui::push_FeatureValueA_button()
{
	QMessageBox::about(NULL, "WRONG", "NO BUILD");
}
void caculator_gui::push_FeatureValueB_button()
{
	QMessageBox::about(NULL, "WRONG", "NO BUILD");
}


void caculator_gui::push_NumMulA_button()
{
	bool type = true;
	QString strA,strNum;
	strA = ui.MatrixA->toPlainText();
	strNum = ui.lineEdit_NumA->text();
	if (strA == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	if (strNum == "")
	{
		QMessageBox::about(NULL, "WRONG", "����������");
		return;
	}
	double num = strNum.toDouble();//�ܴ�������...
	Matrix a;
	a = QString_to_matrix(strA, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	Matrix m;
	m = a * num;
	//strA = "����Ϊ\n" + ;
	strA = Matrix_to_QString(m, DecimalDigit);
	ui.output_test_browser->setPlainText(strA);//set
}
void caculator_gui::push_NumMulB_button()
{
	bool type = true;
	QString strB, strNum;
	strB = ui.MatrixB->toPlainText();
	strNum = ui.lineEdit_NumB->text();
	if (strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	if (strNum == "")
	{
		QMessageBox::about(NULL, "WRONG", "����������");
		return;
	}
	double num = strNum.toDouble();//�ܴ�������...
	Matrix B;
	B = QString_to_matrix(strB, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	Matrix m;
	m = B * num;
	//strA = "����Ϊ\n" + ;
	strB = Matrix_to_QString(m, DecimalDigit);
	ui.output_test_browser->setPlainText(strB);//set
}
void caculator_gui::push_timeA_button()
{
	bool type = true;
	QString strA, strTime;
	strA = ui.MatrixA->toPlainText();
	strTime = ui.lineEdit_TimeA->text();
	if (strA == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	if (strTime == "")
	{
		QMessageBox::about(NULL, "WRONG", "����������");
		return;
	}
	int num = strTime.toInt();
	if (num <= 0)
	{
		QMessageBox::about(NULL, "WRONG", "���������0������");
		return;
	}
	Matrix A;
	A = QString_to_matrix(strA, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	Matrix m;
	m = A.FastPower(num);
	//strA = "����Ϊ\n" + ;
	strA = Matrix_to_QString(m, DecimalDigit);
	ui.output_test_browser->setPlainText(strA);//set
}
void caculator_gui::push_timeB_button()
{
	bool type = true;
	QString strB, strTime;
	strB = ui.MatrixA->toPlainText();
	strTime = ui.lineEdit_TimeB->text();
	if (strB == "")
	{
		QMessageBox::about(NULL, "WRONG", "���������");
		return;
	}
	if (strTime == "")
	{
		QMessageBox::about(NULL, "WRONG", "����������");
		return;
	}
	int num = strTime.toInt();
	if (num <= 0)
	{
		QMessageBox::about(NULL, "WRONG", "���������0������");
		return;
	}
	Matrix B;
	B = QString_to_matrix(strB, type);
	if (type == false)
	{
		QMessageBox::about(NULL, "WRONG", "������������");
		return;
	}
	Matrix m;
	m = B.FastPower(num);
	//strA = "����Ϊ\n" + ;
	strB = Matrix_to_QString(m, DecimalDigit);
	ui.output_test_browser->setPlainText(strB);//set
}

void caculator_gui::change_state_use_float()
{
	if (ui.use_float->isChecked())
	{
		float_use = true;
		DecimalDigit = ui.decimals_num->value();//get dicimal digit
	}
	else
	{
		float_use = false;
		DecimalDigit = 0;
		//use fraction (has not built yet)
	}
}