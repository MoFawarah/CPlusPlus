
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib> 

#include "MyLibrary.h";
#include "MyInputLibrary.h";
using namespace std;
using namespace MyLib;
using namespace MyInputLibrary;

#pragma region ReadText
string ReadText(string msg)
{
	string line = "";
	cout << msg << ": ";
	getline(cin, line);
	return line;
}
#pragma endregion

#pragma region SwapTwoNumbers
void SwapTwoNumbers(int& A, int& B)
{
	int temp = A;
	A = B;
	B = temp;
}
#pragma endregion

#pragma region MultiplicationFrom1To10
void TaableHeader()
{
	cout << "\n\n\t\t\tMultiplication Table From 1 To 10\n" << endl;
	cout << "\t";
	for (int i = 1; i <= 10; i++)
	{
		cout << i <<"\t";
	}
	cout <<"\n__________________________________________________________________________________\n" << endl;
}

string ColumnSeperator(int i)
{
	if (i < 10)
		return "   |";
	else
		return "  |";
}
void MultiplicationFrom1To10()
{
	TaableHeader();
	for (int i = 1; i <= 10; i++)
	{
		cout << " " << i << ColumnSeperator(i) << "\t";
		for (int j = 1; j <= 10; j++)
		{
			cout << i * j <<"\t";
		}

		cout << endl;
	}

}
#pragma endregion

#pragma region PrimeNumbersInRange
enum enPrime{Prime = 1, NotPrime = 2};
int ReadNumber(string msg)
{
	int N = 0;
	cout << msg + ": ";
	cin >> N;
	while (N < 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Input! Please enter positive numbers only. ";
		cout << "Enter a Number Again: ";
		cin >> N;
	}
  
	return N;
}

float ReadAnyNumber(string msg)
{
	float N = 0;

	cout << msg + ": ";
	cin >> N;
	

	return N;
}

int BitwiseTwoNumbers(int num1, int num2)
{
	return (num1 & num2);
}
enPrime CheckPrime(int number)
{
	for (int i=2; i <= round(number / 2); i++)
	{
		if (number % i == 0 )
			return enPrime::NotPrime;
	}
	return enPrime::Prime;
}

void PrintPrimeFrom1ToN(int number)
{
	cout << "Prime Numbers From 1 to " + to_string(number) << endl;

	for (int i = 1; i <= number; i++)
	{
		if (CheckPrime(i) == enPrime::Prime)
			cout << i << endl;
	}
}
#pragma endregion

#pragma region PerfectOrNot
enum enPerfect { Perfect, NotPerfect };
enPerfect IsPerfectNumber(int number)
{
	int sum = 0;
	for (int i = 1; i <= round(number / 2); i++)
	{
		if (number % i == 0)
		{
			sum += i;
		}
	}
	return sum == number ? enPerfect::Perfect : enPerfect::NotPerfect;
}

void PrintPerfectNumber(int number)
{
	if (IsPerfectNumber(number) == enPerfect::Perfect)
		cout << number << " Is Perfect";
	else
		cout << number << " Is Not Perfect";

}

#pragma endregion

#pragma region PerfectNumbersFrom1ToN
void PrintPerfectNumberRange(int number)
{
	cout << "Perfect Numbers from 1 to " << number << " are: " << endl;
	for (int i = 1; i <= number;i++)
	{
		if (IsPerfectNumber(i) == enPerfect::Perfect)
			cout << i << " Is Perfect" << endl;
	}

}
#pragma endregion

#pragma region PrintNumberReversedMethod1
string ConvertNumToString(int number)
{
	return to_string(number);
}
void PrintNumInReverse(string num)
{
	for (int i = num.length() - 1; i >= 0; i--)
	{
		cout << num[i] << " ";
	}
}
#pragma endregion

#pragma region PrintNumberReversedMethod2
void PrintNumInReverse2(int number)
{
	do
	{
		int remainder = 0;
		remainder = number % 10;
		number /= 10;
		cout << remainder;
	} while (number > 0);
}
#pragma endregion

#pragma region SumOfDigits01
vector<int> ConvertNumberToArray(int number)
{
	vector<int> arr;
	do
	{
		int counter = 0;
		int remainder = 0;
		remainder = number % 10;
		number /= 10;
		arr.push_back (remainder);
		counter++;
	} while (number > 0);

	return arr;
}

int SumOfVector(vector<int> arr) 
{
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
	}

	return sum;
}

