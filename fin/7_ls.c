#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
void main()
{
	DIR *fd;
	struct dirent *p;
	char str[12];
	fd=opendir(".");
	if(fd==NULL)
	{
		printf("directory opening failed\n");
		exit(-1);
	}
	while(p=readdir(fd))
		printf("%s\n",p->d_name);
}

