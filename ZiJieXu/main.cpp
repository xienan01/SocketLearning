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
	 //x86Ĭ����С��ģʽ
	unsigned long byteorder = 0x12345678;
	unsigned char *p = (unsigned char*)&byteorder;
	printf("%0x,%0x,%0x,%0x\n\n",p[0],p[1],p[2],p[3]);
	//�ֽ���ת������ htons htonl ntohl ntohs
	//byte order changed to net order

    // �����ֽ���Ĭ���Ǵ��ģʽ
	long newbyte = htonl(byteorder);
	p = (unsigned char*)&newbyte;
	printf("%0x,%0x,%0x,%0x\n\n",p[0],p[1],p[2],p[3]);

	long newnetbyte = ntohl(byteorder);
	p = (unsigned char*)&newnetbyte;
	printf("%0x,%0x,%0x,%0x\n\n",p[0],p[1],p[2],p[3]);
	system("pause");
	return 0;
}