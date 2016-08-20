#pragma once 
#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>

using namespace std;

//#define _SIZE_ 1024
//const string IP="127.0.0.1";
//const int PORT=8080;

class Server
{
public:
	Server();
//	Server(const string& _ip=IP,const int& port=PORT);
	~Server();
	void Init();
	size_t get_msg(string& msg);
	size_t put_msg();
private:
	string _ip;
	int _port;
	int _sock;
};
