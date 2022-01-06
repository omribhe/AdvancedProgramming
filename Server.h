/*
 * Server.h
 *
 *  Created on: Dec 13, 2020
 *      Author: Eli
 */

#ifndef SERVER_H_
#define SERVER_H_
#include <sys/socket.h>
#include "CLI.h"
#include <netinet/in.h>
#include <iostream>
#include <pthread.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread>
#include<signal.h>
#include <unistd.h>


using namespace std;

// edit your ClientHandler interface here:
class ClientHandler{
    public:
    virtual void handle(int clientID)=0;
};


// you can add helper classes here and implement on the cpp file
class SocketIO: public DefaultIO {
    int clientPort;
public:
    virtual string read();

    virtual void write(string text);

    virtual void write(float f);

    virtual void read(float *f);
};

// edit your AnomalyDetectionHandler class here
class AnomalyDetectionHandler:public ClientHandler{
	public:
    virtual void handle(int clientID){

    }
};


// implement on Server.cpp
class Server {
    int fileD;
    sockaddr_in server;
    sockaddr_in client;
	thread* t; // the thread to run the start() method in

	// you may add data members

public:
	Server(int port) throw (const char*) {
        this->fileD = socket(AF_INET, SOCK_STREAM, 0);
        if (fileD < 0)
            throw "socket failed";
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(port);
        int flag = bind(this->fileD,(struct sockaddr*)&server,sizeof(server));
        if ( flag < 0)
            throw "bind failed";
        int flag2 = listen(this->fileD, 5);
        if (flag2 == -1)
            throw "listen failed";
    }
	virtual ~Server();
	void start(ClientHandler& ch)throw(const char*);
	void stop();
};

#endif /* SERVER_H_ */
