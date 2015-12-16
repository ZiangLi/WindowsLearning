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