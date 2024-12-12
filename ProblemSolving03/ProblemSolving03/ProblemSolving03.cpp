
#include <iostream>
#include <string>
#include<cctype>
#include<random>
#include <iomanip>
using namespace std;

int RowSum(int arr[3][3], int rowNumber, int cols)
{
	int sum = 0;
	for (int j = 0; j < cols; j++)
	{
		sum += arr[rowNumber][j];
	}
	return sum;

}

void PrintEachMatrixRowSum(int arr[3][3], int rows, int cols)
{
	cout << "\nThe following is the sum of each row in the matrix:\n\n";
	for (int i = 0; i < rows; i++)
	{
		cout << "Sum of Row " << i + 1 << " = " << RowSum(arr, i, cols) << endl;
	}

}

int GetRandomNumberRanged(int lower = 1, int upper = 100)
{
	return rand() % (upper - lower + 1) + lower;
}

void Fill3X3RandomMatrix(int arr[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = GetRandomNumberRanged(1,5);
		}

	}
}

void PrintMatrix(int arr[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
		   cout << setw(3) << arr[i][j] << "   ";
		}
		cout << endl;

	}
}
int main()
{
	srand(unsigned(time(NULL)));

	int arr[3][3];

	Fill3X3RandomMatrix(arr, 3, 3);
	PrintMatrix(arr, 3, 3);

	
	PrintEachMatrixRowSum(arr, 3, 3);	
	
	system("pause>0");

	return 0;
}

