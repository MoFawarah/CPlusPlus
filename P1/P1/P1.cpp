

#include <iostream>
using namespace std;


enum enGender { Male, Female };
enum enMaritalStatus { Single, Married };
enum enColor {Red, Blue, Yellow, White, Black};

struct StAddress
{
    string City;
    string Country;
    string Street;
    string ZipCode;

};

struct StContactInfo
{
    string Phone;
    string Email;
    StAddress Address;
};

struct StUser
{
    string Name;
    short Age;
    float MonthlySalary;
    float YearlySalary;

    StContactInfo ContactInfo;

    enGender Gender;
    enMaritalStatus MaritalStatus;
    enColor FavColor;
};



void ReadUserInfo(StUser &User)
{
    cout << "Plz enter your name: " << endl;
    cin >> User.Name;

    cout << "Plz enter your age: " << endl;
    cin >> User.Age;

    cout << "Plz enter your monthly salary: " << endl;
    cin >> User.MonthlySalary;
    User.YearlySalary = User.MonthlySalary*12;

    cout << "Plz enter your phone: " << endl;
    cin >> User.ContactInfo.Phone;
    cout << "Plz enter your email: " << endl;
    cin >> User.ContactInfo.Email;

    cout << "Plz enter your city: " << endl;
    cin >> User.ContactInfo.Address.City;


    int genderInput;
    cout << "Plz enter your gender (0 for Male, 1 for Female): " << endl;
    cin >> genderInput;
    if (genderInput == 0)
        User.Gender = Male;
    else if (genderInput == 1)
        User.Gender = Female;
    else
        cout << "Invalid input for gender!" << endl;

    int colorInput;
    cout << "Plz enter your favorite color (0 for Red, 1 for Blue, 2 for Yellow, 3 for White, 4 for Black): " << endl;
    cin >> colorInput;
    switch (colorInput)
    {
    case 0:
        User.FavColor = Red;
        break;
    case 1:
        User.FavColor = Blue;
        break;
    case 2:
        User.FavColor = Yellow;
        break;
    case 3:
        User.FavColor = White;
        break;
    case 4:
        User.FavColor = Black;
        break;
    default:
        cout << "Invalid input for favorite color!" << endl;
        break;
    }

    int maritalInput;
    cout << "Plz enter your marital status (0 for Single, 1 for Married): " << endl;
    cin >> maritalInput;

    if (maritalInput == 0)
        User.MaritalStatus = enMaritalStatus:: Single;
    else if (maritalInput == 1)
        User.MaritalStatus = enMaritalStatus:: Married;
    else
        cout << "Invalid input for marital status!" << endl;

}




void DisplayUserInfo(StUser User) {
    cout << "Name: " << User.Name << endl;
    cout << "Age: " << User.Age << endl;
    cout << "Monthly Salary: " << User.MonthlySalary << endl;
    cout << "Yearly Salary: " << User.YearlySalary << endl;
    cout << "Phone: " << User.ContactInfo.Phone << endl;
    cout << "Email: " << User.ContactInfo.Email << endl;
    cout << "Gender: " << (User.Gender == Male ? "Male" : "Female") << endl;
    cout << "Marital Status: " << (User.MaritalStatus == Single ? "Single" : "Married") << endl;
    cout << "Favorite Color: " << (User.FavColor == Red ? "Red" : User.FavColor == Blue ? "Blue" : User.FavColor == Black ? "Black" : User.FavColor == Yellow ? "Yellow" : "White") << endl;
}


int main()
{
   
    StUser User;
    ReadUserInfo(User);

    DisplayUserInfo(User);

	return 0;


}

