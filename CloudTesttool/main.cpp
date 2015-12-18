#include <iostream>
#include <string>
#include <Windows.h>

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
	//1.1
	if (isIP2DomainIncluded(ip, domain))
		printf("hostsInfo:OK\n");
	else
		printf("hostsInfo:Not Found!\n");
	//1.2.1
	deleteRegKey();
	//1.2.2
	isInternalUser();

	//2.1
	if(isTestVersion())
		filterAndPrintLog("received");
}