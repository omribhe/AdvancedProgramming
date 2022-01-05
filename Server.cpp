
#include "Server.h"


void Server::start(ClientHandler& ch)throw(const char*){	
}

void Server::stop(){
	t->join(); // do not delete this!
}

Server::~Server() {
}

