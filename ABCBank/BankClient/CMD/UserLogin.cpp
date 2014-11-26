#include "UserLogin.h"

#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"
#include "../../Public/JinStream.h"
#include "../../Public/JOutStream.h"


using namespace PUBLIC;
using namespace CMD;

void UserLogin::Execute(BankSession& session){
	JOutStream jos;

	
	uint16 cmd = CMD_LOGIN;
	jos << cmd;

	size_t lengthPos = jos.Length();
	jos.Skip(2);
	string name = session.GetAttribute("name");
	jos << name;

	string pass = session.GetAttribute("pass");


	unsigned char ideaKey[16];
	unsigned char buf[2];
	buf[0] = (cmd >> 8) & 0xff;
	buf[1] = cmd & 0xff;
	MD5 md5;
	md5.MD5Make(ideaKey, buf, 2);

	for(int i=0; i<8; ++i){
		ideaKey[i] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i] = ideaKey[i] ^ ((cmd >> (i%2)) & 0xff);
		ideaKey[i+8] = ideaKey[i] ^ ideaKey[i+8];
		ideaKey[i+8] = ideaKey[i+8] ^ ((cmd >> (i%2)) & 0xff);
	}

	char encryptedPass[16];

	Idea idea;
	idea.Crypt(ideaKey, (const unsigned char*)pass.c_str(), (unsigned char *)encryptedPass, 16, true);
	
	jos.WriteBytes(encryptedPass, 16);
	
	size_t tailPos = jos.Length();
	jos.Reposition(lengthPos);
	jos << static_cast<uint16>(tailPos + 8 -sizeof(RequestHead));
	
	jos.Reposition(tailPos);

	unsigned char hash[16];
	md5.MD5Make(hash, (const unsigned char*)jos.Data(), jos.Length());
	for(int i = 0; i<8; ++i){
		hash[i] = hash[i] ^ hash[i + 8];
		hash[i] = hash[i] ^ ((cmd >> (i%2)) & 0xff);
	}
	jos.WriteBytes(hash, 8);
	

	session.Send(jos.Data(), jos.Length());
	session.Recv();
	JInStream jis((const char*)session.GetResponsePack(), session.GetResponsePack()->head.len + sizeof(ResponseHead));
	jis.Skip(4);
	uint16 cnt;
	uint16 seq;
	int16 error_code;
	jis >> cnt >> seq >> error_code;

	char error_msg[31];
	jis.ReadBytes(error_msg, 30);

	session.SetErrorCode(error_code);
	session.SetErrorMsg(error_msg);
}