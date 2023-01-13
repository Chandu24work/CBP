#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    if (pid < 0) {
        printf("Error calling pid\n");
    }
    else if (pid == 0) {
        printf(" In Child process,my pid is=%d\n",getpid());
        printf("In child process ,my Parent PID: %d\n", getppid());
        sleep(5);
	printf("Parent process is terminated\n");
        printf("\n In Child process,my pid= %d\n",getpid());
        printf(" In child process,My Parent PID: %d\n", getppid());
    }
    else {
        printf("In Parent process,my pid=%d\n",getpid());
	sleep(2);
	printf("Parent Process is terminated\n");
    }

    return 0;
}
