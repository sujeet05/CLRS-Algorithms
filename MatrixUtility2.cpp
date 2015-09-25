#include<iostream>

using namespace std;
typedef int** arr;
class Matrix
{
	public:
			Matrix(int _row,int _col, arr _mat);
			~Matrix(){}
			Matrix(const Matrix& _matrix);
			const Matrix operator*(const Matrix & _matrix);
			const Matrix operator+(const Matrix & _matrix);
			const Matrix operator=(const Matrix & _matrix);
			inline int no_of_rows()const {return m_row;}
			inline int no_of_cols()const {return m_col;}
			ostream& operator << (ostream& os);
			void print();
	private:
		int m_row;
		int m_col;
		arr mat;
};

Matrix::Matrix(int _row,int _col, arr _mat = NULL):m_row(_row),m_col(_col),mat(_mat)
{
		if(!mat) {
			mat = new int* [m_row];
			for(int i=0; i < m_row; ++i)
				mat[i] = new int[m_col];
		}
}

const Matrix Matrix::operator*(const Matrix & _matrix)
{
	Matrix _return(m_row,_matrix.no_of_cols());
	return _return;
}

const Matrix Matrix::operator+(const Matrix & _matrix)
{
	Matrix _return(m_row, m_col);
	return _return;
}
//ostream& Matrix::operator<<(ostream& os)
void Matrix::print()
{
		cout<< this << endl;
	for(int i=0;i<no_of_cols();++i){
		for(int j=0;j<no_of_rows();++j){
				cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	//return os;
}
void func(int*  b) {
		cout << b <<" " <<  b[0] << endl;
}
int main()
{
//	Matrix matrixObj(2,2);

	int a[2]= { 3,4};	
	cout << a <<"  " <<  a[0] << endl;
	func( (int* )a );
//	Matrix m2(2,2,(int **) a);

//	matrixObj.print();
//	m2.print();
	return 0;
}
