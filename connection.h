#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

class connection {
	public:
		connection(const std::string &, int);
		~connection();
		bool connected(void);
		bool data_arrived(void);
	private:
		int sock;
		struct sockaddr_in sin;
		std::string server;
		int port;
};

#endif
