
#include<iostream>

using namespace std;

class clsA
{

public:
	float x;

	clsA(float x)
	{
		this->x = x;
	}

	void Print()
	{
		cout << "The value of x=" << x << endl;
	}

	void func1(clsA &obj)
	{
		obj.x = 300;
	}

	void func2(clsA &obj)
	{
		func1(*this);
	}


};


//object sent by value, any updated will not b reflected
// on the original object
void Fun1(clsA A1)
{

	A1.x = 101.1;
}


//object sent by reference, any updated will be reflected
// on the original object
void Fun2(clsA& A1)
{

	A1.x = 202.2;
}


int main()

{
	clsA A1(70.7);

	cout << "\nA.x before calling function1: \n";
	A1.Print();


	//Pass by value, object will not be afected.
	Fun1(A1);
	cout << "\nA.x after calling function1 ByVal: \n";
	A1.Print();

	//Pass by value, object will be afected.
	Fun2(A1);
	cout << "\nA.x after calling function2 ByRef: \n";
	A1.Print();

	//A1.func1(A1);

	//cout << "\nA.x after calling func1 ByVal: \n";
	//A1.Print();

	A1.func2(A1);

	cout << "\nA.x after calling func2 ByRef: \n";
	A1.Print();



	system("pause>0");

}

