

#include <iostream>
#include <string>
using namespace std;

int ReadNumberInRange(int From, int To)
{
    cout <<"Please enter a num between " << From << " And " << To <<": " << endl;

    int number;
    do 
    {
     cin >> number; 
     if (number < From || number > To)
     {
         cout << "Wrong Number, Try Again: " << endl;
     }
   
    } while (number < From || number > To);

    return number;


}

void readArray(float arr[], int &Length)
{
    cout << "Please enter length of Array: ";
    cin >> Length;

    for (int i = 0; i <= Length - 1 ; i++)
    {
        cout << "Enter Number " << i+1 << ": ";
        cin >> arr[i];
    }
}
void printArray(float arr[], int Length)
{
    for (int i = 0; i <= Length - 1; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
float calculateArraySum(float arr[], int Length)
{
    float sum = 0;
    for (int i = 0; i <= Length - 1; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
  /*  float arr[50];
    int Length;
    readArray(arr, Length);
    printArray(arr, Length);
    float sum = calculateArraySum(arr, Length);
    cout << "sum is: " << sum << endl;
    cout << "avg is: " << sum/Length << endl;*/

    //for (int i = 1; i<=10; i++)
    //{
    //    for (int j=i; j <= 10; j++)
    //    {
    //        cout << j << " ";
    //    }
    //    cout << endl;
    //   
    //}


    int sum = 0, num1 = 0;

    for (int i = 1; i <= 5; i++)
    {
        cin >> num1;
        if (num1 >= 50)
        {
            continue;
        }
        sum += num1;
    }
    cout << "Sum is: " <<  sum << endl;

	

    return 0;
    
}


