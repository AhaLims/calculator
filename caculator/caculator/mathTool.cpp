#include"source.h"
#include"Matrix.h"

/*judge if the linear equations is compatible and the number of solution*/
int Compatible(const Matrix CoefficientMatrix, const Matrix AugmentedMatrix)
{
	int CRank = CoefficientMatrix.getRank();
	int ARank = AugmentedMatrix.getRank();
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
}
Matrix getSolution(const Matrix A, const Matrix b)//solve Ax = b
{
	Matrix AugmentedMatrix(A.getRow(), A.getColumn() + 1,false);
	for (int i = 0; i < A.getRow(); i++)
	{
		for (int j = 0; j < A.getColumn() + 1; j++)
		{
			if (j == A.getColumn())
			{
				AugmentedMatrix.setData(i, j, b.getData(i, 0));
			}
			else
			{
				AugmentedMatrix.setData(i, j, A.getData(i,j));
			}
		}
	}
	int num = Compatible();
	if (num == 0)
	{
		Matrix m(1, 1, 0);
		return m;// 0 solution
	}
	else if (num == 1)
	{
		Matrix solution(A.getRow(), 1, false);
		solution = A.inverse_matrix() *b;
		return solution;
	}
	else if (num == 2)
	{
		;//Countless more sulution
		//use Causs to get ?
	}
}