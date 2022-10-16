#include<stdio.h>
#include<fcntl.h>
#include<sys/sem.h>
#include<sys/shm.h>
#define KEY 0x19980
void main()
{
	struct sembuf sem;
	char *ptr,*addr;
	int shmid,semid;
	shmid=shmget(KEY,100,IPC_CREAT|0640);
	addr=shmat(shmid,NULL,0);
	semid=semget(KEY,2,IPC_CREAT|0640);
	semctl(semid,0,SETVAL,0);
	semctl(semid,1,SETVAL,0);

	sem.sem_num=0;
	sem.sem_op=-1;
	sem.sem_flg=0;

	semop(semid,&sem,1);
	printf("%s\n",addr);

	sem.sem_num=1;
	sem.sem_op=1;
	sem.sem_flg=0;

	scanf("%s",&addr[50]);
	semop(semid,&sem,1);
}
	


