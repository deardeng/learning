#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/mman.h>

struct stu{
    char name[20];
    int age;
    float score;
};

int main(){
    int count;
    int fd;
    struct stu *s;
    struct stat st;
    int size;
    int i;

    fd=open("newstu.dat",O_RDWR|O_CREAT|O_EXCL,0666);
    if(fd==-1){
        fd=open("newstu.dat",O_RDWR);
        if(fd==-1)printf("::%m\n"),exit(-1);
    }

    fstat(fd,&st);
    size=st.st_size;
    count=size/sizeof(struct stu);

    //ftruncate(fd,size+sizeof(struct stu));

    s=mmap(0,size+sizeof(struct stu),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

    //printf("input name:");
    //scanf("%s",s[count].name);
    //printf("input age:");
    //scanf("%d",&(s[count].age));
    //printf("input score:");
    //scanf("%f",&(s[count].score));
    //ftruncate(fd,size+sizeof(struct stu));

    for(i=0;i<count;i++){
        printf("%s,\t,%d,\t%.2f\n",s[i].name,s[i].age,s[i].score);
    }

    munmap(s,sizeof(struct stu)+size);
    close(fd);
}
