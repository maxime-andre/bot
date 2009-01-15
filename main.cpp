#include <iostream>
#include "connection.h"

using namespace std;

int main(int argc, char **argv)
{
	connection *irc_connection=new connection("irc.sagwin.org", 6667);

	delete irc_connection;

	return 0;
}
