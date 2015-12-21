#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "constVar.h"

using namespace std;
//To write IP2Domain "125.39.204.225 wup.imtt.qq.com", administrator authority needed
bool isIP2DomainIncluded(const string &ip, const string &domain);