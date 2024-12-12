#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

#pragma region PrintName
string ReadName()
{
	string name;
	cout << "Please enter your name: " << endl;
	getline(cin, name);
	return name;
}

void DisplayName(string name)
{
	cout << "Your name is: " << name << endl;;
}
#pragma endregion

#pragma region EvenOrOdd

enum enEvenOdd { Even, Odd };

float ReadNumber()
{
	cout << "Please Enter a number: ";
	float num;
	cin >> num;

	return num;
}

enEvenOdd CheckOddEven(int num)
{
	if (num % 2 == 0)
	{
		return enEvenOdd::Even;
	}
	else
	{
		return enEvenOdd::Odd;
	}
}

void PrintEvenOrOdd(enEvenOdd num)
{
	if (num == enEvenOdd::Even)
	{
		cout << "The Number is Even" << endl;
	}
	else
	{
		cout << "The Number is Odd" << endl;
	}

}
#pragma endregion

#pragma region DriverLicense

struct stUserInfo
{
	short userAge;
	bool hasDriverLicense;
	bool hasRecommendation;
};
stUserInfo ReadUserInfo()
{
	stUserInfo user;
	cout << "Please Enter your age: ";
	cin >> user.userAge;

	cout << "Do you have a Driver License? (1/0): ";
	cin >> user.hasDriverLicense;

	cout << "Do you have Recommendation? (1/0): ";
	cin >> user.hasRecommendation;

	return user;

}

bool IsAccepted(stUserInfo user)
{
	return (user.hasRecommendation || (user.userAge > 21 && user.hasDriverLicense == true));
}

void PrintDriverResult(stUserInfo user)
{
	if (IsAccepted(user))
	{
		cout << "Hired" << endl;
	}
	else
	{
		cout << "Rejected" << endl;
	}
}
#pragma endregion

#pragma region PrintFullName
struct stUserFullName
{
	string firstName;
	string lastName;
};
stUserFullName ReadFullName()
{
	stUserFullName userName;
	cout << "Please enter your first name: ";
	cin >> userName.firstName;
	cout << "Please enter your last name: ";
	cin >> userName.lastName;
	return userName;
}

string MergeFullName(stUserFullName userName)
{
	return userName.firstName + " " + userName.lastName;
}

void DisplayFullName(string fullName)
{
	cout << "Your Full Name Is: " << fullName << endl;
}
#pragma endregion

#pragma region PrintHalfNumber
float CalculateHalfNum(float num)
{
	return num / 2;
}

void PrintHalfNum(float num)
{
	cout << "Half of " + to_string(num) + " is " + to_string (CalculateHalfNum(num)) << endl;
}
#pragma endregion

#pragma region PassOrFail
enum enResult { Pass, Fail };
int ReadMark()
{
	int mark;
	cout << "Please enter your mark: ";
	cin >> mark;
	return mark;
}
enResult CheckMark(int mark)
{
	if (mark >= 50)
		return enResult::Pass;

	else
		return enResult::Fail;
}

void PrintExamResult(int mark)
{
	if (CheckMark(mark) == enResult::Pass)
		cout << "Pass" << endl;
	else
		cout << "Fail" << endl;
}
#pragma endregion

#pragma region SumOfThreeNumbers
void ReadThreeNumbers(int arr[])
{
	cout << "Please enter 3 numbers respectively: " << endl;
	cin >> arr[0] >> arr[1] >> arr[2];
}

int SumOfThreeNumbers(int arr[])
{
	return arr[0] + arr[1] + arr[2];
}

void PrintValue(float value)
{
	cout << value << endl;
}
#pragma endregion

#pragma region AvgOfThreeNumbers
int AvgOfThreeNum(int sum)
{
	return sum / 3;
}
#pragma endregion

#pragma region AvgPassOrFail
enResult CheckAvg(int avg)
{
	if (avg >= 50)
		return enResult::Pass;
	else
		return enResult::Fail;
}
void PrintResult(enResult result)
{
	if (result == enResult::Pass? cout << "Pass" << endl : cout << "Fail" << endl);		
}
#pragma endregion

#pragma region MaxOfArray
void ReadArrayNums(int arr[100], int& numOfNumbers)
{
	cout << "How many numbers do you wanna compare? ";

	do
	{
		cout << "Enter a positive integer: ";
		cin >> numOfNumbers;
	} while (numOfNumbers <= 0);


	cout << "Please enter " + to_string(numOfNumbers) + " numbers respectively : " << endl;
	for (int i = 0; i < numOfNumbers; i++)
	{
		cin >> arr[i];
	}
}
bool FindMaxOfArray(int arr[100], int &maxValue, int numOfNumbers)
{
	maxValue = arr[0];
	for (int i = 0; i < numOfNumbers; i++)
	{
		if (arr[i] == arr[i+1] && i != (numOfNumbers-1))
			return true;
		
		if (arr[i] > maxValue)
		{
			maxValue = arr[i];
		}
	}

	return false;
	
}

