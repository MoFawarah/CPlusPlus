
#include <iostream>
#include <string>
#include<cctype>
#include<random>
#include <iomanip>
using namespace std;


int GetRandomNumberRanged(int lower = 1, int upper = 100)
{
	return rand() % (upper - lower + 1) + lower;
}

int ColSum(int arr[3][3], int colNumber, int rows)
{
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		sum += arr[i][colNumber];

	}
	return sum;

}

int RowSum(int arr[3][3], int rowNumber, int cols)
{
	int sum = 0;
	for (int j = 0; j < cols; j++)
	{
		sum += arr[rowNumber][j];
	}
	return sum;

}

void AddSumRowToNewArray(int arrSum[3], int matrix[3][3], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		arrSum[i] = RowSum(matrix, i, cols);
	}
}

void AddSumColToNewArray(int arrSumCol[3], int matrix[3][3], int rows, int cols)
{
	for (int i = 0; i < cols; i++)
	{
		arrSumCol[i] = ColSum(matrix, i, rows);
	}
}

void PrintEachMatrixColSum(int arr[3][3], int rows, int cols)
{
	cout << "\nThe following is the sum of each col in the matrix:\n\n";
	
		for (int j = 0; j < cols ;j++)
		{
			cout << "Sum of Col " << j + 1 << " = " << ColSum(arr, j, rows) << endl;
		}
	

}

void PrintEachMatrixRowSum(int arr[3][3], int rows, int cols)
{
	cout << "\nThe following is the sum of each row in the matrix:\n\n";
	for (int i = 0; i < rows; i++)
	{
		cout << "Sum of Row " << i + 1 << " = " << RowSum(arr, i, cols) << endl;
	}

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

void FillMatrixWithOrderedNumbers(int arr[3][3], int rows, int cols)
{
	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			counter++;

			arr[i][j] = counter;
		}

	}
}

void TransposedArray(int arr[3][3], int transposedArray[3][3], int rows, int cols)
{
	int col = 0;
	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < cols; j++)
		{
			transposedArray[j][i] = arr[i][j];
			col++;
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

void PrintArray(int arr[3])
{

	for (int j = 0; j < 3; j++)
	{
		cout << setw(3) << arr[j] << "   ";
	}
	cout << endl;


}
int main()
{
	srand(unsigned(time(NULL)));

	int arr[3][3];
	int arrTran[3][3];

	/*Fill3X3RandomMatrix(arr, 3, 3);
	PrintMatrix(arr, 3, 3);*/

	
/*	PrintEachMatrixRowSum(arr, 3, 3);*/	
	
	int arrSumCol[3];



	FillMatrixWithOrderedNumbers(arr, 3, 3);
	PrintMatrix(arr, 3, 3);


	TransposedArray(arr, arrTran, 3, 3);
	cout << "\n Sum Of Transposed Array: " << endl;
	PrintMatrix(arrTran, 3, 3);




	
	return 0;
}

