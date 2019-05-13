/**
 * description: an echo_server_net server
 * author:      xienan
 * time:        20190425
 *
 **/
#include "iostream"
#include "stdio.h"
#include "stdlib.h"

#ifdef WIN32
#include "WinSock2.h"
#pragma comment(lib, "wc2_32.lib")
#else
#include "sys/socket.h"
#endif

int main()
{
	//需要初始化
	WORD sockVersion = MAKEWORD(2, 2);
    WSADATA wsdata;
    if (WSAStartup(sockVersion, &wsdata) != 0)
    {
        return 1;
    }
	//int echo_server_fd =0;
	SOCKET echo_server_fd = socket(PF_INET,SOCK_STREAM,0);
	if(echo_server_fd == 0)
	{
		std::cout << "init socket OK!" << std::endl;
	}
	else
	{
		std::cout << "init socket OK!" << std::endl;
		exit(0);
	}
	struct sockaddr_in addr_in;
	addr_in.sin_family = PF_INET; 
	addr_in.sin_port = htons(55555);
	addr_in.sin_addr.S_un.S_addr = htons(INADDR_ANY);
	int errcode = bind(echo_server_fd, (sockaddr*)&addr_in, sizeof(addr_in));
	if(errcode !=0)
	{
	std::cout << "bind failed!" << std::endl;
	exit(0);
	}

	errcode = listen(errcode,SOMAXCONN);
	if(!errcode)
	{
		std::cout << "listen failed" << std::endl;
		exit(0);
	}
	struct sockaddr_in sockadd;
	int sockadd_len = sizeof(sockadd);
	int flag = 0;
    SOCKET err = accept(errcode,(sockaddr *)&sockadd, &sockadd_len);
	if(err == 0)
	{
	flag =1;
	}
	else
	{
	std::cout << "accept failed" << std::endl; 
	exit(0);
	}

	char ReciveBuffer[1024];
	while(1)
	{
		memset(ReciveBuffer,0, sizeof(ReciveBuffer));

		if(flag ==1)
		{
			err = recv(err, ReciveBuffer, sizeof(ReciveBuffer),flag);
		}
		else
		{
			std::cout << "Waiting Connect ......" << std::endl;
		}
	}
	

return 0;
}