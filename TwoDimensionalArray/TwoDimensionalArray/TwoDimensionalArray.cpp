

#include <iostream>
using namespace std;

int main()
{

	int ArrayX[2][3] = { {1,2,3}, {4,5,6} };

	for (int i = 0; i < 2; i++)
	{
		cout << "Column Number " << i+1 << ": " << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << ArrayX[i][j] << " ";
		}
		cout << endl;

		
	}

	int MultiplicationArray[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			MultiplicationArray[i][j] = (i + 1) * (j + 1);
		}
	}

	cout << endl;


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%0*d  ",2, MultiplicationArray[i][j]);
		}
		cout << endl;


	}



	return 0;


}
