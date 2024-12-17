#pragma once
#include<iostream>
#include<vector>
#include <string>
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


	static void LowerCaseAllLetters(string& s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			s[i] = tolower(s[i]);
		}
	}

	void LowerCaseAllLetters()
	{
		LowerCaseAllLetters(_stringValue);
	}

	static void ConvertCharater(char &ch)
	{
		(char(ch) >= 65 && char(ch) <= 90)? ch = tolower(ch) : ch = toupper(ch);
	}

	void ConvertCharater()
	{
		ConvertCharater(_charValue);
	};


	static void InvertAllLetters(string& s)
	{
		for (int i = 0; i < s.length(); i++)
		{
	         ConvertCharater(s[i]);
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


	static int CountLetter(string s, char ch)
	{
		int counter = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ch)
				counter++;
		} 

		return counter;
	}
	int CountLetter(char ch)
	{
		return CountLetter(_stringValue, ch);
	}
	
};

