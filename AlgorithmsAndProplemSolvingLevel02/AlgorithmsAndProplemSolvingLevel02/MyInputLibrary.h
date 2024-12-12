#pragma once
#include <iostream>;
using namespace std;

namespace MyInputLibrary
{
	float readNumber()
	{
		float number;
		cout << "Enter a number: ";
		cin >> number;
		return number;
	}
}
