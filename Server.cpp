
#include "Server.h"



string SocketIO::read() {
    char* letter = nullptr;
    string buffer = "";
    while(!strcmp(letter,"\n")){
        recv(this->clientPort,letter,sizeof(char),0);
        buffer += *letter;
    }
    return buffer;
}

void SocketIO::write(string text) {
    const char* t = text.c_str();
    send(this->clientPort,t, strlen(t),0);
}

void SocketIO::write(float f) {
    string s(std::to_string(f));
    this->write(s);
}

void SocketIO::read(float *f) {
    this->read();
}

void Server::start(ClientHandler& ch)throw(const char*){	
}

void Server::stop(){
	t->join(); // do not delete this!
}

Server::~Server() {
}