void PrintValue(int value)
{
	cout << value;
}
#pragma endregion

#pragma region SumOfDigits02
int SumOfDigits(int number)
{
	int sum = 0;
	do
	{
		int remainder = 0;
		remainder = number % 10;
		number /= 10;
		sum += remainder;
	} while (number > 0);

	return sum;
}
#pragma endregion

#pragma region ReverseNumber
int ReverseNumber(int number)
{
	int remainder = 0, reversedNumber = 0;
	do
	{
		remainder = number % 10;
		number /= 10;
		reversedNumber = reversedNumber * 10 + remainder ;
	} while (number > 0);
	return reversedNumber;
}
#pragma endregion

#pragma region DigitFrequency
int CheckFrequency(int digit, int number)
{
	int remainder = 0, counter = 0;
	do
	{
		remainder = number % 10;
		number /= 10;
		
		if (remainder == digit)
			counter++;
	} while (number > 0);
	return counter;
}
#pragma endregion

#pragma region AllDigitFrequency

void PrintFrequency(int number, int freq)
{
	cout << number << " has been repeated " << freq << endl;
}
void CheckAllFrequency(int number)
{
	for (int i = 0; i <= 9; i++)
	{
	   int Freq = CheckFrequency(i, number);
	   if (Freq > 0)
	   {
		   PrintFrequency(i, Freq);
	   }
	}
}
#pragma endregion

#pragma region PalindromeOrNot
enum enPalindromeOrNot { Palindrome, NotPalindrome };
enPalindromeOrNot PalindromeOrNot(int number)
{
	int reversedNumber = ReverseNumber(number);
	if (number == reversedNumber)
		return enPalindromeOrNot::Palindrome;
	else 
		return enPalindromeOrNot::NotPalindrome;
}

void PrintPalindromeOrNot(enPalindromeOrNot result)
{
	if (result == enPalindromeOrNot::Palindrome)
		cout << "Number is Palindrome";
	else
		cout << "Number is Not Palindrome";
}
#pragma endregion

#pragma region InvertedPattern
void InvertedPattern(int number)
{

	for (int i = number; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i << " ";
		}
		cout << endl;
	}

}
#pragma endregion

#pragma region NumberPattern
void NumberPattern(int number)
{
	for (int i = 1; i <= number; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			cout << i;
		}
		cout << endl;
	}

}
#pragma endregion

#pragma region InvertedLetterPattern
void InvertedLetterPattern(int number)
{
	int counter = 0;
	int originalNumber = number;
	for (int i = (65 + number - 1); i >= 65; i--)
	{
		counter++;
		for (int j = 1; j <= number; j++)
		{
			cout << char(i);
		}
		cout << endl;
		number--;
		if (counter == originalNumber)
			break;
	}
}
#pragma endregion

#pragma region LetterPattern
void LetterPattern(int number)
{
	int counter = 0;
	int originalNumber = number;
	for (int i = 65; i <= 95; i++)
	{
		counter++;
		for (int j =1; j <= counter; j++)
		{
			cout << char(i);
		}
		cout << endl;
		number--;
		if (counter == originalNumber)
			break;
	}
}
#pragma endregion

#pragma region LetterPatternMethod2

void LetterPattern02(int number)
{
	for (int i = 0; i < number; i++)
	{
		char currentChar = 'A' + i; 
		for (int j = 0; j <= i; j++) 
		{
			cout << currentChar; 
		}
		cout << endl; 
	}
}
#pragma endregion

#pragma region PrintWordsFromAAATOZZZ
void PrintWordsFromAAATOZZZ()
{
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				cout << char(i) << char(j) << char(k) << endl;
			}
			
		}
	}

}
#pragma endregion

#pragma region GuessThreeLetterPassword3TriesOnly
void GuessThreeLetterPassword3TriesOnly()
{
	int tries = 0;
	string password = "AAA";
	string userPassword = "";
	do
	{
		tries++;
		cout << "Guess the Three-Letter Password: ";
		cin >>  userPassword;

	} while (password != userPassword);
	cout << "Paswword is: " << password << endl;
	cout << "Found after: " << tries << " tries" << endl;

}
#pragma endregion

#pragma region GuessThreeLetterPassword

