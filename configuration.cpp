#include <iostream>
#include "configuration.h"

using namespace std;

configuration::configuration(const string &filename)
{
	this->filename=filename;
}

string configuration::operator[](const char * key)
{
	string key_str(key);
	if(key_str=="server")
		return "irc.sagwin.org";
	if(key_str=="port")
		return "6667";
	throw "key not found";
}


