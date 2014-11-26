#include "BankSession.h"
#include "../Public/Exception.h"
#include "../Public/Singleton.h"
#include "TransactionManager.h"
#include "../Public/MD5.h"
#include "../Public/Idea.h"
BankSession::BankSession(std::auto_ptr<Socket>& socket) : socket_(socket),isDead_(false)
{
	requestPack_ = (RequestPack *)buffer_;
}

BankSession::~BankSession()
{
}

void BankSession::Process(){
	Recv();
	DoAction();
}

void BankSession::Send(const char* buf, size_t len){
	socket_->SendN(buf, len);
}

void BankSession::Recv(){
	int ret;
	ret = socket_->RecvN(buffer_, sizeof(RequestHead));
	if(ret == 0){
		throw Exception("�ͻ��˹ر�");
	}
	else if(ret != sizeof(RequestHead)){
		throw Exception("�������ݰ�����");
	}
	uint16 cmd = Endian::NetworkToHost16(requestPack_->head.cmd);
	uint16 len = Endian::NetworkToHost16(requestPack_->head.len);


	ret = socket_->RecvN(buffer_ + sizeof(RequestHead), len);
	if(ret == 0){
		throw Exception("�ͻ��˹ر�");
	}
	else if(ret != len){
		throw Exception("�������ݰ�����");
	}

	unsigned char hash[16];
	MD5 md5;
	md5.MD5Make(hash, (unsigned char const*)buffer_, sizeof(RequestHead)+len-8);
	for(int i=0; i<8; ++i){
		hash[i] = hash[i] ^ hash[i+8];
		hash[i] = hash[i] ^ ((cmd >> (i%2)) & 0xff);
	}
	
	if(memcmp(hash, buffer_ + sizeof(RequestHead)+len-8, 8)){
		throw Exception("��������ݰ�");	
	}
	requestPack_->head.cmd = cmd;
	requestPack_->head.len = len;
}

void BankSession::DoAction(){
	Singleton<TransactionManager>::Instance().DoAction(*this);
}
