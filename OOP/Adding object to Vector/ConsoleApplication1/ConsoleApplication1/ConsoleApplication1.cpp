
#include<iostream>
#include<vector>

using namespace std;

class Person
{
public:

	int age;
	string name;

	Person(int age, string name)
	{
		this->age = age;
		this->name = name;
	}


	void Print()
	{
		cout << "Age is =" << age << ". Name is " << name << endl;
	}

};


int main()

{

	vector <Person> v1;
	short NumberOfObjects = 5;

	// inserting object at the end of vector
	for (int i = 0; i < NumberOfObjects; i++)
	{
		v1.push_back(Person(i, "MEow"));
	}

	// printing object content
	for (int i = 0; i < NumberOfObjects; i++)
	{
		cout << v1[i].name << endl;

	}

}

