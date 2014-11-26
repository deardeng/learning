#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
using namespace std;

int main(void){
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD( 2, 2 );

	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {
		return 1;
	}

	if ( LOBYTE( wsaData.wVersion ) != 2 ||
		HIBYTE( wsaData.wVersion ) != 2 ) {
			WSACleanup( );
			return 1; 
	}

	SOCKET sock;
	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(INVALID_SOCKET == sock){
		cout << "error with code = " << WSAGetLastError() << endl;
		exit(1);
	}

	sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//servaddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(8888);

	int ret;
	ret = connect(sock, (sockaddr*)&servaddr, sizeof(servaddr));
	if(-1 == ret){
		cout << "error with code = " << WSAGetLastError() << endl;
		exit(1);
	}

	char buf[1024] = {0};
	char recvbuf[1024] = {0};
	while(1){
		cin >> buf;
		if(strcmp(buf,"quit") == 0){
			break;
		}

		ret = send(sock, buf, strlen(buf), 0);
		if(-1 == ret){
			cout << "error with code = " << WSAGetLastError() << endl;
			exit(1);
		}
		ret = recv(sock,recvbuf,sizeof(recvbuf),0);
		if(-1 == ret){
			cout << "error with code = " << WSAGetLastError() << endl;
			exit(1);
		}
		if(0 == ret){
			cout << "server close" << endl;
			break;
		}
		if(ret > 0){
			cout << recvbuf << endl;
		}
		memset(buf, 0, sizeof(buf));
		memset(recvbuf, 0, sizeof(recvbuf));
	}

	closesocket(sock);
	return 0;

}
