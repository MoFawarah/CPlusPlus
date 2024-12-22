
#include <iostream>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsStringNew.h"
#include "clsClient.h"

int main()
{ 
   
	clsClient client;

	vector <clsClient> vClients = client.LoadCleintsDataFromFile();
	string AccountNumber = client.ReadClientAccountNumber();
	client.DeleteClientByAccountNumber(AccountNumber, vClients);
	system("pause>0");

	
	return 0;
}