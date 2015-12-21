#include "hostsIO.h"

bool isIP2DomainIncluded(const string &ip, const string &domain)
{
	bool isIncluded = false;

	ifstream ifs(hostsDir);
	if (!ifs)
	{
		cout << "Error opening " << hostsDir << " for input" << endl;
		exit(-1);
	}

	string line;
	while (getline(ifs, line))
	{
		//how to identify '#' at the first of one line?
		//ok,use sstream to judge whether first character of splited string is '#'.
		istringstream is(line);
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
	ifs.close();

	ofstream ofs(hostsDir, ios::app);
	//
	if (isIncluded == false)
	{
		ofs << "\n" << ip << " " << domain;
		printf("IP2Domain not found\n");
		printf("Hosts config accomplished\n");
	}
	else
		printf("IP2Domain exists\n");
	ofs.close();

	return isIncluded;
}