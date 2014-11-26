#include "UserLogin.h"

#include "../DAL/BankService.h"
#include "../../Public/Logging.h"
#include "../../Public/JUtil.h"
#include "../../Public/JinStream.h"
#include "../../Public/JOutStream.h"

using namespace PUBLIC;
using namespace CMD;
using namespace DAL;
void UserLogin::Execute(BankSession& session){
    JInStream jis(session.GetRequestPack()->buf,session.GetRequestPack()->head.len);
    uint16 cmd = session.GetCmd();
    string name;
	jis >> name;

	char pass[16];
	unsigned char ideaKey[16];
	unsigned char buf[2];
	buf[0] = (cmd >> 8)& 0xff;
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
	jis.ReadBytes(encryptedPass,16);
	Idea idea;
	idea.Crypt(ideaKey, (const unsigned char*)encryptedPass, (unsigned char *)pass, 16, false);
	

    int16 error_code = 0;
    char error_msg[31] = {0};

	BankService dao;
	int ret;
	ret = dao.UserLogin(name, pass);
	if(ret == 0){
		LOG_INFO << "登录成功";
	}
	else if(ret == 1){
		error_code = 1;
		strcpy_s(error_msg,  "用户名或密码错误");
		LOG_INFO << error_msg;

	}
	else if(ret == -1)
	{
		error_code = -1;
		strcpy_s(error_msg,  "数据库错误");
		LOG_INFO << error_msg;
	}
    JOutStream jos;
    jos << cmd;
    size_t lengthPos = jos.Length();
    jos.Skip(2);
    uint16 cnt = 0;
    uint16 seq = 0;
    jos << cnt << seq << error_code;
    jos.WriteBytes(error_msg, 30);

	size_t tailPos = jos.Length();
	jos.Reposition(lengthPos);
	jos << static_cast<uint16>(tailPos + 8 -sizeof(ResponseHead));

	jos.Reposition(tailPos);

	unsigned char hash[16];
	md5.MD5Make(hash, (const unsigned char*)jos.Data(), jos.Length());
	for(int i = 0; i<8; ++i){
		hash[i] = hash[i] ^ hash[i + 8];
		hash[i] = hash[i] ^ ((cmd >> (i%2)) & 0xff);
	}
	jos.WriteBytes(hash, 8);

    session.Send(jos.Data(), jos.Length());
}
