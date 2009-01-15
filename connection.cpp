#include <iostream>
#include "connection.h"

using namespace std;

connection::connection(const string &server, int port)
{
	cout<<"Connexion à "<<server<<":"<<port<<"..."<<endl;
	this->server=server;
	this->port=port;

	struct hostent *hp;
	if((hp=gethostbyname(server.c_str()))==NULL) {
		cerr<<"Hôte inconnu"<<hp<<endl;
		throw "unknown host";
	}


	memset(&this->sin, 0, sizeof(struct sockaddr_in));
	memcpy((char *)&sin.sin_addr, hp->h_addr, hp->h_length);
	this->sin.sin_family=hp->h_addrtype;
	this->sin.sin_port=htons(port);

	if((this->sock=socket(hp->h_addrtype, SOCK_STREAM, 0)) < 0 ) {
		cerr<<"Erreur lors de la création du socket"<<endl;
		throw "socket creation error";
	}
	
	if(connect(this->sock, (struct sockaddr *)&sin, sizeof(sin)) < 0 ) {
		close(this->sock);
		cerr<<"Connexion refusée"<<endl;
		throw "connection refused";
	}
}

connection::~connection()
{
	cout<<"Déconnexion"<<endl;
	close(this->sock);
}
