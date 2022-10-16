#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
	int i,j;
	char *argv[20];
	char cmd[20];
	printf("enter name of command to change the process image\n");
	scanf("%[^\n]s",cmd);
	__fpurge(stdin);
	argv[0]=cmd;
	for(i=0,j=1;cmd[i]!='\0';i++)
	{
		if(cmd[i]==' ')
		{
			cmd[i]='\0';
			argv[j]=&cmd[i+1];
			//i++;
			j++;
		}
	}
	argv[j]=0;
	mysys(argv);
}
int mysys(char **argv)
{
	int ret,x,i;
	pid_t pid;
	pid=fork();
	if(pid>0)
	{//child
		ret=wait(&x);
	  	printf("child process:%d\n",getpid());
		//execvp(argv[0],argv);
		return 0;
	}
	else
	{
		printf("parent process:%d\n",getpid());
		execvp(argv[0],argv);
	}
}




