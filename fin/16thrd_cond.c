//to print even and odd numbers simulatenously by using conditional variables
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
void *thread_fun1(void *);
void *thread_fun2(void *);
void main()
{
	pthread_t ti1,ti2;
	void *ptr;
	pthread_create(&ti1,NULL,thread_fun1,NULL);
	pthread_create(&ti2,NULL,thread_fun2,NULL);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *thread_fun1(void *ptr)
{
	int i;
	for(i=1;i<=30;i++)
	{
		pthread_cond_signal(&cond);
		pthread_mutex_lock(&mutex);
		if(i%2==0)
		{
		printf("even:%d\n",i);
		}
		pthread_cond_wait(&cond,&mutex);
		pthread_mutex_unlock(&mutex);
		sleep(1);
		
	//	pthread_exit(0);
	}
}
void *thread_fun2(void *ptr)
{
	int i;
	for(i=1;i<=30;i++)
	{
		pthread_cond_signal(&cond);
		pthread_mutex_lock(&mutex);
		if(i%2!=0)
		{
		printf("odd:%d\n",i);
		}
		pthread_cond_wait(&cond,&mutex);
		pthread_mutex_unlock(&mutex);
		sleep(1);
		

	}
//	exit(0);
	pthread_exit(0);
}