void PrintMaxOfArray(int maxValue, bool areEqual)
{
	if (areEqual)
		cout << "Both numbers are equal." << endl;
	else
		cout << "The maximum number is: " << maxValue << endl;
}
#pragma endregion

#pragma region SwapTwoNum

void ReadTwoNum(float &num1, float& num2)
{
	cout << "Please enter 2 numbers: " << endl;
	cin >> num1 >> num2;
}
void SwapTwoNumbers(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void PrintSwappedNumbers(int num1, int num2)
{
	cout << "Original Numbers: " << num1 << ", " << num2 << endl;
	SwapTwoNumbers(num1, num2);
	cout << "Swapped Numbers: " << num1 << ", " << num2 << endl;
}
#pragma endregion

#pragma region RectangleArea
float RectangleArea(float w, float h)
{
	return (float) (w * h);
}
#pragma endregion

#pragma region RectangleAreaDiagonal
float RectangleAreaDiagonal(float sideLength, float diagonal)
{
	return sideLength * sqrt(pow(diagonal, 2) - pow(sideLength, 2));
}
#pragma endregion

#pragma region TriangleArea
float TriangleArea(float base, float height)
{
	return 0.5*base*height;
}
#pragma endregion

#pragma region CircleArea
void ReadNumber(float &num)
{
	cout << "Enter a number: ";
	cin >> num;
}
float CircleArea(float radius)
{
	const float pi = 3.14159265;
	return pi *pow(radius,2);
}
#pragma endregion

#pragma region CircleAreaWithDiameter

float CircleAreaWithDiameter(float diameter)
{
	const float pi = 3.14159265;
	return (pi * pow(diameter, 2))/4;
}
#pragma endregion

#pragma region CircleInscribedInSquare
float CircleInscribedInSquare(float squareSide)
{
	const float pi = 3.14159265;
	return (pi * pow(squareSide, 2)) / 4;
}
#pragma endregion

#pragma region ValidateAge
int ReadAge()
{
	int age;
	cout << "Enter your age: ";
	cin >> age;
	return age;
}
bool ValidateAgeInRange(int age, int from, int to)
{
	return (age>=from && age<=to);
}

void PrintValidationResult(bool result)
{
	cout << (result ? "Valid" : "Invalid") << " age" << endl;
}
#pragma endregion

#pragma region ReadAgeOnlyBetweenRange
bool ReadUntilAgeBetween(int from, int to)
{
	int age;
	do
	{
		age = ReadAge();
	} while (!ValidateAgeInRange(age, from, to));

   return true;
}
#pragma endregion

#pragma region ReadFrom1ToN
vector<int> ArrayFrom1ToN(int n)
{
	vector<int> arr(n);
	for (int i = 0; i <= n-1; i++)
	{
		arr[i] = i + 1;
	}
	return arr;
}

void PrintFrom1ToN(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << to_string(arr[i]) + " ";
	}
}
#pragma endregion

#pragma region ReadFromNTo1
vector<int> ArrayFromNTo1(int n)
{
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = n - i;
	}
	return arr;
}

#pragma endregion

#pragma region CalTotalPiggyBank
struct PiggyBank {
	int Pennies, Nickles, Dimes, Quarter, Dollar;
};
PiggyBank ReadPiggyBankContent()
{
	PiggyBank piggyBank;
	cin >> piggyBank.Pennies
	>> piggyBank.Nickles
	>> piggyBank.Dimes
	>> piggyBank.Quarter
	>> piggyBank.Dollar;

	return piggyBank;
}
float CalTotalPiggyBank(PiggyBank piggyBank)
{
	float result = 0;
	result = piggyBank.Pennies + piggyBank.Nickles * 5 + piggyBank.Dimes * 10 + piggyBank.Quarter * 25 + piggyBank.Dollar * 100;
	return result;	
}
#pragma endregion

#pragma region OddSumOfArray
int OddSum(vector<int> arr)
{
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] % 2 != 0)
			sum += arr[i];
	}
	return sum;
}
#pragma endregion

#pragma region EvenSumOfArray
int EvenSum(vector<int> arr)
{
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] % 2 == 0)
			sum += arr[i];
	}
	return sum;
}
#pragma endregion

#pragma region FactorialOfN
int FactorialOfN(int N)
{
	int factorial = 1;
	for (int i = 1; i <= N; i++)
	{
		factorial *= i;
	}
	return factorial;
}
#pragma endregion

