#include"source.h"
#include"Matrix.h"
#include"LinearEqaution.h"


/*judge if the linear equations is compatible and the number of solution*/
int solveLinearEqaution::Compatible(const Matrix& CoefficientMatrix, const Matrix& AugmentedMatrix)
{
	std::cout << "what ???";
	int CRank = CoefficientMatrix.getRank();
	std::cout << "what";
	int ARank = AugmentedMatrix.getRank();
	std::cout << "e,m";
	if (CRank == ARank && CRank == CoefficientMatrix.getRow())//only one solution
	{
		return 1;
	}
	if (CRank == ARank && CRank < CoefficientMatrix.getRow())//more than one solution
	{
		return 2;
	}
	if (CRank != ARank)//it's not compatible
	{
		return 0;
	}
	else
	{
		std::cout << "???";
		return 0;
	}
}

/*num is the amount of solution .
If there is only one solution, return solution matrix */
Matrix solveLinearEqaution::getSolution(const Matrix& A, const Matrix& b,int & num)//solve Ax = b
{
	//A is Coefficient Matrix
	Matrix AugmentedMatrix(A.getRow(), A.getColumn() + 1,false);
	std::cout <<"A row is "<< A.getRow() << "\n";
	std::cout << "A column is " << A.getColumn() << "\n";
	A.show();
	b.show();
	for (int i = 0; i < A.getRow(); i++)
	{
		//std::cout << "5\n";
		for (int j = 0; j <= A.getColumn(); j++)
		{

			if (j == A.getColumn())
			{
				//std::cout << "3\n";
				AugmentedMatrix.setData(i, j, b.getData(i, 0));
			}
			else
			{
				//std::cout << "4\n";
				AugmentedMatrix.setData(i, j, A.getData(i,j));
			}
		}
	}
	std::cout << "1\n";
	num = 0;
	num = Compatible(A,AugmentedMatrix);
	std::cout << "compatible wrong \n";
	if (num == 0)
	{
		Matrix m(1, 1, 0);
		return m;// 0 solution
	}

	/* only one solution
	the answer is A^-1 *b 
	x[i] = solution.data[i][0];
	*/
	else if (num == 1)
	{
		//Matrix solution(A.getRow(), 1, false);
		A.inverse_matrix().show();
		Matrix solution = A.inverse_matrix() * b;
		return solution;
	}
	else //if (num == 2)
	{
		Matrix m(1, 1, 0);
		return m;//Countless more sulution
	}
}