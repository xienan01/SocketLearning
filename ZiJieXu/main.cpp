#include "stdio.h"
#include "stdlib.h"

#ifdef WIN32
#include "WinSock2.h"
#pragma comment(lib,"ws2_32.lib")
#else
#include "arpa/inet.h"
#endif

int main()
{
	 //x86默认是小端模式
	unsigned long byteorder = 0x12345678;
	unsigned char *p = (unsigned char*)&byteorder;
	printf("%0x,%0x,%0x,%0x\n\n",p[0],p[1],p[2],p[3]);
	//字节序转换函数 htons htonl ntohl ntohs
	//byte order changed to net order

    // 网络字节序默认是大端模式
	long newbyte = htonl(byteorder);
	p = (unsigned char*)&newbyte;
	printf("%0x,%0x,%0x,%0x\n\n",p[0],p[1],p[2],p[3]);

	long newnetbyte = ntohl(byteorder);
	p = (unsigned char*)&newnetbyte;
	printf("%0x,%0x,%0x,%0x\n\n",p[0],p[1],p[2],p[3]);
	system("pause");
	return 0;
}