//implement kill command
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int signo;
	printf("enter the signo:");
	scanf("%d",&signo);
	pid_t pid;
	while(1)
	{
	printf("pid:%d\n:",getpid());
	}
	kill(pid,signo);

}
	
