#pragma once
class clsInputValidate
{
	//has only static functions
public:

	static bool isNumberBetween(int number, int from, int to)
	{
		if (number >= from && number <= to)
			return true;

		return false;
	}

	static bool isNumberBetween(double number, double from, double to)
	{
		if (number >= from && number <= to)
			return true;

		return false;
	}
};

