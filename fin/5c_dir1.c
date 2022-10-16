//creating and deleting directory
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
void main()
{
	int ret,ret1,op;
//	char dir_nam[20];
	printf("0.exit\t 1.create_dir\t2.delete_dir\nEnter the option:\n");
	while(1)
	{
		scanf("%d",&op);
		switch(op)
		{
			case 0:
				exit(0);
				
			case 1:
			
			char dir_nam[20];
			printf("enter the name of directory\n");
			scanf("%s",dir_nam);
			ret=mkdir(dir_nam,0660);
			printf("ret:%d\n",ret);
			break;
			case 2:
			printf("enter the name of the directory to be removed\n");
			scanf("%s",dir_nam);
			ret1=rmdir(dir_nam);
			printf("ret1:%d\n",ret1);
			break;
		}
	}
}
