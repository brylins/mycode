#include "WINSOCK2.h"
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <iostream.h>

//工程-设置-连接-添加ws2_32.lib


#define STR_MAX_LEN 1000
bool dataNeedToSendFlag = false;
char sendBuffer[STR_MAX_LEN];

int writeSendBuffer(int *i)
{
	while(1)
	{
		//scanf("%[^\n]", sendBuffer);
		fgets(sendBuffer,STR_MAX_LEN,stdin);
		dataNeedToSendFlag = true;
		printf(":%s\n", sendBuffer);
	}
	return 0;
}


void receicedFromsSocket()
{
	int err;	
	WSADATA wsaData;
	WORD wVersionRequested;
	char recvBuf[STR_MAX_LEN];
	
	wVersionRequested = MAKEWORD(1, 1);
	err = WSAStartup(wVersionRequested, &wsaData);

	if(err != 0) 
	{
		return;
	}
	
	if(LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) 
	{
		WSACleanup();
		return; 
	}

	SOCKET sockClient=socket(AF_INET, SOCK_STREAM, 0);
		
	unsigned long ul=1;
	ioctlsocket(sockClient, FIONBIO, (unsigned long *)&ul); 
 
	SOCKADDR_IN addrSrv;
	addrSrv.sin_family=AF_INET;	
	addrSrv.sin_port=htons(50000);
    addrSrv.sin_addr.S_un.S_addr=inet_addr("10.57.233.197");
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	while(1)
	{
		if(dataNeedToSendFlag)
		{
			dataNeedToSendFlag = false;
			printf("send\n");
			send(sockClient, sendBuffer, strlen(sendBuffer) + 1, 0);		
		}

		memset(recvBuf, STR_MAX_LEN, 0);
		int ret = recv(sockClient, recvBuf, 100, 0);
		
		if(ret > 0)
		{
			printf("\nret=%d %s\n", ret, recvBuf);
		}
		Sleep(1000);
	}
	
 

 
	//closesocket(sockClient);
	//WSACleanup();
	getchar(); 
}

 
int main(int argc, char* argv[])
{
	int m=1;
	int n=2;
	HANDLE hThread1;
    HANDLE hThread2;
	
	hThread1 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)receicedFromsSocket, &m, 0, NULL);
	hThread2 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)writeSendBuffer, &n, 0, NULL);
	
	while(1)
	{
		Sleep(10000);	
	}

	
	TerminateThread(hThread1,1);
    TerminateThread(hThread2,1);
	
	CloseHandle(hThread1);
    CloseHandle(hThread2);
	return 0;

}
