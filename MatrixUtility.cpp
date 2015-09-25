#include<iostream>

using namespace std;
typedef int *arr[];
class Matrix
{
	public:
			Matrix(int _row,int _col,int *_matrix);
			~Matrix(){}
			Matrix(const Matrix& _matrix);
			const Matrix operator*(const Matrix & _matrix);
			const Matrix operator+(const Matrix & _matrix);
			inline int no_of_rows()const {return m_row;}
			inline int no_of_cols()const {return m_col;}
			void PrintMatrix();
	private:
		int m_row;
		int m_col;
		int *m_matrix[];
//		arr* m1[];
};

Matrix::Matrix(int _row,int _col,int *_matrix=NULL):m_row(_row),m_col(_col)
{
}

const Matrix Matrix::operator*(const Matrix & _matrix)
{
	Matrix _return(m_row,_matrix.no_of_cols());
	return _return;
}

const Matrix Matrix::operator+(const Matrix & _matrix)
{
	Matrix _return(m_row,_matrix.no_of_cols());
	return _return;
}
void Matrix::PrintMatrix()
{
	for(int i=0;i<no_of_cols();++i)
	for(int j=0;j<no_of_rows();++j)
}
int main()
{
	Matrix matrixObj(2,2);
	return 0;
}