#pragma region Calculator
enum enOperationType {Add = '+', Subtract = '-', Multiplly = '*', Division = '/'};
struct stCalculator
{
	float num1, num2;
	char operatorSymbol;
};
enOperationType ReadCalcType()
{
	char OP = '+';
	cout << "Please enter operation type: ";
	cin >> OP;

	return (enOperationType)OP;
}
float Calculation(int num1, int num2, enOperationType OP)
{
	switch (OP)
	{
	case enOperationType::Add:
		return num1 + num2;
	case enOperationType::Subtract:
		return num1 - num2;
	case enOperationType:: Multiplly:
		return num1 * num2;
	case enOperationType::Division:
		return num1 / num2;
	default:
		return num1 + num2;
	}
}
#pragma endregion

#pragma region PrimeOrNot
enum enPrime {Prime, NotPrime};
float EnterNumberWithMsg(string Msg)
{
	float number;
	do
	{
		cout << Msg + ": ";
		cin >> number;

	} while (number < 0);

	return number;
}

enPrime CheckPrime(int number)
{
	for (int i = 2; i <= round(number / 2); i++)
	{
		if (number%i == 0)
		{
			return enPrime::NotPrime;
		}
		
    }
	return enPrime::Prime;
}

void PrintNumberType(enPrime number)
{
	if (number == enPrime::Prime)
		cout << "Prime" << endl;
	else 
		cout << "Not Prime" << endl;
}
#pragma endregion

#pragma region RemainderBack
float CalculateRemainderBack(float CashPaid, float TotalBill)
{
	return CashPaid - TotalBill;
}
#pragma endregion

#pragma region ServiceFee
float CalTotalBill(float serviceFee, float salesTax, float totalBill)
{
	 totalBill += totalBill * (serviceFee / 100);
	return totalBill + totalBill * (salesTax / 100);
}
#pragma endregion

int main()
{
	//DisplayName(ReadName());
	//PrintEvenOrOdd(CheckOddEven(ReadNumber()));
	
	//PrintDriverResult(ReadUserInfo());

	//DisplayFullName(MergeFullName(ReadFullName()));

	//PrintHalfNum(ReadNumber());

	//PrintExamResult(ReadMark());
	//int arr [] = { 0, 0, 0 };
	//ReadThreeNumbers(arr);

	//PrintResult(CheckAvg(AvgOfThreeNum((SumOfThreeNumbers(arr)))));

	/*int arr[100], maxValue, numOfNumbers;
	ReadArrayNums(arr, numOfNumbers);
	bool areEqual = FindMaxOfArray(arr, maxValue, numOfNumbers);
	
	PrintMaxOfArray(maxValue, areEqual);*/

	/*int num1, num2;*/
	//ReadTwoNum(num1, num2);
	//PrintSwappedNumbers(num1, num2);

	//float num1, num2;
	//ReadTwoNum(num1, num2);
	//PrintValue(RectangleArea(num1, num2));

	/*float num1, num2;
	ReadTwoNum(num1, num2);
	PrintValue(RectangleAreaDiagonal(num1, num2));*/

	/*float num1, num2;
	ReadTwoNum(num1, num2);
	PrintValue(TriangleArea(num1, num2));*/

	/*float num;
	ReadNumber(num);
	PrintValue(CircleArea(num));*/
	
	//float num;
	//ReadNumber(num);
	//PrintValue(CircleAreaWithDiameter(num));
	
	/*float num;
	ReadNumber(num);
	PrintValue(CircleInscribedInSquare(num));*/

	//PrintValidationResult(ValidateAgeInRange(ReadAge(), 18, 45));
	
	//PrintValidationResult(ReadUntilAgeBetween(18, 45));

	/*PrintFrom1ToN(ArrayFromNTo1(ReadNumber()));*/

	/*PrintValue(OddSum(ArrayFrom1ToN(ReadNumber())));

	PrintValue(EvenSum(ArrayFrom1ToN(ReadNumber())));*/
	/*PrintValue(FactorialOfN(ReadNumber()));	*/

	
	//float totalPennies = CalTotalPiggyBank(ReadPiggyBankContent());
	//cout << "Total value in the piggy bank in pennies: $" << totalPennies << endl;
	//cout << "Total value in the piggy bank in dollar: $" << totalPennies/100 << endl;

	//float num1 = ReadNumber();
	//float num2 = ReadNumber();
	//enOperationType OP = ReadCalcType();	
	//PrintValue(Calculation(num1, num2, OP));


	/*int x = EnterNumberWithMsg("Please Enter Positive Number");
	enPrime XX = CheckPrime(x);
	PrintNumberType(XX);*/


	/*float cashPaid = EnterNumberWithMsg("Please Enter Cash Paid");
	float totalBill = EnterNumberWithMsg("Please Enter Total Bill");
	PrintValue(CalculateRemainderBack(cashPaid, totalBill));*/

	float totalBill = EnterNumberWithMsg("Please Enter Total Bill");
	float serviceFee = EnterNumberWithMsg("Please Enter Service Fee");
	float tax = EnterNumberWithMsg("Please Enter Tax");
	PrintValue(CalTotalBill(serviceFee, tax, totalBill));



}

