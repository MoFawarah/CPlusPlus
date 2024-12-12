

#include <iostream>
#include<vector>
using namespace std;

struct stUser
{
	string name;
	float salary;
};

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main()
{







	vector<int> num{ 1, 2, 3, 4, 5 };
	// declare iterator
	vector<int>::iterator iter;
	// use iterator with for loop
	for (iter = num.begin(); iter != num.end();iter++)
	{
		cout << *iter << " ";
	}






	//int x = 100;
	//int y = -77;

	//cout << "X Before Swapping: " << x << endl;
	//cout << "Y Before Swapping: " << y << endl;

	//cout << endl;

	//swap(&x, &y);

	//cout << "X After Swapping: " << x << endl;
	//cout << "Y After Swapping: " << y << endl;

	//float x = 10.88;
	//void *ptr;
	//ptr = &x;
	//cout << *(static_cast<float*>(ptr)) << endl;
	//cout << *(reinterpret_cast<float*>(ptr)) << endl;

	/*stUser user, *userPtr = &user;
	user.name = "Mohammad Fawareh";
	user.salary = 7008;

	cout << user.name << endl;
	cout << user.salary << endl;


	cout << userPtr->name << endl;
	cout << userPtr->salary << endl;*/






	//int* ptrX;
	//// declare a float pointer
	//float* ptrY;
	//// dynamically allocate memory
	//ptrX = new int;
	//ptrY = new float;
	//// assigning value to the memory
	//*ptrX = 45;
	//*ptrY = 58.35f;
	//cout << *ptrX << endl;
	//cout << *ptrY << endl;
	//// deallocate the memory
	//delete ptrX;
	//delete ptrY;
	//return 0;
}


	



