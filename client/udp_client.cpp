#include"udp_client.h"

const int _SIZE_=1024;
Client::Client(const string& ip,const int& port)
	:_remote_ip(ip)
	 ,_port(port)
	 ,_sock(-1)
{}

Client::~Client()
{
	if(_sock!=-1)
		close(_sock);
}

void Client::Init()
{
	_sock=socket(AF_INET,SOCK_DGRAM,0);
	if(_sock<0)
	{
		cout<<__func__<<__LINE__<<endl;
		perror("socket()");
		exit(0);
	}
}


size_t Client::send_msg(string& msg)
{
	struct sockaddr_in remote;

	remote.sin_family=AF_INET;
	remote.sin_port=htons(_port);
	remote.sin_addr.s_addr=inet_addr(_remote_ip.c_str());

	socklen_t len=sizeof(remote);

	size_t ret=sendto(_sock,msg.c_str(),msg.size(),0,(struct sockaddr*)&remote,len);
	if(ret<0)
	{
		cout<<__func__<<__LINE__<<endl;
		perror("sendto()");
		exit(1);
	}
}

//size_t Client::recv_msg(string& msg)
//{
//	struct sockaddr_in remote;
//	socklen_t len=sizeof(remote);
//
//	char buf[_SIZE_];
//
//	size_t ret=recvfrom(_sock,buf,sizeof(buf),0,(struct sockaddr*)&remote,&len);
//}
