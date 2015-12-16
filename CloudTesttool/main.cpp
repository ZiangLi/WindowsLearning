#include <iostream>
#include <string>
#include <Windows.h>

#include "constVar.h"
#include "hostsIO.h"
#include "registryIO.h"

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
	if (isIP2DomainIncluded(ip, domain))
		printf("hostsInfo:OK\n");
	else
		printf("hostsInfo:Not Found!\n");

	deleteRegKey();

	isInternalUser();
}