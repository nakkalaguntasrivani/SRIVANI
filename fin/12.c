//send message from parent to child
#include<stdio.h>
#include<unistd.h>
#include<string.h>
void main()
{
	int ret,ret1,len;
	pid_t pid;
	char buf[50],buf1[50];
	char rbuf[50],wbuf[50];
	int fd1[2];
	int fd2[2];
	ret=pipe(fd1);
	ret1=pipe(fd2);
	pid=fork();   //to create child process
	if(pid>0)   //parent
	{
		while(1)
		{
		close(fd1[0]);
		printf("message to child:\n");
		scanf("%[^\n]s",wbuf);
		__fpurge(stdin);
		ret=write(fd1[1],wbuf,strlen(wbuf));
		close(fd2[1]);
		ret1=read(fd2[0],rbuf,50);
		rbuf[ret1]='\0';
		printf("parent message:%s\n",rbuf);
		}
	}
	else
	{
		while(1)
		{

			close(fd1[1]);       //child
                	ret=read(fd1[0],buf,50); //blocking call
                	buf[ret]='\0';
			printf("child msg:%s\n",buf);
			close(fd2[0]);
			printf("message to parent\n");
			scanf("%[^\n]s",buf1);
			__fpurge(stdin);
			write(fd2[1],buf1,strlen(buf1));
		}
	}
}

