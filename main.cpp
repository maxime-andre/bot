#include <iostream>
#include <sstream>
#include "connection.h"
#include "configuration.h"

using namespace std;

int main(int argc, char **argv)
{
	configuration conf("bot.conf");
	string server, str_port;
	int port;
	try {
		server=conf["server"];
		str_port=conf["port"];
		istringstream istr(str_port);
		if(istr>>port)
			throw "Port incorrect";
		
	}
	catch(char*e) {
		cout<<"Fichier de configuration incorrect"<<endl;
		cout<<e<<endl;
		return 1;
	}
	catch(...) {
		cout<<"Exception inconnue"<<endl;
		return 1;
	}
	
	connection *irc_connection=new connection(server, port);

	delete irc_connection;

	return 0;
}
