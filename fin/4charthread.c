//to print small lettes in one thread and capital letter in another thread
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
char str[100];
void *thread_fun1(void *ptr);
void *thread_fun2(void *ptr);
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
void main()
{
	
	pthread_t ti1,ti2;
	int *ptr;
	printf("Enter the string:\n");
        scanf("%[^\n]s",str);
	pthread_create(&ti1,NULL,thread_fun1,&str);
	pthread_create(&ti2,NULL,thread_fun2,&str);
//	pthread_mutex_lock(&mutex);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *thread_fun1(void *ptr)
{
	int i;
	printf("hai\n");
	for(i=0;str[i]!='\0';i++)
	{
		sleep(1);
		pthread_mutex_lock(&mutex);
		if(str[i]>=65 && str[i]<=90)
			printf("Thread 1 :%c\n",((char *)ptr)[i]);
		pthread_mutex_unlock(&mutex1);
	}
}
void *thread_fun2(void *ptr)
{
	int i;
	printf("bye\n");
	for(i=0;str[i]!='\0';i++)
	{
		sleep(1);
		pthread_mutex_lock(&mutex1);
		if(str[i]>=97 && str[i]<=122)
			printf("Thread 2 :%c\n",((char *)ptr)[i]);
		
		pthread_mutex_unlock(&mutex);
	}
}



