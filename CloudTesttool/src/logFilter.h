#pragma once
#include <fstream>
#include <string>
#include <iostream>

//TODO:case-insensitive search
bool isTestVersion();
void filterAndPrintLog(const std::string keyword="", const std::string logname = "chrome_debug.log");