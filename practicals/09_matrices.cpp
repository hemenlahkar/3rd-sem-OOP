#include<iostream>
using namespace std;

class Matrix {
public:
	int row, column, **matrix;
	Matrix()
	{
		row = column = 0;
		matrix = nullptr;
	}
	Matrix(int r, int c)
	{
		row = r, column = c;
		if(r == 0 || c == 0)
			matrix = nullptr;
		else
		{
			matrix = new int*[r];
			for(int i = 0; i < r; i++)
				matrix[i] = new int[c];
		}
	}
	~Matrix()
	{
		for(int i = 0; i < column; i++)
			delete matrix[i];
		delete matrix;
	}
	void getData()
	{
		if (row == 0 || column == 0)
		{
			cout << "Enter dimension of the matrix in MxN format: ";
			cin >> row;
			cin.ignore();
			cin >> column;
			matrix = new int*[row];
			for(int i = 0; i < row; i++)
				matrix[i] = new int[column];
		}
		for(int i = 0; i < row; i++)
			for(int j = 0; j < column; j++)
			{
				cout << "Enter element (" << i + 1 << ", " << j + 1 << "): ";
				cin >> matrix[i][j];
			}
	}
	void display()
	{
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < column; j++)
				cout << matrix[i][j] << "  ";
			cout << endl;
		}
		cout << endl;
	}
	friend Matrix multiply(Matrix &l, Matrix &m);
	friend Matrix add(Matrix &l, Matrix &m);
	
	friend Matrix operator + (Matrix &A, Matrix &B)
	{
		return add(A, B);
	}
	friend Matrix operator * (Matrix &A, Matrix &B)
	{
		return multiply(A, B);
	}

};

Matrix add(Matrix &l, Matrix &m)
{
	if(l.row != m.row || l.column != m.column)
	{
		cout << "Cannot add: Dimensions of the matrices don't match" << endl;
		return Matrix(0, 0);
	}
	Matrix *n = new Matrix(l.column, l.row);

	for(int i = 0; i < l.row; i++)
		for(int j = 0; j < l.column; j++)
			n->matrix[i][j] = l.matrix[i][j] + m.matrix[i][j];
	return *n;
}
Matrix multiply(Matrix &l, Matrix &m)
{
	if(l.column != m.row)
	{
		cout << "Cannot multiply: no. of column of first matrix must equal no. of rows of second matrix" << endl;
		return Matrix(0, 0);
	}
	Matrix *n = new Matrix(l.row, m.column);
	for(int i = 0; i < l.row; i++)
		for(int j = 0; j < m.column; j++)
			for(int k = 0; k < l.column; k++)
				n->matrix[i][j] += l.matrix[i][k] * m.matrix[k][j];
	return *n;
}
int main()
{
	Matrix A, B;
	A.getData();
	B.getData();
	Matrix C = A + B;
	Matrix D = A * B;
	cout << "Sum: " << endl;
	C.display();
	cout << "Product: " << endl;
	D.display();
	return 0;
}


