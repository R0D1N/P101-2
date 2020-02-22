#include <iostream>

using namespace std;

int main()
{
    int rows = 4;
    int columns = 4;
    double **matrix = new double*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int sum = 0;
    int rows_counter = 0;

    for (size_t j = 0; j < columns; j++)
    {
        if (matrix[rows_counter][j] == 0)
        {
            sum += j+1;
        }
        rows_counter++;
    }

    cout << endl << sum << endl;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}