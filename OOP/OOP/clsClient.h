#pragma once
#include<iostream>
#include <iomanip>
#include<vector>
#include <string>
#include <fstream>
#include "clsStringNew.h"
using namespace std;
class clsClient
{
private:
	string _AccountNumber;
	string _PinCode;
	string _Name;
	string _Phone;
	double _AccountBalance;


public:

	string fileName = "clients.txt";
	clsClient()
	{
		_AccountNumber = "";
		_PinCode = "";
		_Name = "";
		_Phone = "";
		_AccountBalance = 0;
	}
	clsClient(string AccountNumber, string PinCode, string Name, string Phone, double AccountBalance)
	{
		this->_AccountNumber = AccountNumber;
		this->_PinCode = PinCode;
		this->_Name = Name;
		this->_Phone = Phone;
		this->_AccountBalance = AccountBalance;
	}

	// Getters and Setters:
	void setAccountNumber(string AccountNumber)
	{
		this->_AccountNumber = AccountNumber;
	}
	string getAccountNumber()
	{
		return _AccountNumber;
	}
	__declspec(property(get = getAccountNumber, put = setAccountNumber)) string AccountNumber;

	void setPinCode(string PinCode)
	{
		this->_PinCode = PinCode;
	}
	string getPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

	void setName(string Name)
	{
		this->_Name = Name;
	}
	string getName()
	{
		return _Name;
	}
	__declspec(property(get = getName, put = setName)) string Name;

	void setPhone(string Phone)
	{
		this->_Phone = Phone;
	}
	string getPhone()
	{
		return _Phone;
	}
	__declspec(property(get = getPhone, put = setPhone)) string Phone;

	void setAccountBalance(double AccountBalance)
	{
		if (AccountBalance >= 0)
		{
			this->_AccountBalance = AccountBalance;
		}
		else
		{
			cout << "Invalid account balance. Please enter a positive value." << endl;
		}
	}

	double getAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountBalance)) double AccountBalance;

	// Functions and procedures:

	void UpdateClientData()
	{
		cout << "Enter Account Number? ";
		getline(cin, this->_AccountNumber);
		cout << "Enter PinCode? ";
		getline(cin, this->_PinCode);
		cout << "Enter Name? ";
		getline(cin, this->_Name);
		cout << "Enter Phone? ";
		getline(cin, this->_Phone);
		cout << "Enter AccountBalance? ";
		cin >> this->_AccountBalance;
	}

	clsClient ReadNewClient()
	{
		
		cout << "Enter Account Number? ";
		getline(cin >> ws, this->_AccountNumber);
		cout << "Enter PinCode? ";
		getline(cin, this->_PinCode);
		cout << "Enter Name? ";
		getline(cin, this->_Name);
		cout << "Enter Phone? ";
		getline(cin, this->_Phone);
		cout << "Enter AccountBalance? ";
		cin >> this->_AccountBalance;
		return *this;

	}

	string ConvertRecordToLine(clsClient client, string seperator = "#//#")
	{
		return client.AccountNumber + seperator + client.PinCode + seperator + client.Name + seperator + client.Phone + seperator + to_string(client.AccountBalance);

	}

	clsClient ConvertLineToRecord(string line, string seperator = "#//#")
	{
		clsClient client;
		vector <string> vClient;
		vClient = clsStringNew::SplitString(line, seperator);

		client.AccountNumber = vClient[0];
		client.PinCode = vClient[1];
		client.Name = vClient[2];
		client.Phone = vClient[3];
		client.AccountBalance = stod(vClient[4]);
		

		return client;


	}


	void AddDataLineToFile(string fileName, string clientLine)
	{
		fstream file;
		file.open(fileName, ios::out | ios::app);

		if (file.is_open())
		{
			file << clientLine << endl;
		}

		file.close();

	}

	void AddNewClient()
	{
		clsClient client = {};
		string line = "";
		client = ReadNewClient();
		line = ConvertRecordToLine(client);
		AddDataLineToFile(fileName, line);
	}
	
	void AddClients()
	{

		char addMore = 'Y';
		
		cout << "Adding New Clients: " << endl;
		do
		{
			AddNewClient();

			cout << "Client Added Successfuly. Do you want to add more clients? Y/N: ";
			cin >> addMore;
			if (tolower(addMore) == 'y')
				system("cls");
			

		} while (tolower(addMore) == 'y');

	}

	vector <clsClient> LoadCleintsDataFromFile()
	{
		fstream file;
		vector <clsClient> vClients;
		file.open(fileName, ios::in);

		if (file.is_open())
		{
			string line = "";
			while (getline(file, line))
			{
				vClients.push_back(ConvertLineToRecord(line));
			}


			file.close();
		}

		return vClients;
	}

	void PrintClientRecord(clsClient &Client)
	{
		cout << "| " << setw(15) << left << Client.AccountNumber;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(40) << left << Client.Name;
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}


	void PrintAllClientsData(vector <clsClient> vClients)
	{
		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
			cout <<
			"\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Balance";
		cout <<
			"\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		for (clsClient Client : vClients)
		{
			PrintClientRecord(Client);
			cout << endl;
		}
		cout <<
			"\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}



};