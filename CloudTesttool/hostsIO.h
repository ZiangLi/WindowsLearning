#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "constVar.h"

using namespace std;
//TODO:write IP2Domain "125.39.204.225 wup.imtt.qq.com"
bool isIP2DomainIncluded(const string &ip, const string &domain);