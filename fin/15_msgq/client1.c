#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#define MSG_TYPE 1
#define KEY 0X11111111
int main()
{
        char rbuf[50],wbuf[50];
        int msqid,ret;
	((long int *)wbuf)[0]=MSG_TYPE;
	((long int *)wbuf)[1]=getpid();
	printf("getpid:%d\n",getpid());
	strcpy(&wbuf[16],"hello");
        msqid=msgget(KEY,0);
//	while(1)
//	{
	msgsnd(msqid,wbuf,16+strlen(&wbuf[16])+1,0);
	msgrcv(msqid,rbuf,40,getpid(),0);
	printf("parent:%s\n",&rbuf[8]);
//	}
}
