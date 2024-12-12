

#include <iostream>
using namespace std;    
#include <cstdio> // For printf
#include <iomanip> 


int main()
{
	char name[] = "John";
	float age = 26.5;
	int Page = 1, TotalPages = 10;
	// print string and int variable
	printf("The page number = %d \n", Page);
	printf("You are in Page %d of %d \n", Page, TotalPages);
	printf("My name is %s and I am %.*f years old \n", name, 3 , age);
	//Width specification
	printf("The page number = %0*d \n", 2, Page);
	printf("The page number = %0*d \n", 3, Page);
	printf("The page number = %0*d \n", 4, Page);
	printf("The page number = %0*d \n", 5, Page);
	int Number1 = 20, Number2 = 30;
	printf("The Result of %d + %d = %d \n", Number1, Number2, Number1 + Number2);


	// stew : Set Width Manipulator

	cout << "---------|--------------------------------|---------|" << endl;
    cout << " Code    |                  Name          |  Mark   |" << endl;
    cout << "---------|--------------------------------|---------|" << endl;

	cout <<setw(9) << "C101" << "|" << setw(32) << "introduction to Programming 1" << "|" << setw(9) << "95" << "|" << endl;
	cout << setw(9) << "C102" << "|" << setw(32) << "Computer Hardware" << "|" << setw(9) << "88" << "|" << endl;
	cout << setw(9) << "C10354243" << "|" << setw(32) << "Network"
	<< "|" << setw(9) <<"75" << "|" << endl;
	cout << "---------|--------------------------------|---------|" << endl;











}