string ReadWord(string msg)
{
	string word = "";
	cout << msg + ": ";
	cin >> word;
	return word;    
}
bool GuessThreeLetterPassword02(string userInput)
{
	string password = userInput;
	transform(password.begin(), password.end(), password.begin(), ::toupper);

	int counter = 0;
   
	for (int i = 65; i <= 90; i++)
	{
   
		for (int j = 65; j <= 90; j++)
		{
 
			for (int k = 65; k <= 90; k++)
			{
  
				counter++;
				string computerGuess = "";
				computerGuess += char(i);
				computerGuess += char(j);
				computerGuess += char(k);
				cout << "Computer Guess[" <<counter <<"] " << computerGuess << endl;

				if (computerGuess == password)
				{
					cout << "Password is: " << password << endl;
					cout << "Found After: " << counter << " tries." << endl;
					return true;
				}
	   
			}

		}
	}

	cout << "Password not found!" << endl;
	return 0;

}
#pragma endregion

#pragma region encryption
string EncryptText(string text, short encryptionKey)
{
	for (int i = 0; i <= text.length(); i++)
	{
		text[i] = char(int(text[i]) + encryptionKey);
	}
	return text;

}

string DecryptText(string text, short encryptionKey)
{
	for (int i = 0; i <= text.length(); i++)
	{
		text[i] = char(int(text[i]) - encryptionKey);
	}
	return text;

}
#pragma endregion

#pragma region RandomNumberRange
int RandomNumberRange(int lower, int upper)
{
		int randomNumber = rand() % (upper - lower + 1) + lower;
		return randomNumber;
}
#pragma endregion

#pragma region RandomThing
enum enCharType{SmallLetter, CapitalLetter, SpecialCharacter, Digit};
char GetRandomChar(enCharType chType)
{
	switch (chType)
	{
	case SmallLetter:
		return char(RandomNumberRange(97, 122));
		break;
	case CapitalLetter:
		return char(RandomNumberRange(65, 90));
		break;                                
	case SpecialCharacter:                     
		return char(RandomNumberRange(33, 47));
		break;                                 
	case Digit:                                
		return char(RandomNumberRange(48, 57));
		break;
	default:
		return NULL;
		break;
	}
}
#pragma endregion

#pragma region GenerateKeys

string GenerateWord(enCharType charType, short length)
{
	string word = "";
	for (int i = 1; i <= length; i++)
	{
		word += GetRandomChar(charType);
	}
	return word;
}
string GenerateKey()
{
	string key = "";
	for (int i = 0; i < 4; i++)
	{
	   key += GenerateWord(CapitalLetter, 4);
	   if (i != 3)
		   key += "-";
	}

	return key;
   
}
void GenerateKeys(short howManyKeys)
{
	for (int i = 0; i < howManyKeys; i++)
	{
		cout << GenerateKey() << endl;
	}
}

void GenerateKeysInArray(short howManyKeys, string arr[100])
{
	for (int i = 0; i < howManyKeys; i++)
	{
		arr[i] = GenerateKey();
	}
}


#pragma endregion

#pragma region CheckRepeatedElementInArray

void ReadArray(int arr[], short &length)
{
	cout << "Enter Number Of Elements: ";
	cin >> length;
	
	cout << "Enter Array Elements: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "Element[" << i+1 << "]: ";
		cin >> arr[i];
	}

}

void PrintArray(int arr[100], short length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void PrintArrayString(string arr[100], short length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}
}
int TimesRepeatedInArray(int arr[100], short arrayLength, short numberToCheck)
{
	int counter = 0;
	for (int i = 0; i < arrayLength; i++)
	{
		if (arr[i] == numberToCheck)
			counter++;
	}
	return counter;

}
#pragma endregion

#pragma region FillArrayRandonly
void FillArrayRandonly(int arr[100], int &length)
{
	length = ReadNumber("Please Enter Number Of Array Elements");

	int Lower = ReadAnyNumber("Please enter the lower number");
	int Upper = ReadAnyNumber("Please enter the upper number");

	for (int i = 0; i <= length - 1; i++)
	{
		arr[i] = RandomNumberRange(Lower, Upper);
	}
}
#pragma endregion

#pragma region MaxOfRandomArray
int MaxOfRandomArray(int arr[100], int length)
{
	int maxNum = arr[0];
	for (int i = 0; i <= length - 1; i++)
	{
		if (arr[i] > maxNum)
			maxNum = arr[i];
	}
	return maxNum;
}
#pragma endregion

#pragma region MinOfRandomArray
int MinOfRandomArray(int arr[100], int length)
{
	int minNum = arr[0];
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < minNum)
			minNum = arr[i];
	}

	return minNum;
}
#pragma endregion

