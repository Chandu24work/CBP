#include<stdio.h>
#include <unistd.h>
int main(){
	int pid, retnice;
	printf("pres DEL to stop process\n");
	pid=fork();
	for(;;){
		if (pid==0){
			retnice = nice(-5);// to change the priority of the process -20 highest 19 lowest
			printf("child gets higherCPU priortity%d\n",retnice);
			sleep(10);
		}
		else{
			retnice=nice(4);
			printf("Parent gets lower CPU priority%d\n",retnice);
			sleep(10);
		}
}
}
