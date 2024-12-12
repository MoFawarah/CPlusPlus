
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;


#pragma region ReadNumbersVectors
void ReadVectorsNumbers(vector<int> & vec)
{
	int number = 0;
	char addMore = 'y';

	cout << "Please Enter a Number: ";
	cin >> number;

	vec.push_back(number);
	 
	do
	{
		cout << "Do you wanna add more numbers? Y/N: ";
		cin >> addMore;
		if (addMore == 'y' || addMore == 'Y')
		{
			cout << "Please enter another number: ";
			cin >> number;
			vec.push_back(number);
		}

	} while (addMore == 'y' || addMore == 'Y');

}

void PrintVector(vector<int> & vec)
{
	for (int &num : vec)
		cout << num << " ";
}
#pragma endregion

#pragma region VectorOfStructure
struct stEmployee
{
	string firstName;
	string lastName;
	float salary;

	stEmployee()
	{
		firstName = "";
		lastName = "";
		salary = 0;
	}

};

void AddEmpolyee(vector <stEmployee> &vEmp)
{
	stEmployee emp;
	char addMore = 'y';

 

	while (addMore == 'y' || addMore == 'Y')
	{
		cout << "Add a new emp: \n" << endl;

		cout << "Add First Name: ";
		cin >> emp.firstName;

		cout << "Add Last Name: ";
		cin >> emp.lastName;

		cout << "Add Salary: ";
		cin >> emp.salary;
		cout << endl;

		vEmp.push_back(emp);
		cout << "Do you wanna add more employess? Y/N: ";
		cin >> addMore;
	};


}

void PrintVector(vector<stEmployee>& vec)
{
	for (stEmployee& emp : vec)
	{
		cout << "First Name: " << emp.firstName << endl;
		cout << "Last Name: " << emp.lastName << endl;
		cout << "Salary: " << emp.salary << endl;
		cout << "--------------------------------------------" << endl;
	}
		
}
#pragma endregion

int main()
{
	//vector <int> myVector;

	//ReadVectorsNumbers(myVector);
	//PrintVector(myVector);


	vector <stEmployee> vEmployee;;

 
	//AddEmpolyee(vEmployee);
	//cout << "Vector Size " << vEmployee.size() << endl;
 
	//cout << "Vector Capacity " << vEmployee.capacity() << endl;
	//if (!vEmployee.empty())
	//{
	//    stEmployee firstEmp =  vEmployee.front();
	//    cout << firstEmp.firstName << endl;
	//    stEmployee lastEmp = vEmployee.back();
	//    cout << lastEmp.firstName << endl;
	//}


	//PrintVector(vEmployee);

	vEmployee.clear();

		/*stEmployee employee;
		employee.firstName = "Mohammad";
		employee.lastName = "Hatem";
		employee.salary = 800.5;
		vEmployee.push_back(employee);


		employee.firstName = "Ratib";
		employee.lastName = "ddd";
		employee.salary = 700.5;
		vEmployee.push_back(employee);


		employee.firstName = "Dina";
		employee.lastName = "qqqqq";
		employee.salary = 400;
		vEmployee.push_back(employee);*/


	//vector <int> vNumbers;
	//vNumbers.push_back(10);
	//vNumbers.push_back(20);
	//vNumbers.push_back(30);
	//vNumbers.push_back(40);
	//vNumbers.push_back(50);
	//vNumbers.push_back(50);
	//vNumbers.push_back(50);
	//vNumbers.push_back(50);
	//cout << "First Element: " << vNumbers.front() << endl;
	//cout << "Last Element: " << vNumbers.back() << endl;
	////returns the number of elements present in the vector
	//cout << "Size: " << vNumbers.size() << endl;
	////check the overall size of a vector
	//cout << "Capacity : " << vNumbers.capacity() << endl;
	////returns 1 (true) if the vector is empty
	//cout << "Empty : " << vNumbers.empty() << endl;

	/*vector<int> vec = { 1,2,3,4,5,6,7,8,9 };

	try
	{
		cout << vec.at(10);
	}
	catch (exception  ex)
	{
		cout << "Error: " << ex.what() << endl;
	}*/


	/*string s1 = "Hello, my name is Mohammad!";
	cout << s1 << endl;
	s1.append(" I am 26 years old");
	cout << s1 << endl;


	cout << s1.length() << endl;
	


	s1.insert(0,"Heeelo ");
	cout << s1 << endl;


	s1.push_back('H');
	cout << s1 << endl;
	s1.pop_back();
	cout << s1 << endl;
	cout << s1.find("Heeelo") << endl;;

	if (s1.find("ttttt") != s1.npos)
	{
		cout << "Found at " << s1.find("ttttt") << endl;
	}
	else
	{
		cout << "Not Found" << endl;
	}
*/

	string x = "Hee#lot";
	char y = toupper(x.at(x.length()-1));
	cout << y << endl;
	cout << ispunct(x.at(0)) << endl;	


	return 0;
}