#pragma region SumOfRandomArray
int SumOfRandomArray(int arr[100], int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
	}

	return sum;
}
#pragma endregion

#pragma region AvgOfRandomArray
float AvgOfRandomArray(int arr[100], int length)
{
	return (float)SumOfRandomArray(arr, length) / length;
}
#pragma endregion

#pragma region CopyArray
void CopyArray(int arr1[100], int arr2[100], int length)
{
	for (int i = 0; i < length; i++)
	{
		arr2[i] = arr1[i];
	}
}
#pragma endregion

#pragma region CopyArrayInReverse
void CopyArrayInReverse(int arr1[100], int arr2[100], int length)
{
	for (int i = 0; i < length; i++)
	{
		arr2[i] = arr1[length-1-i];
	}
}
#pragma endregion

#pragma region CopyArrayOnlyPrime
void CopyArrayOnlyPrime(int arr1[100], int arr2[100], int length1, int& length2)
{
	int counter = 0;
	for (int i = 0; i < length1; i++)
	{
		if (CheckPrime(arr1[i]) == enPrime::Prime)
		{
			arr2[counter] = arr1[i];
			counter++;
		}
	}
	length2 = counter;
}
#pragma endregion

#pragma region SumOfTwoArraysIntoNewOne
void SumOfTwoArraysIntoNewOne(int arr1[100], int arr2[100], int arr3[100], int length)
{
	for (int i = 0; i < length; i++)
	{
		arr3[i] = arr1[i] + arr2[i];
	}
}
#pragma endregion

#pragma region ReadArrayFrom1ToN
void ReadArrayFrom1ToN(int N, int arr[100])
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = i+1;
	}
}

void ShuffleArray(int arr[100], int N)
{
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		//int randomIndex = RandomNumberRange(i, N - 1);
		SwapTwoNumbers(arr[RandomNumberRange(1,N)-1], arr[RandomNumberRange(1, N) - 1]);
	}

}
#pragma endregion

#pragma region FindIndex
int FindIndex(int arr[100], int length, int &lookingFor)
{
   lookingFor = ReadNumber("Please Enter a Number To Search For");

	for (int i = 0; i < length; i++)
	{
		if (arr[i] == lookingFor)
		{
			return i;
		}
	}

	return -1;
}
#pragma endregion

#pragma region FindIndexBool

bool FindIndexBool(int arr[100], int length, int &lookingFor)
{
	return FindIndex(arr, length, lookingFor) != -1;
}
#pragma endregion

#pragma region DynamicArrayFilling

void AddArrayElement(int number, int arr[100], int &arr2Length)
{
	arr2Length++;
	arr[arr2Length - 1] = number;
}
void DynamicArrayFilling(int arr[100], int &arrLength)
{
	bool next = true;
	do
	{
		AddArrayElement(ReadNumber("Please Enter a Number"), arr, arrLength);
	   
		cout << "Do you want to add more number [0]:No, [1]:Yes? ";
		cin >> next;

	} while (next);

}
#pragma endregion

#pragma region CopyArray02
void CopyArrayUsingAddArrayElement(int arr[100], int arr2[100], int length1, int &length2)
{
	for (int i = 0; i < length1; i++)
		AddArrayElement(arr[i], arr2, length2);
}
#pragma endregion

#pragma region CopyOddUsingAddArrayElement
void CopyOddUsingAddArrayElement(int arr[100], int arr2[100], int length1, int &length2)
{
	for (int i = 0; i < length1; i++)
	{
		if (arr[i]%2 != 0)
			AddArrayElement(arr[i], arr2, length2);
	}
}
#pragma endregion

#pragma region CopyOnlyDistinct
void CopyOnlyDistinct(int arr1[100],int arr2[100], int &length1, int &length2)
{
	for (int i = 0; i < length1; i++)
	{
		if (TimesRepeatedInArray(arr1, length1, arr1[i]) == 1)
			AddArrayElement(arr1[i], arr2, length2);
	}
	
}


#pragma endregion

#pragma region CheckTwoNumberEqual
bool CheckTwoNumberEqual(int number1, int number2)
{
	if (number1 == number2)
		return true;

	return false;

}

bool CheckPalindromeArray(int arr1[100], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (arr1[i] != arr1[length-1-i])
			return false;
	}

	return true;

}
#pragma endregion

