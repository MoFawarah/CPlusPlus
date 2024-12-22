
#include <iostream>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsStringNew.h"
#include "clsClient.h"

int main()
{ 
   
	clsClient client;

	vector <clsClient> vClients;
	vClients = client.LoadCleintsDataFromFile();

	client.PrintAllClientsData(vClients);
	



	
	return 0;
}