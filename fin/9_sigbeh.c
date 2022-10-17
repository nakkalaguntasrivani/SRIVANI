//9.change the signal behaviour
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void myhandler(int signo);
void main()
{
	int signo;
	printf("enter the signal number:");
	scanf("%d",&signo);
	signal(signo,myhandler);
	while(1)
	{
	
		printf("helooooo");

	}
}
void myhandler(int signo)
{
	printf("received signal-%d\n",signo);
}
