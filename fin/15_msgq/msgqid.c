#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#define MSG_TYPE 1
#define KEY 0X11111111
int main()
{
	char rbuf[50],wbuf[50];
	int msqid,ret;
	msqid=msgget(KEY,IPC_CREAT|0664);
	printf("msgget:%d\n",msqid);
        ret=msgrcv(msqid,rbuf,40,MSG_TYPE,0);
	printf("msgrcv:%d\n",ret);
	printf("rbuf1:%ld\n",((long int *)rbuf)[0]);
	printf("rbuf2:%ld\n",((long int *)rbuf)[1]);
	printf("rbuf3:%s\n",&rbuf[16]);
	((long int *)wbuf)[0]=((long int *)rbuf)[1];
	strcpy(&wbuf[8],"hi");
	printf("server reply:msgtype= %ld\n",((long int *)wbuf)[0]);
	printf("server reply:message= %s\n",&wbuf[8]);
	msgsnd(msqid,wbuf,8+strlen(&wbuf[8])+1,0);
//	}
	msgctl(msqid,IPC_RMID,0);

	
}
