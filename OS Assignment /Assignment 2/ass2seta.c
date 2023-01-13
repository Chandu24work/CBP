#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

void seperate();
void count();
char cmd[80],token1[20],token2[20],token3[20],token4[20],ch;
int n,fp,wc,cc,lc;
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
			if(strcmp(token1,"count")==0)
				count();
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
	void count()
	{
		lc=0;wc=0;cc=0;
		fp=open(token3,O_RDONLY);
		if(fp==-1)
		{
			printf("\n File %s not opened",token3);
		}
		else
		{
			while(read(fp,&ch,1))
			{
				if(ch!=' '&& ch!='\t' && ch!='\n')
				{
					cc++;
				}
				else if(ch ==' ' || ch=='\t')
				{
					wc++;
				}
				else
				{
					wc++;
					lc++;
				}

			}
		}
		if(strcmp(token2,"w")==0)
			printf("\n Words count is %d",wc);
		if(strcmp(token2,"l")==0)
			printf("\n Line count is %d",lc);
		if(strcmp(token2,"c")==0)
			printf("\n character count is %d",cc);
		close(fp);
	
	}




