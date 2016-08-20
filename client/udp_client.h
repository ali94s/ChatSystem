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



class Client
{
public:
	Client(const string& ip,const int& port);
	~Client();

	void Init();

	size_t recv_msg(string& msg);
	size_t send_msg(string& msg);
private:
	string _remote_ip;
	int _port;
	int _sock;
};
