#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
void *thread_fun1(void *);
void *thread_fun2(void *);
int glob=0;
void main()
{
	pthread_t ti1,ti2;
	int *ptr;
	pthread_create(&ti1,NULL,thread_fun1,NULL);
	pthread_create(&ti2,NULL,thread_fun2,NULL);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *thread_fun1(void *ptr)
{
	int i,loc=0;
//	pthread_mutex_lock(&mutex);
	for(i=1;i<=30;i++)
	{
	//	sleep(1);
		pthread_mutex_lock(&mutex);
		if(i%2==0)
		{
		printf("even:%d\n",i);
	//		i++;
	//	pthread_cond_signal(&cond);
		pthread_cond_wait(&cond,&mutex);
		}
	//	else
	//	{
	//	pthread_cond_wait(&cond,&mutex);
		loc=glob;
		loc++;
		glob=loc;
		pthread_mutex_unlock(&mutex);
	//	}
	}
//	pthread_cond_signal(&cond);
//	pthread_exit(0);
}
void *thread_fun2(void *ptr)
{
	int i,loc=0;
	//pthread_mutex_lock(&mutex);
	for(i=1;i<=30;i++)
	{
		//sleep(1);
		pthread_mutex_lock(&mutex);
		if(i%2!=0)
		{
		printf("odd:%d\n",i);
		i++;
		pthread_cond_wait(&cond,&mutex);
		}
	//	else
	//	{
		loc=glob;
		loc++;
		glob=loc;	
		pthread_mutex_unlock(&mutex);
	//	}
	}
//	pthread_cond_broadcost(
//	pthread_exit(0);
}
