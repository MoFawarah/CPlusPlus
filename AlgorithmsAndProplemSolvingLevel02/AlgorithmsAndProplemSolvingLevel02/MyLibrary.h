#pragma once
#include <iostream>
using namespace std;

namespace MyLib
{
	void sayHello()
	{
		cout << "Hello!" << endl;
	}

	int sumTwoNumbers(int num1, int num2)
	{
		return num1 + num2;
	}
}