#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void ChildProcess();
void ParentProcess();
int main(){
	pid_t pid; // pid_t is a data type used to represent the process id 
	pid=fork(); // to create a new child process
	if(pid == 0){
		printf("the process id is %d\n",pid);
		ChildProcess();
	}
	else{
		printf("the process id is %d\n",pid);
		ParentProcess();
	}
}

void ChildProcess(){
	printf("I am child process\n");
}

void ParentProcess(){
	printf("I am parent process\n");
}

