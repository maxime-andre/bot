#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <iostream>

class configuration {
	public:
		configuration(const std::string&);
		std::string operator[](const char *);
	private:
		std::string filename;
};

#endif
