#include<stdio.h>
#include<fcntl.h>
void main()
{
	int ret;
	char str[20];
	printf("enter the name of the file\n");
	scanf("%s",str);
	ret=open(str,O_CREAT|O_RDWR,0664);
	if(ret>0)
	{
		printf("file successfully created\n");
	}
}
