#include <iostream>

using namespace std;

int sumFunc_1(int rows, int columns, double** matrix) {
	int counter = 0;
	if (rows > columns) {
		counter = columns;
	}
	if (rows < columns) {
		counter = rows;
	}
	else
	counter = columns;

	int sum = 0;

	for (int j = 0; j < counter; j++) {
		if (matrix[j][j] == 0)
		{
			sum += j + 1;
		}
	}

	if (rows < columns) {
		matrix[rows - 1][rows - 1] = sum;
	}

	if (rows > columns) {
		matrix[columns - 1][columns - 1] = sum;
	}
	return sum;
}

//int sumFunc_2(int rows, int columns, double* matrix) {
//	int counter = 0;
//	if (rows > columns) {
//		counter = columns;
//	}
//	if (rows < columns) {
//		counter = rows;
//	}
//	else
//		counter = columns;
//
//	int sum = 0;
//
//	for (int j = 0; j < counter; j++) {
//		if (&matrix[j * columns + j] == 0)
//		{
//			sum += j + 1;
//		}
//	}
//
//	if (rows < columns) {
//		&matrix[rows * columns + ] = sum;
//	}
//
//	if (rows > columns) {
//		&matrix[rows * columns] = sum;
//	}
//	return sum;
//}

//test


void fillArray_1(int rows, int columns, double** matrix) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cin >> matrix[i][j];
		}
	}
}

void fillArray_2(int rows, int columns, double* matrix) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			scanf_s("%g", &matrix[i * columns + j]);
		}
	}
}

void deleteMatrix_1(int rows, double** matrix) {
	for (int i = 0; i < rows; i++) {
		delete matrix[i];
	}
}

void showResult_1(int rows, int columns, double** matrix) {

	int sum = sumFunc_1(rows, columns, matrix);

	cout << endl << "Sum numbers of columns with zero:" << sum << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
};

int main() {
	int rows;
	cout << "Enter count of rows:";
	cin >> rows;

	int columns;
	cout << "Enter count of columns:";
	cin >> columns;


	cout << "First method with two indexes" << endl;

	//Creating array using two indexes
	double** matrix_1 = new double* [rows];
	for (int i = 0; i < rows; i++) {
		matrix_1[i] = new double[columns];
	}
	fillArray_1(rows, columns, matrix_1);
	showResult_1(rows, columns, matrix_1);
	deleteMatrix_1(rows, matrix_1);


	cout << "Second method with one index" << endl;

	//Creating array using one index
	double* matrix_2 = new double[rows * columns];
	fillArray_2(rows, columns, matrix_2);
	
	system("pause");
	return 0;
}