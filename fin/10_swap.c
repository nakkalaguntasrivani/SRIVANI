#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void main()
{
	int ret,ret1,fd1,fd2;
	char buf1[1024],buf2[1024];
	fd1=open("a.txt",O_RDWR);
	fd2=open("b.txt",O_RDWR);
	ret=read(fd1,buf1,1024);
	printf("before swap a.txt:%s\n",buf1);
	printf("before swap b.txt:%s\n",buf2);
	ret1=read(fd2,buf2,1024);
	printf("after swap a.txt:%s\n",buf2);
	printf("after swap b.txt:%s\n",buf1);
	buf1[ret]='\0';
	buf2[ret]='\0';
	write(fd1,buf2,1024);
	write(fd2,buf1,1024);
}
