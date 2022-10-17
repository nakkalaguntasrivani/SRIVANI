#####################################################################
1. A PROGRAM TO CHANGE PROCESS IMAGE BY USING EXEC FAMILY CALLS

header file:
		#include<unistd.h>

system calls: 
		fork()
		execvp()

return values:
		fork() system calls on success creates child process.(returns-->pid of the child process)
		execvp() system call on success it creates new process image(it does not have any return value)	
			
In this program to change the process image of the process we are using one of the exec family call member execvp() which takes two arguments( one is path of the file being executed and other is array of character pointer). process image is changing by using following commands like ps -af,ps, ps -ax






#############################################################################
2. A PROGRAM TO PRINT TWO THREADS SIMULTANEOUSLY BY USING MUTEX

header files:   <pthread.h>
		<unistd.h>

system calls:  pthread_create
		pthread_join

return values:
		for pthread_create() system call on success it returns 0 and new thread is created.
pthread_join() system call will act as the blocking call and will block until the thread terminates.


in this program two threads are created by the pthread system calls. for printing the threads simulataneously we are  using mutex locks where this lock is set, then no other threads will access it(avoid race condition).
###############################################################################

3. A PROGRAM TO IMPLEMENT YOUR KILL COMMAND












#######################################################################################

4. A PROGRAM TO PRINT SMALL CHARACTERS IN ONE THREAD & CAPITAL LETTERS IN OTHER THREAD FOR A GIVEN STRING

header files:   #include<pthread.h>
		#include<string.h>

system calls: 
		pthread_create()
		pthread_join()

return values: 
		pthread_create() system call on success returns 0 and create new thread
and on failure it return negative value.
		pthread_join() system call on success returns 0 and acts as blocking call until the thread terminates.

DESCRIPTION:
In this program we are creating two threads by using pthread_create, mutex-locks are created so that threads will prints simulatenously. here one thread is used to print small characters and other thread is for capital letter. 
############################################################################################

5.A PROGRAM ON CREATING AND DELETING THE DIRECTORY 

header files:
		#include<sys/stat.h>

system call:
		mkdir();
		rmdir();
return value:
		mkdir() system call on success returns 0 and creates a new directory and on failure it returns -1.
		rmdir() system call on success it removes the directory from the filesystem

DESCRIPTION:
In this program we are creating and deleting the directory from the file system by using mkdir and rmdir system calls. to create the directory we use mkdir system call where we are passing two arguments one is directory path and other is permission(flags) to that directory and in rmdir system call we are only passing the path of the directory, which we want to remove.

###############################################################################################

7. A PROGRAM TO IMPLEMENT YOUR OWN LS COMMAND

header files: 
		#include<dirent.h>//the internal format of directories is unspecified and following data type through typedef

system calls:
		opendir();
		DIR *opendir(const char *name);
       		DIR *fdopendir(int fd);

return values:
		on success it returns a pointer to a DIR object and opens a directory stream corresponding to the directory name and on failure it returns NULL.

DESCRIPTION:
In this program we are implementing our own ls command by using opendir() function. by using DIR *fd we are accessing opendir() function which we are taking current directory as structure is pre_defined for dirent header file we can directly access the directiory files.

###################################################################################################

8.A PROGRAM TO CREATE A FILE WITHOUT USING CREATE SYSTEM CALL

header file:
		#include<fcntl.h>

system calls:
           int open(const char *pathname, int flags, mode_t mode);

return values:
		open() system call on success returns the fd of the file and on failure it returns -1

DESRIPTION:
In this program we are creating a file by using open system call instead of using create system call.here we are passing name of the file as first argument, flags (O_CREAT|O_RDWR) in 2nd argument and 3rd is the permissions of that file.
by this a file is created.

##################################################################################################

9.A PROGRAM TO CHANGE THE SIGNAL BEHAVIOUR

header file:
		#include<signal.h>
system calls:
		sighandler_t signal(int signum, sighandler_t handler); 
		signal();
return values:
		on success it returns the previous value of the signal handler and on failure it returns SIG_ERR.

DESRIPTION:
In this we are signal() function in first argument we are passing signo which is taken from user and 
2nd is myhandler function.
#################################################################################


 












































