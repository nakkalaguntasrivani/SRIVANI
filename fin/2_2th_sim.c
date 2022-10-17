//printing two threads simultaneously by using mutex
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2=PTHREAD_MUTEX_INITIALIZER;
int r,i;
void *thread_fn1(void);
void *thread_fn2(void);
void main()
{
	int *ptr;
	printf("enter the range upto:");
	scanf("%d",&r);
	pthread_t ti1,ti2;
	pthread_create(&ti1,NULL,thread_fn1,NULL);
	pthread_create(&ti2,NULL,thread_fn2,NULL);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *thread_fn1(void)
{
	for(i=0;i<r;i++)
	{
	//	sleep(1);
		pthread_mutex_lock(&mutex1);
		printf("function-1:%d\n",i);
		pthread_mutex_unlock(&mutex2);
		
	}
}

void *thread_fn2(void)
{
	for(i=0;i<r;i++)
	{
		sleep(1);
		pthread_mutex_lock(&mutex2);
		printf("function-2:%d\n",i);
		pthread_mutex_unlock(&mutex1);
		
	}
}


