#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>

void seperate();
void list();
int n,cc,lc,fp,wc;
char fname[20],cmd[80],token1[20],token2[20],token3[20],token4[20];
DIR *dp;
struct dirent *de;
pid_t pid;
void seperate()
{
strcpy(token1,"\0");
	strcpy(token2,"\0");
	strcpy(token3,"\0");
	strcpy(token4,"\0");
	n=sscanf(cmd,"%s%s%s%s",token1,token2,token3,token4);
}
int main()
{
	while(1)
	{
		printf("\n MyShell $");
		fgets(cmd,80,stdin);
		seperate();
		if(strcmp(token1,"exit")==0)
			exit(0);
		pid=fork();
		if(pid==-1)
			printf("\n Child process not created");
		else if(pid==0)
		{
			if(strcmp(token1,"list")==0)
				list();
			else
			{
				switch(n)
				{
					case 1:
						execlp(token1,token1,NULL);
						break;
					case 2:
						execlp(token1,token1,token2,NULL);
						break;
					case 3:
						execlp(token1,token1,token2,token3,NULL);
						break;
					case 4:
						execlp(token1,token1,token2,token3,token4,NULL);
						break;
				}
			
			}
		}
			else
		
				wait(NULL);
		
		}
		return 0;
	}
	
void list()
{
	int cnt=0;
	dp=opendir(token3);
	if(dp==NULL)
	{
		printf("\n%s Directory not found",token3);
	}
	else
	{
		if(strcmp(token2,"f")==0)
		{
	while(1)
	{
		de=readdir(dp);
		if(de==NULL)
		  break;
			printf("\n File name %s",de->d_name);
	} 	
		}
	if(strcmp(token2,"n")==0)
	{
	while(1)
	{
	de=readdir(dp);
	if(de==NULL)
		break;
	cnt++;
	}
	printf("\n Total files %d",cnt);
	}
	if(strcmp(token2,"i")==0)
	{
	while(1)
	{
	de=readdir(dp);
	if(de==NULL)
		break;
	printf("\n File name %s",de->d_name);
	printf("\n Inode no%d",de->d_ino);
}
}
}
}

