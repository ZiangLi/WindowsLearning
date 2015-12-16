#include "registryIO.h"
#include "constVar.h"
#include <iostream>
void deleteRegKey(bool popHubb , bool popWin )
{
	if (popHubb)
	{
		HKEY hKey;
		LONG resultOpen=RegOpenKeyEx(_HKEY, popHubbSubkey, 0, KEY_SET_VALUE, &hKey);
		if (ERROR_SUCCESS == resultOpen)
		{

			LONG resultHubb = RegDeleteValue(hKey, popHubbValueName);

			if (ERROR_SUCCESS != resultHubb)
				printf("Cannot delete HubbSubkey\n");
		}
	}
	if (popWin)
	{
		LONG resultWin = RegDeleteKey(_HKEY, popWinSubkey);

		if (ERROR_SUCCESS != resultWin)
			printf("Cannot delete HubbSubkey\n");
	}
}

bool isInternalUser(bool setValue)
{
	bool bInternalUser = true;
	HKEY hKey;
	LONG resultOpen=RegOpenKeyEx(_HKEY, TestSubkey, 0, KEY_ALL_ACCESS, &hKey);

	if (ERROR_SUCCESS == resultOpen)
	{
		DWORD BufferSize = 256;
		DWORD cbData;
		DWORD dwRet;

		LPBYTE PerfData = (LPBYTE)malloc(BufferSize);
		cbData = BufferSize;

		printf("\nRetrieving the data...");


		dwRet = RegQueryValueEx(hKey,
			TestValueName,
			NULL,
			NULL,
			PerfData,
			&cbData);

		if (dwRet == ERROR_SUCCESS && strcmp((char*)PerfData,"0"))
		{
			bInternalUser = false;
			std::cout << PerfData << std::endl;
		}
	}

	return bInternalUser;
}