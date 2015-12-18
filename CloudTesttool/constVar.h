#pragma once

#include <string>
#include <Windows.h>

const std::string hostsDir = "C:\\Windows\\System32\\drivers\\etc\\hosts";
const std::string ip = "125.39.204.225";
const std::string domain = "wup.imtt.qq.com";

#define _HKEY HKEY_CURRENT_USER
const LPCTSTR TestSubkey = TEXT("Software\\Tencent\\QQBrowser\\PrivateCfg");
const LPCTSTR TestValueName = TEXT("INTUER");
const LPCTSTR popWinSubkey = TEXT("Software\\Tencent\\QQBrowser\\ExtensionsInfo\\{66AC5389-365D-4B55-BF5C-5A2A4BC21CCD}");
const LPCTSTR popHubbSubkey = TEXT("Software\\Tencent\\QQBrowser\\PrivateCfg");
const LPCTSTR popHubbValueName = TEXT("lastIconPushTime");
const char interUserMark[] = "0";

#define _HKEY_LOG HKEY_LOCAL_MACHINE
const LPCTSTR VersionSubkey32 = TEXT("SOFTWARE\\Tencent\\QQBrowser");
const LPCTSTR VersionSubkey64 = TEXT("SOFTWARE\\Wow6432Node\\Tencent\\QQBrowser");
const LPCTSTR VersionName = TEXT("Version");

//const std::string logDirXP = "C:\\Documents and Settings\\%USERNAME%\\Local Settings\\Application Data\\Tencent\\QQBrowser\\User Data\\";
//const std::string logDir = "C:\\Users\\%USERNAME%\\AppData\\Local\\Tencent\\QQBrowser\\User Data\\";

const std::string logDirXP1 = "C:\\Documents and Settings\\";
const std::string logDirXP2 = "\\Local Settings\\Application Data\\Tencent\\QQBrowser\\User Data\\";
const std::string logDir1 = "C:\\Users\\";
const std::string logDir2 = "\\AppData\\Local\\Tencent\\QQBrowser\\User Data\\";