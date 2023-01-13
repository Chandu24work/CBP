#include <stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	int n,i,j,key,temp;
	int a[10];
	pid_t pid;
	printf("ENter how many elements you want:\n");
	scanf("%d",&n);
	printf("Enter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	pid=fork();
	if(pid==0) // child process
	{
		for(i=1;i<n;i++) // 12 4 5 10 13
		{
			key=a[i];
			j=i-1;
			while(j>=0 && a[j]>key)
			{
				a[j+1]=a[j];
				j=j-1;
			}
			a[j+1]=key;
		}
		printf("Sorted array using insertion sort:\n");
		for(i=0;i<n;i++)
			printf("%d\t",a[i]);
			printf("\n");
	}
	else //parent process
	{
		wait(NULL); 
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		printf("Sorted array using bubble sort:\n");
		for(i=0;i<n;i++)
			printf("%d\t",a[i]);
			printf("\n");
	
	}	
	return 0;
}