#pragma region CountOddsInArray
int CountOddsInArray(int arr[], int length)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] % 2 != 0)
			counter++;
	}
	return counter;
}
#pragma endregion

#pragma region CountEvensInArray
int CountEvensInArray(int arr[], int length)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] % 2 == 0)
			counter++;
	}
	return counter;
}
#pragma endregion

#pragma region CountPositivesInArray
int CountPositivesInArray(int arr[], int length)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] >=0)
			counter++;
	}
	return counter;
}
#pragma endregion

#pragma region CountNegativesInArray
int CountNegativesInArray(int arr[], int length)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < 0)
			counter++;
	}
	return counter;
}
#pragma endregion

#pragma region MathFunctions
float MyAbsolute(float number)
{
	if (number < 0)
	return -number;

return number;
}

float GetFractions(float number)
{
	return number - (int)number;
}

int MyRound(double number)
{

	if (MyAbsolute(GetFractions(number)) >= 0.5)
	{
		if (number > 0)
			return int(number) + 1;
		else
			return int(number) - 1;		
	}
	
	return int(number);
}

int MyFloor(float number)
{
	if (number > 0)
		return int(number);

	return int(number) - 1;

}

int MyCeil(float number)
{
	if (number >= 0)
	{
		if (GetFractions(number) == 0)
			return number;
		else
			return int(number) + 1;
	}

	return int(number);
}

float MySqrt(float number)
{
	return pow(number, 0.5);
}


#pragma endregion

#pragma region PrintNumbers-Recursion
void PrintNumbersFromTo(int From, int To)
{
	if (From <= To)
	{
		cout << From << endl;
		PrintNumbersFromTo(From+1, To);
	}
}

void PrintNumbersToFrom(int From, int To)
{
	if (To >= From)
	{
		cout << To << endl;
		PrintNumbersToFrom(From, To - 1);
	}
}

int Power(int number, int power)
{
	if (power == 0)
		return 1;
	
	return number * Power(number, power-1);
	
}
#pragma endregion

