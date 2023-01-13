#include <stdio.h>
#define MAX 20
int frames[MAX],ref[MAX],mem[MAX][MAX],faults,sp,m,n;
void accept()
{
	int i;
	printf("Enter number of frames=");
	scanf("%d",&n);
	printf("Enter number of references=");
	scanf("%d",&m);
	printf("Enter references string=\n");
	for(i=0;i<m;i++)
	{
		printf("[%d]=",i);
		scanf("%d",&ref[i]);
	}
}
void disp()
{
	int i,j;
	for(i=0;i<m;i++)
		printf("%d\t",ref[i]);
	printf("\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mem[i][j])
				printf("%d\t",mem[i][j]);
			else
				printf("\t");
		}
		printf("\n\n");
	}
	printf("Total page faults=%d\n",faults);
}
int search(int pno)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(frames[i]==pno)
			return i;
	}
	return -1;
}
void fifo()
{
	int i,j;
	for(i=0;i<m;i++)
	{
		if(search(ref[i])==-1)
		{
			frames[sp]=ref[i];
			sp=(sp+1)%n;
			faults++;
			for(j=0;j<n;j++)
				mem[j][i]=frames[j];
		}
	}
}
int main()
{
	accept();
	fifo();
	disp();
	return 0;
}

