#include "hostsIO.h"

bool isIP2DomainIncluded(const string &ip, const string &domain)
{
	bool isIncluded = false;

	ifstream fs(hostsDir);
	if (!fs)
	{
		cout << "Error opening " << hostsDir << " for input" << endl;
		exit(-1);
	}

	string s;
	while (getline(fs, s))
	{
		//how to identify '#' at the first of one line?
		//ok,use sstream to judge whether first character of splited string is '#'.
		istringstream is(s);
		string _ip,_domain;
		is >> _ip;
		
		if (_ip[0] == '#')
			continue;
		else
		{
			is >> _domain;
			if (_ip==ip && _domain==domain)
			{
				isIncluded = true;
				break;
			}
		}

	}
	return isIncluded;
}