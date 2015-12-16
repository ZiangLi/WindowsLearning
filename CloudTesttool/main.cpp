#include <iostream>
#include <string>
#include <Windows.h>

#include "constVar.h"
#include "hostsIO.h"

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	if (isIP2DomainIncluded(ip, domain))
		MessageBox(NULL,TEXT("OK"),TEXT("hostsInfo"),0);
	else
		MessageBox(NULL, TEXT("Not found!"), TEXT("hostsInfo"), 0);

	return 0;
}