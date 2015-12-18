#include "logFilter.h"
#include "constVar.h"

bool isTestVersion()
{
	bool isTestVersion = true;

	LPCTSTR VersionSubkey;
	SYSTEM_INFO si;
	HKEY hKey;

	GetNativeSystemInfo(&si);

	if (si.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64 ||
		si.wProcessorArchitecture != PROCESSOR_ARCHITECTURE_IA64)
	{
		VersionSubkey = VersionSubkey64;
	}
	else
	{	
		VersionSubkey = VersionSubkey32;
	}

	LONG resultOpen = RegOpenKeyEx(_HKEY_LOG, VersionSubkey, 0, KEY_READ, &hKey);
	if (ERROR_SUCCESS == resultOpen)
	{
		DWORD dwType = REG_NONE;
		DWORD dwCount = 0;

		std::wstring strValue;

		LONG lResult = RegQueryValueEx(hKey,
			VersionName,
			NULL,
			&dwType,
			NULL,
			&dwCount);

		if (lResult == ERROR_SUCCESS)
		{
			strValue.resize(dwCount);
			lResult = RegQueryValueEx(hKey,
				VersionName,
				NULL,
				NULL,
				(LPBYTE)strValue.data(),
				&dwCount);

			if (strValue[strValue.length() / 2 - 2] != '1')
			{
				isTestVersion = false;
			}
		}
	}

	return isTestVersion;
}

void filterAndPrintLog(const std::string keyword, const std::string logname)
{
	const char* Username = std::getenv("USERNAME");

	OSVERSIONINFO   osver;
	std::string dirLog = logDir1 + Username + logDir2;
	osver.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&osver);

	if (osver.dwPlatformId == 2)
	{
		if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 1)//XP
		{
			dirLog = logDirXP1 + Username + logDirXP2;
		}

		std::ifstream fs(dirLog + logname);
		std::string strLogFiltered;
		while (getline(fs, strLogFiltered))
		{
			if (keyword != "")
			{
				size_t result = strLogFiltered.find(keyword);
				if (result == std::string::npos)
					continue;
			}
			std::cout << strLogFiltered << std::endl;
		}
		fs.close();
	}
}