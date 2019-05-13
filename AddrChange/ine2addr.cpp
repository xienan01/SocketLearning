/**
 * description: inet_addr changed
 * author:      xienan
 * time:        20190425
 *
 **/

#include "stdio.h"
#include "stdlib.h"

#ifdef WIN32
#include "WinSock2.h"
#pragma comment(lib,"ws2_32.lib")
#else
#include "netinet/in.h"

#endif


int main()
{
	//ת����32λ�������ַ
	char* addr = "192.168.1.110";
	unsigned long newaddr = inet_addr(addr);
	printf("%u\n",newaddr);

	//ת��������ģʽ���
	unsigned long addrnew = ntohl(newaddr);
	printf("%u\n",addrnew);

	//�����ַת����ʱ�ֵ�ַ
	struct in_addr in;
	in.S_un.S_addr = newaddr;
	char* p = inet_ntoa(in);
	printf("%s\n",p);

	struct in_addr address;
	address.S_un.S_addr = inet_addr(INADDR_ANY);  //�����ַ
	printf("%s\n", inet_ntoa(address));
	system("pause");
	return 0;
}