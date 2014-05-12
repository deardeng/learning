#include <iostream>
using namespace std;
#include <fstream>
void encode(char* buf, int bytes)
{
	for(int i=0; i<bytes; i++)
		++*buf++;
}
void decode(char* buf, int bytes)
{
	for(int i=0; i<bytes; i++)
		--*buf++;
}
int main(int argc, char* argv[])
{//用法: a.out -e|-d 文件路径
	if(argc!=3||strcmp(argv[1],"-e")&&strcmp(argv[1],"-d")){
		cout << argv[0] << " -e|-d 文件" << endl;
		return 0;
	}
	fstream f1(argv[2],ios::binary|ios::in|ios::out);
	if(!f1){
		cout << "打开" << argv[2] << "文件失败" << endl;
		return 1;
	}
	bool buf[100];
	void(*p)(char*,int) = argv[1][1]=='e'?encode:decode;
	int pos1=0, pos2, bytes;
	bool ok = true;
	while(ok){
		f1.seekg(pos1);//f1.seekg(pos1,ios::beg);
		f1.read((char*)buf,sizeof(buf));
		if(!f1){
			f1.clear();
			ok = false;
		}
		else
			pos2 = f1.tellg();
		bytes = f1.gcount();
		p((char*)buf,bytes);
		cout.write((char*)buf,bytes);
		f1.seekp(pos1);//f1.seekp(-bytes,ios::cur);
		f1.write((char*)buf,bytes);//不要用sizeof(buf)
		pos1 = pos2;
	}
	//f1.close();
}
