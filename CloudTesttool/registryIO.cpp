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
			printf("Cannot delete popWinSubkey\n");
	}
}

bool isInternalUser(bool setValue)
{
	bool bInternalUser = true;
	HKEY hKey;
	LONG resultOpen = RegOpenKeyEx(_HKEY, TestSubkey, 0, KEY_ALL_ACCESS, &hKey);

	if (ERROR_SUCCESS == resultOpen)
	{
		DWORD dwType = REG_NONE;
		DWORD dwCount = 0;

		DWORD DValue = 0;

		LONG lResult= RegQueryValueEx(hKey,
			TestValueName,
			NULL,
			&dwType,
			NULL,
			&dwCount);

		if (lResult == ERROR_SUCCESS)
		{
			lResult = RegQueryValueEx(hKey,
				TestValueName,
				NULL,
				&dwType,
				(LPBYTE)&DValue,
				&dwCount);

			if (DValue != 0)
			{
				bInternalUser = false;
				if (setValue == true)
				{
					DWORD newValue = 1;
					RegSetValueEx(hKey,
						TestValueName,
						NULL,
						REG_DWORD,
						(LPBYTE)&newValue,
						dwCount
						);

					printf("TestValue changed!\n");
				}
			}
		}
		RegCloseKey(hKey);
	}

	return bInternalUser;
}