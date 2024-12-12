
#include <string>

#include <optional> 
#include <iostream>
using namespace std;

#pragma region StOwner
struct StOwner
{
	string ownerName;
	string phone;
	struct Address
	{
		string Strret;
		string City;
		string Country;
		string ZipCode;
	} Address;

};
#pragma endregion

#pragma region StCar
struct Car
{
	int Id;
	short Year;
	string Brand;
	StOwner Owner;

};

#pragma endregion

#pragma region Main
int main()
{

	Car Car1, Car2, Car3;
	Car1.Id = 1;
	Car1.Year = 1998;
	Car1.Brand = "BMW";
	Car1.Owner.ownerName = "Mohammad Fawareh";
	Car1.Owner.phone = "+962781537857";
	Car1.Owner.Address.City = "Ajloun";


	if (Car1.Brand.empty())
		cout << "No Brand Yet" << endl;
	else {
		cout << Car1.Brand << endl << endl;
	}

	cout << Car1.Owner.ownerName << " " << Car1.Owner.phone << endl;
	cout << Car1.Owner.Address.City << endl;





	return 0;
}

#pragma endregion



