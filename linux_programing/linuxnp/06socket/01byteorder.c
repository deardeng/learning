#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, const char *argv[])
{
    unsigned int x = 0x12345678;
    unsigned char *p = (unsigned char*)&x;
    printf("%0x %0x %0x %0x\n",p[0],p[1],p[2],p[3]);

    unsigned int y = htonl(x);
    p = (unsigned char*)&y;
    printf("%0x %0x %0x %0x\n",p[0],p[1],p[2],p[3]);
    return 0;
}
