
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void SaveDataFromVectorToFile(string fileName, vector<string> vData)
{
	fstream file;
	file.open(fileName, ios::out);

	if (file.is_open())
	{
		for (string& line : vData)
		{
			if(line != "")
			file << line << endl;
		}
			
	}

	file.close();
}
void LoadFileToVector(string fileName, vector<string>& vData)
{
	fstream file;
	file.open(fileName, ios::in);

	if (file.is_open())
	{
		string line = "";
		while (getline(file, line))
		{
			vData.push_back(line);
		}


	file.close();
	}
}
void PrintFileContent(string fileName)
{
	fstream file;
	file.open(fileName, ios:: in);

	if (file.is_open())
	{
		string line = "";
		
		while (getline(file, line))
		{
			cout << line << endl;
		}

		file.close();
	}

}

void DeleteFromFile(string fileName, string record)
{
	vector <string> vData;
	LoadFileToVector(fileName, vData);
	

	for (string &line : vData)
	{
		if (line == record)
		{
			line = "";
		}
	}

	SaveDataFromVectorToFile(fileName, vData);
	
}

void UpdateRecordInFile(string fileName, string record, string updateTo = "Omar")
{
	vector <string> vDataNew;
	LoadFileToVector(fileName, vDataNew);


	for (string & line : vDataNew)
	{
		if (line == record)
		{
			line = updateTo;
		}
	}
	SaveDataFromVectorToFile(fileName, vDataNew);
}
int main()
{


	//PrintFileContent("myFile.txt");

	//vector<string> vData = {};
	//LoadFileToVector("myFile.txt", vData);

	//for (int i = 0; i < vData.size(); i++)
	//{
	//	cout << "Vector's position " << i+1 << " has: "<< vData[i] << endl;
	//}


	//for (int i = 0; i < vData.size(); i++)
	//{
	//	vData[i] += "Hi";
	//}

	//for (string &line : vData)
	//{
	//	cout << line << endl;
	//}

	//vector <string> vVectorData = { "Ali", "Mohammad", "Ali", "Ratib", "Hatem", "Fawareh" };
	//SaveDataFromVectorToFile("myFile.txt", vVectorData);

	cout << "Before Delete: " << endl;
	PrintFileContent("myFile.txt");


	//DeleteFromFile("myFile.txt", "Rania");

	//cout << "After Delete: " << endl;
	//PrintFileContent("myFile.txt");


	cout << "After Update: " << endl;

	UpdateRecordInFile("myFile.txt", "Mohammad Hatem Fawareh");
	PrintFileContent("myFile.txt");


}

