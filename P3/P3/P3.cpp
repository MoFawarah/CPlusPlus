

#include <iostream>
#include <string>
using namespace std;

void Swap(int &Num1, int &Num2) {

	Num1 = Num1 + Num2; 
	Num2 = Num1 - Num2; 
	Num1 = Num1 - Num2; 

}
int main()
{
	int X = 200;
	int Y = 500;

	cout << "X Before Swapping is: " << X << endl;
	cout << "Y Before Swapping is: " << Y << endl;


	Swap(X, Y);

	cout << "X After Swapping is: " << X << endl;
	cout << "Y After Swapping is: " << Y << endl;


}