void MyFunc() {
	static int Number = 1;
	cout << "Value of Number: " << Number << "\n";

	Number++;

}
int main()
{











	srand((unsigned)time(NULL));
	return 0;






	//MultiplicationFrom1To10();

	//int N = ReadNumber("Please Enter N");
	/*PrintPrimeFrom1ToN(N);*/

 /*   PrintPerfectNumberRange(N);*/

	//PrintNumInReverse(ConvertNumToString(ReadNumber("Please Enter N")));
	//PrintNumInReverse2(ReadNumber("Please Enter N"));

	//PrintValue(SumOfVector(ConvertNumberToArray(ReadNumber("Please Enter N"))));

   /* int numberReversed = ReverseNumber(ReadNumber("Please Enter N"));
	PrintValue(numberReversed);*/
	//PrintValue(CheckAllFrequency(ReadNumber("Please Enter Number")));

	//CheckAllFrequency(ReadNumber("Please Enter Number"));

	//PrintNumInReverse2(ReverseNumber(ReadNumber("Please Enter N")));

	//PrintPalindromeOrNot(PalindromeOrNot(ReadNumber("Please Enter N")));

	//LetterPattern02(ReadNumber("Please Enter a Number"));
	/*GuessThreeLetterPassword02(ReadWord("Please Enter a password"));*/

	//string wordEncrypted = EncryptText(ReadText("Please Enter a password"), 5);
	//cout << "After Encryption: " << wordEncrypted << endl;;

	//string wordEecrypted = DecryptText(wordEncrypted, 5);

	//cout << "After Decryption: " << wordEecrypted << endl;
   
	//srand(time(0)); // Seed the random number generator


  /* cout << RandomNumberRange(1,10);*/

 //   cout << GetRandomChar(enCharType::SmallLetter);
 //   cout<<GetRandomChar(enCharType::CapitalLetter);
 //   cout<<GetRandomChar(enCharType::SpecialCharacter);
	//cout<<GetRandomChar(enCharType::Digit);

	/* GenerateKeys(4); */

	//GenerateKeys(ReadNumber("How many keys do you want to generate? "));


	//int arr[100];
	//short arrayLength = 0;
  
	//ReadArray(arr, arrayLength);

	//short numberToCheck = ReadNumber("What's the number you want to check? ");

	//cout << "Original Array Is: ";
	//PrintArray(arr, arrayLength);

	//cout << numberToCheck << " is repeated ";

	//cout<< TimesRepeatedInArray(arr, arrayLength, numberToCheck) << " times.";
	

  /*  int arr[100];
	int ArrayLength = ReadNumber("Please enter the number of elements");
	FillArrayRandonly(arr, ArrayLength);

	cout << "Array1 Elements: ";
	PrintArray(arr, ArrayLength);*/

	//cout << "Array Elements: ";
	//PrintArray(arr, ArrayLength);
	//cout << "Max: " << MaxOfRandomArray(arr, ArrayLength) << endl;
	//cout << "Min: " << MinOfRandomArray(arr, ArrayLength) << endl;
	//cout << "Sum: " << SumOfRandomArray(arr, ArrayLength) << endl;
	//cout << "Avg: " << AvgOfRandomArray(arr, ArrayLength) << endl;


	//int arr2[100];
	
	//cout << "Array1 Elements: ";
	//PrintArray(arr, ArrayLength);

  /*  CopyArray(arr, arr2, ArrayLength);
	cout << "Array2 Elements: ";
	PrintArray(arr2, ArrayLength);*/

	//CopyArrayOnlyPrime(arr, arr2, ArrayLength, length2);
	//cout << "Array2 Only Prime Elements: ";
	//PrintArray(arr2, length2);

	//CopyArrayInReverse(arr, arr2, ArrayLength);

	//cout << "Array2 Elements In Reverse: ";
	//PrintArray(arr2, ArrayLength);

   


 /*   int arr1[100];
	int ArrayLength = ReadNumber("What's the array length you want");
	FillArrayRandonly(arr1, ArrayLength);   

	cout << "Array One: ";
	PrintArray(arr1, ArrayLength);
	
	int arr2[100];
	FillArrayRandonly(arr2, ArrayLength);

	cout << "Array Two: ";
	PrintArray(arr2, ArrayLength);

	int arr3[100];
	SumOfTwoArraysIntoNewOne(arr1, arr2, arr3, ArrayLength);

	cout << "Array Three: ";
	PrintArray(arr3, ArrayLength);*/

  /*  int arrayBefore[100];
	short N = ReadNumber("Please Enter N");
	ReadArrayFrom1ToN(N, arrayBefore);

	cout << "Array Before Shuffling: ";
	PrintArray(arrayBefore, N);

	ShuffleArray(arrayBefore, N);
	cout << "Array After Shuffling: ";
	PrintArray(arrayBefore, N);*/


 /*   string arrayKeys[100] ;
	short howManyKeys = ReadNumber("How many keys do you want to generate? ");

	GenerateKeysInArray(howManyKeys, arrayKeys);

	PrintArrayString(arrayKeys, howManyKeys);*/

	//int arr[100];
	//int length = ReadNumber("Enter the length of the array");
	//int lookingFor = 0;

	//FillArrayRandonly(arr, length);
	//cout << "Array Eleemnts: ";
	//PrintArray(arr, length);
   /* int numberPosition = FindIndex(arr, length, lookingFor);

	if (numberPosition == -1)
	{
		cout << "The number you're looking for is " << lookingFor << endl;
		cout << "The number is NOT FOUND " << endl;
	}
	else {
		cout << "The number you're looking for is " << lookingFor << endl;;
		cout << "The number found at position " << numberPosition << endl;;
		cout << "The number order is " << numberPosition + 1 << endl;
	}*/


	//bool result = FindIndexBool(arr, length, lookingFor);
	//if (result)
	//{
	//    cout << "The number you're looking for is " << lookingFor << endl;;
	//    cout << "The number is found" << endl;
	//}
	//else {
	//    cout << "The number you're looking for is " << lookingFor << endl;;
	//    cout << "The number is NOT found" << endl;
	//}



//int arr[100], arrLength=0;
//DynamicArrayFilling(arr, arrLength);
//cout << "Array Length: " << arrLength << endl;
//PrintArray(arr, arrLength);

//int arr1[100];
//int length1 = 0, length2 = 0;
//FillArrayRandonly(arr1, length1);
//
//cout << "Array 01 Elements: "<< endl;
//PrintArray(arr1, length1);
//
//int arr2[100];
//CopyOnlyDistinct(arr1, arr2, length1, length2);
//
//cout << "Array 02 Elements: " << endl;
//PrintArray(arr2, length2);
//
//int arr[100];
//int length = 0;
//FillArrayRandonly(arr, length);
//
//PrintArray(arr, length);
//
//
//cout << CountNegativesInArray(arr, length) << endl;



}





