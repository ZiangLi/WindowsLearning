#include <iostream>
#include <string>
#include <Windows.h>
#include <shellapi.h>

#include "constVar.h"
#include "hostsIO.h"
#include "registryIO.h"
#include "logFilter.h"
using namespace std;

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
//{
//	if (isIP2DomainIncluded(ip, domain))
//		MessageBox(NULL,TEXT("OK"),TEXT("hostsInfo"),0);
//	else
//		MessageBox(NULL, TEXT("Not found!"), TEXT("hostsInfo"), 0);
//
//	return 0;
//}

int main()
{
	printf("Choose the function needed:\n\n\t");
	printf("0.Hosts config\n\t");
	printf("1.InternalUser or not\n\t");
	printf("2.Delete Pop and Bubble RegKey\n\t");
	printf("3.Filter the chrome_debug.log\n\t");
	printf("4.All the functions above\n\t");
	while (1)
	{

		string keyword;
		int choice = -1;

		cout << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			//1.1
			isIP2DomainIncluded(ip, domain);
			break;
		case 1:
			//1.2.1
			if (isInternalUser())
				printf("InternalUser\n");
			else
				printf("Not InternalUser\n");
			break;
		case 2:
			//1.2.2
			deleteRegKey();
			break;
		case 3:
			//2.1
			printf("Input the keyword to filter the debuglog:\n");
			cin >> keyword;
			if (isTestVersion())
				filterAndPrintLog(keyword);
			else
				printf("Not v401\n");
			break;
		case 4:
		{
				   isIP2DomainIncluded(ip, domain);


				   if (isInternalUser())
					   printf("InternalUser\n");
				   else
					   printf("Not InternalUser\n");

				   deleteRegKey();

				   printf("Input the keyword to filter the debuglog:\n");

				   cin >> keyword;
				   if (isTestVersion())
					   filterAndPrintLog(keyword);
				   else
					   printf("Not v401\n");
				   break;
		}
		default:
			break;
		}
	}

	return 0;
}