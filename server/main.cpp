#include"udp_server.h"


int main(int argc,char* argv[])
{
	Server ser;
	ser.Init();
	string msg;
	while(1)
	{
		ser.get_msg(msg);
		cout<<msg<<endl;
		sleep(2);
	}

	return 0;
}

