#pragma once
#include<iostream>
#include<vector>
#include <string>
#include <fstream>
using namespace std;

class clsStringNew
{

	string _stringValue;
	char _charValue;

	 struct stCounter {
		int capitalCounter = 0;
		int smallCounter = 0;
		int Length = 0;
	};


public:
	clsStringNew()
	{
		_stringValue = "";
		_charValue = '/0';
	};

	clsStringNew(string value)
	{
		_stringValue = value;
		_charValue = '/0';
	}

	clsStringNew(char value)
	{
		_stringValue = "";
		_charValue = value;
	}

	void setStringValue(string value)
	{
		_stringValue = value;
	}

	string getStringValue()
	{
		return _stringValue;
	}

	__declspec(property(get = getStringValue, put = setStringValue)) string stringValue;


	void setCharValue(char value)
	{
		_charValue = value;
	}

	char getCharValue()
	{
		return _charValue;
	}

	__declspec(property(get = getCharValue, put = setCharValue)) char charValue;

	
	// Functions and procedures:

	static void getEachFirstLetterOfString(string s)
	{

		// method 01:
		/*for (int i = 0; i < s.length(); i++)
		{
			if (s[0] != ' ' && i == 0)
			{
				cout << s[0] << " ";
			}

			if (s[i] == ' ')
			{
				if (s[i + 1] != ' ')
					cout << s[i + 1] << " ";
			}
		}*/


		// method 02:
		bool isFirstLetter = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ' && isFirstLetter)
			{
				cout << s[i] << " ";
			}

			isFirstLetter = s[i] == ' ' ? true : false;
		}

	};

	static void GetEachWordOfString(string s)
	{
		string word = "";
		string skipper = " ";
		for (int i = 0; i < s.length(); i++)
		{

			if (s[i] != ' ' && s.find(skipper) != s.npos)
			{
				word += s[i];
			}

			if ((s[i] == ' ' || i == s.length() - 1) && word != "")
			{
				cout << word << endl;
				word = "";
			}

		}

	};


	static vector <string> GetEachWordOfString02(string s)
	{
		string word = "";
		string skipper = " ";
		vector <string> stringSplitted;
		for (int i = 0; i < s.length(); i++)
		{

			if (s[i] != ' ' && s.find(skipper) != s.npos)
			{
				word += s[i];
			}

			if ((s[i] == ' ' || i == s.length() - 1) && word != "")
			{
				stringSplitted.push_back(word);
				word = "";
			}

		}
		return stringSplitted;

	};


	static string ReplaceUsingSplit(string sentString, string toBeReplaced, string replaceWith, bool MatchCase = false)
	{

		vector <string> stringSplitted = SplitString(sentString, " ");
		for (string& word : stringSplitted)
		{
			if (MatchCase)
			{
				if (word == toBeReplaced)
					word = replaceWith;
			}

			else
			{
				if (LowerCaseAllLetters(word) == LowerCaseAllLetters(toBeReplaced))
					word = replaceWith+" ";
			}
			
		}

		return Join(stringSplitted, " ");
	}

	static string RemovePunctuationsOfString(string sentString)
	{
		string S2 = "";
		for (int i = 0; i < sentString.length(); i++)
		{
			if (!ispunct(sentString[i]))
				S2 += sentString[i];
		}

		return S2;
	};


	static string Replace(string sentString, string toBeReplaced, string replaceWith)
	{
		short pos = sentString.find(toBeReplaced);
		while (pos != string::npos)
		{
			sentString.replace(pos, toBeReplaced.length(), replaceWith);
			pos = sentString.find(toBeReplaced);
		}

		return sentString;
	}

	static struct stClientData
	{
		string AccountNumber;
		string PinCode;
		string Name;
		string Phone;
		double AccountBalance;

		stClientData()
		{
			this->AccountNumber = "";
			this->PinCode = "";
			this->Name = "";
			this->Phone = "";
			this->AccountBalance = 0;

		}
	};

	static stClientData ReadClientData(stClientData Client)
	{
		cout << "Enter Account Number? ";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, Client.AccountNumber);
		cout << "Enter PinCode? ";
		getline(cin, Client.PinCode);
		cout << "Enter Name? ";
		getline(cin, Client.Name);
		cout << "Enter Phone? ";
		getline(cin, Client.Phone);
		cout << "Enter AccountBalance? ";
		cin >> Client.AccountBalance;
		return Client;
	}
	static string ClientDataToLine(stClientData client, string seperator = "#//#")
	{
		return client.AccountNumber + seperator + client.PinCode + seperator + client.Name + seperator + client.Phone + seperator + to_string(client.AccountBalance);
	}

	static stClientData convertLineToRecord(string clientData, string seperator = "#//#")
	{
		stClientData client;
		vector <string> clientDataExtracted;
		clientDataExtracted = SplitString(clientData, seperator);
		
		client.AccountNumber = clientDataExtracted[0];
		client.PinCode = clientDataExtracted[1];
		client.Name= clientDataExtracted[2];
		client.Phone= clientDataExtracted[3];
		client.AccountBalance= stod(clientDataExtracted[4]);

		return client;

	}
	static void AddDataLineToFile(string FileName, string stDataLine)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	static void AddNewClient()
	{
		const string ClientsFileName = "Clients.txt";
		stClientData Client;
		Client = ReadClientData(Client);
		AddDataLineToFile(ClientsFileName, ClientDataToLine(Client));
	}

	static void AddClients()
	{
		char AddMore = 'Y';
		do
		{
			system("cls");
			cout << "Adding New Client:\n\n";
			AddNewClient();
			cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
				cin >> AddMore;
		} while (toupper(AddMore) == 'Y');
	}


	static void PrintClientRecord(stClientData Client)
	{
		cout << "\n\nThe following is the extracted client record:\n";
		cout << "\nAccout Number: " << Client.AccountNumber;
		cout << "\nPin Code : " << Client.PinCode;
		cout << "\nName : " << Client.Name;
		cout << "\nPhone : " << Client.Phone;
		cout << "\nAccount Balance: " << Client.AccountBalance;
	}


	void GetEachWordOfString()
	{
		GetEachWordOfString(_stringValue);
	};


	static int CountWordsOfString(string s)
	{
		int counter = 0;

		for (int i = 0; i < s.length(); i++)
		{

			if (s[i] != ' ')
			{
				counter++;
				while (i < s.length() && s[i] != ' ')
				{
					i++;
				}
			}
		}

		return counter;
	};

	int CountWordsOfString()
	{
		return CountWordsOfString(_stringValue);
	};

	static vector<string> SplitString(string sentString, string delim)
	{
		vector <string> sSplited;
		short pos = 0;
		string sWord = "";
		while ((pos = sentString.find(delim)) != string::npos)
		{
			sWord = sentString.substr(0, pos);
			if (!sWord.empty() && sWord != "")
			{
				sSplited.push_back(sWord);
			}
			sentString.erase(0, pos + delim.length());		
		}		

		if (sentString != "")
		{
			sSplited.push_back(sentString);
		}

		return sSplited;

	}


	static string Join(vector <string> V, string seperator)
	{
		string newString = "";
		short lastItem = V.size() - 1;
		for (string& word : V)
		{
			newString += word;
			if (word != V[lastItem])
			newString += seperator;
		}

		return newString;
	}

	static string Join(string V[10], int length, string seperator)
	{
		string newString = "";

		for(int i = 0; i < length; i++)
		{
			newString = newString +  V[i] + seperator;
		}

		return newString.substr(0, newString.length() - seperator.length());
	}

	static string Join(string S1, string S2, string seperator)
	{
		return S1 + seperator + S2;
	}

	static string ReverseWordsInString(string S1)
	{
		vector<string> vString;
		string S2 = "";
		vString = SplitString(S1, " ");
		// declare iterator
		/*vector<string>::iterator iter = vString.end();
		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		S2 = S2.substr(0, S2.length() - 1); *///remove last space.

		for (int i = vString.size()-1; i >=0; i--)
		{
			S2 += vString[i];
			if (vString[i] != vString[0])
				S2 += " ";
		}
		return S2;
	}
	static string TrimLeft(string sentString)
	{
		short pos = 0;
		int i = 0;
		for (i; i < sentString.length(); i++)
		{
			if (sentString[i] != ' ')
			{
				//return sentString.erase(0, i);
				//or
				return sentString.substr(i, sentString.length()-1);
			}
			
		}
		return "";
		
		
	}

	static string TrimRight(string sentString)
	{
		short pos = 0;
		short i = sentString.length()-1;
		for (i; i >= 0; i--)
		{
			if (sentString[i] != ' ')
			{
				//return sentString.erase(i + 1, sentString.length() - 1);
				//or
				return sentString.substr(0, i + 1);
			}

		}
		return "";
	}

	static string Trim(string sentString)
	{
		 return TrimLeft(TrimRight(sentString));
	}

	void getEachFirstLetterOfString()
	{
		getEachFirstLetterOfString(_stringValue);
	};


	static void UpperCaseEachFirstLetter(string& s)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ' && isFirstLetter)
			{
				s[i] = toupper(s[i]);
			}

			isFirstLetter = s[i] == ' ' ? true : false;
		}
	};


	void UpperCaseEachFirstLetter()
	{
		UpperCaseEachFirstLetter(_stringValue);
	};



	static void LowerCaseEachFirstLetter(string &s)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ' && isFirstLetter)
			{
				s[i] = tolower(s[i]);
			}

			isFirstLetter = s[i] == ' ' ? true : false;
		}
	};
	
	void LowerCaseEachFirstLetter()
	{
		LowerCaseEachFirstLetter(_stringValue);
	};



	static void UpperCaseAllLetters(string& s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			s[i] = toupper(s[i]);
		}
	};


	void UpperCaseAllLetters()
	{
		UpperCaseAllLetters(_stringValue);
	};


	static string LowerCaseAllLetters(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			s[i] = tolower(s[i]);
		}
		return s;
	}

	void LowerCaseAllLetters()
	{
		LowerCaseAllLetters(_stringValue);
	}

	static void InvertCharater(char &ch)
	{
		(char(ch) >= 65 && char(ch) <= 90)? ch = tolower(ch) : ch = toupper(ch);
	}

	void InvertCharater()
	{
		InvertCharater(_charValue);
	};


	static void InvertAllLetters(string& s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			InvertCharater(s[i]);
		}
	};

	void InvertAllLetters()
	{
		InvertAllLetters(_stringValue);
	};



	static stCounter Count(string s)
	{
		stCounter counter;
		counter.Length = s.length();
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
			{
				if (isupper(s[i]))
					counter.capitalCounter++;
				else
					counter.smallCounter++;
			}
		}

		return counter;
	};

	stCounter Count()
	{
		return Count(_stringValue);
	}


	static int CountLetter(string s, char ch, bool matchCase = true)
	{
		int counter = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (matchCase)
			{
				if (s[i] == ch)
					counter++;
			}
			else
			{
				if (tolower(s[i]) == tolower(ch))
					counter++;
			}
		} 

		return counter;
	}
	int CountLetter(char ch, bool matchCase = true)
	{
		return CountLetter(_stringValue, ch, matchCase);
	};


	
	static bool IsVowel(char ch)
	{
		ch = tolower(ch);
		
		return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u'));
	}

	bool IsVowel()
	{
		return IsVowel(_charValue);
	}

	static int CountVowels(string S)
	{
		int counter = 0;
		for (int i = 0; i < S.length(); i++)
		{
			if (IsVowel(S[i]))
				counter++;
		}

		return counter;
	}

	int CountVowels()
	{
		return CountVowels(_stringValue);
	};

	static void PrintVowels(string S)
	{
		for (int i = 0; i < S.length(); i++)
		{
			if (IsVowel(S[i]))
				cout << S[i] << "     ";
		}
	};

	void PrintVowels()
	{
		PrintVowels(_stringValue);
	}


	
};

