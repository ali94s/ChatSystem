#include"udp_client.h"


int main(int argc,char* argv[])
{

	Client cli(argv[1],atoi(argv[2]));

	cli.Init();
	while(1)
	{
		string msg;
		cin>>msg;
		cli.send_msg(msg);
		sleep(1);
	}
	return 0;
}
