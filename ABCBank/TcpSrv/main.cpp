#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <process.h>
using namespace std;
#include "JThread.h"

class ServiceThread:public JThread{
public:
	ServiceThread(SOCKET conn):conn_(conn){
		cout << "ServiceThread..." << endl;
	}
	~ServiceThread(){
		cout << "~ServiceThread..." << endl;

	}
	void Run(){
		char buf[1024] = {0};
		while(1){
			int ret = recv(conn_,buf,sizeof(buf),0);
			if(SOCKET_ERROR == ret){
				cout << "error with code = " << WSAGetLastError() << endl;
				exit(1);
			}
			if(0 == ret){
				cout << "client close" << endl;
				break;
			}
			if(ret > 0){
				cout << buf << endl;
				send(conn_,buf,strlen(buf),0);
			}
			memset(buf, 0, sizeof(buf));
		}
		closesocket(conn_);


	}
private:
	SOCKET conn_;
};


//unsigned _stdcall do_service(void* p){
//	int conn = (SOCKET)p;
//	char buf[1024] = {0};
//	while(1){
//		int ret = recv(conn,buf,sizeof(buf),0);
//		if(SOCKET_ERROR == ret){
//			cout << "error with code = " << WSAGetLastError() << endl;
//			exit(1);
//		}
//		if(0 == ret){
//			cout << "client close" << endl;
//			break;
//		}
//		if(ret > 0){
//			cout << buf << endl;
//			send(conn,buf,strlen(buf),0);
//		}
//		memset(buf, 0, sizeof(buf));
//	}
//	closesocket(conn);
//	return 0;
//}

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

	SOCKET listenfd;
	listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(INVALID_SOCKET == listenfd){
		cout << "error with code = " << WSAGetLastError() << endl;
		exit(1);
	}

	sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//servaddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(8888);

	int ret;
	int opt = 1;
	ret = setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));
	ret = bind(listenfd, (sockaddr*)&servaddr, sizeof(servaddr));
	if(ret == SOCKET_ERROR){
		cout << "error with code = " << WSAGetLastError() << endl;
		exit(1);
	}

	ret = listen(listenfd, SOMAXCONN);
	if(ret == SOCKET_ERROR){
		cout << "error with code = " << WSAGetLastError() << endl;
		exit(1);
	}

	sockaddr_in peeraddr;
	int peerlen;
	SOCKET conn;
	while(1){
		peerlen = sizeof(peeraddr);
		conn = accept(listenfd, (sockaddr*)&peeraddr, &peerlen);
		if(conn == SOCKET_ERROR){
			cout << "error with code = " << WSAGetLastError() << endl;
			exit(1);
		}

		cout << inet_ntoa(peeraddr.sin_addr) << " " << ntohs(peeraddr.sin_port) << endl;
		//unsigned threadId;
		//HANDLE hThread = (HANDLE)_beginthreadex(NULL,0,do_service,(void*)conn,0,&threadId);
		//if(NULL == hThread){
		//	cout << "error with code = " << GetLastError() << endl;
		//	exit(1);
		//}
		//CloseHandle(hThread);
		
		ServiceThread* t = new ServiceThread(conn);
		t->SetAutoDel(true);
		t->Start();
	}
	WSACleanup();

	return 0;
}