
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
    float temp = stof(this->read());
    *f = temp;
}

void Server::start(ClientHandler& ch)throw(const char*){
    t = new thread([&ch,this](){
        __sighandler_t connect_alarm;
        signal(SIGALRM,connect_alarm ); /* connect_alarm is you signal handler */
        while(isTurnOn) {
            alarm( 2 ); /* secs is your timeout in seconds */
            socklen_t size = sizeof(client);
            int fileDescriptorAccept = accept(fileD, (struct sockaddr *) &client, &size);
            if (fileDescriptorAccept == -1) {
                throw ("accept filed");
            }
            ch.handle(fileDescriptorAccept);
            close(fileDescriptorAccept);
        }
        close(fileD);
    });
}

void Server::stop(){
    this->isTurnOn = false;
	t->join(); // do not delete this!
}

Server::~Server() {
}

