#include "registryIO.h"
#include "constVar.h"
#include <iostream>

void deleteRegKey(bool popBubb , bool popWin )
{
	if (popBubb)
	{
		printf("Deleting BubbSubkey...\n");

		HKEY hKey;
		LONG resultOpen=RegOpenKeyEx(_HKEY, popBubbSubkey, 0, KEY_SET_VALUE, &hKey);
		if (ERROR_SUCCESS == resultOpen)
		{

			LONG resultBubb = RegDeleteValue(hKey, popBubbValueName);

			if (ERROR_SUCCESS != resultBubb)
				printf("Cannot delete BubbSubkey or Subkey not exists\n");
			else
				printf("BubbSubkey Deleted\n");
		}
	}
	if (popWin)
	{
		printf("Deleting popWinSubkey...\n");

		LONG resultWin = RegDeleteKey(_HKEY, popWinSubkey);

		if (ERROR_SUCCESS != resultWin)
			printf("Cannot delete popWinSubkey or Subkey not exists\n");
		else
			printf("popWinSubkey Deleted\n");
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

					printf("INTUSER changed!\n");
				}
			}
		}
		else
			printf("No INTUSER found!\n");

		RegCloseKey(hKey);
	}

	return bInternalUser;
}