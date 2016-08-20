#include"udp_server.h"

const string IP="127.0.0.1";
const int PORT=8080;
const int _SIZE_=1024;

Server::Server()
	:_ip(IP)
	 ,_port(PORT)
	 ,_sock(-1)
{}

Server::~Server()
{
	if(_sock!=-1)
		close(_sock);
}

void Server::Init()
{
	//创建套接字
	_sock=socket(AF_INET,SOCK_DGRAM,0);
	if(_sock<0)
	{
		perror("sock()");
		cout<<__func__<<":"<<__LINE__<<endl;
		exit(0);
	}

	//初始化套接字
	struct sockaddr_in local; 

	local.sin_family=AF_INET;
	local.sin_port=htons(_port);
	local.sin_addr.s_addr=inet_addr(_ip.c_str());

	//绑定
	if(bind(_sock,(struct sockaddr*)&local,sizeof(local))<0)
	{
		perror("bind()");
		cout<<__func__<<":"<<__LINE__<<endl;
		exit(1);
	}
}
size_t Server::get_msg(string& msg)
{
	char buf[_SIZE_];
	struct sockaddr_in cli;
	socklen_t len=sizeof(cli);
	size_t ret=recvfrom(_sock,buf,sizeof(buf)-1,0,(struct sockaddr*)&cli,&len);
	if(ret<0)
	{
		perror("recvfrom()");
		cout<<__func__<<":"<<__LINE__<<endl;
		exit(2);
	}
	else
	{
		buf[ret]='\0';
		msg=buf;
	}


}

