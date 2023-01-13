#include<stdio.h>
#include<stdlib.h>
struct process
{
	int first_bt,next_bt,at,ft,tat,wt,temp_bt,prio;
	
	//float at;
}P[10];
struct Schedule
{
     int pid,endtime;
}sch[100];
int sch_cnt,ct,np,i;
void take_input()
{
	printf("Enter the no of process:");
	scanf("%d",&np);
	for(i=0;i<np;i++)
	{
		printf("Enter the arrival time of process %d:");
		scanf("%d",&P[i].at);
		printf("Enter first  burst time of process %d:");
		scanf("%d",&P[i].first_bt);
		P[i].temp_bt=P[i].first_bt;
		printf("Enter the process of priority");
		scanf("%d",&P[i].prio);
	}
}
int getProcessByPriority()
{
	int minp=-1;
	int minat=32768;
	for(i=0;i<np;i++)
	{
		if(P[i].at<=ct && P[i].temp_bt>0 && P[i].prio<minat)
		{
			minp=i;
			minat=P[i].prio;
		}
	}
	return minp;
}
void showGanttChart()
{
	for(i=0;i<sch_cnt*5;i++)
	printf("-");
	printf("\n|");
	for(i=0;i<sch_cnt;i++)                                           	                                                                                                        	printf("P%d | ",sch[i].pid); 
	printf("\n");
	for(i=0;i<sch_cnt*5;i++)
	printf("-");
	printf("\n0");
	for(i=0;i<sch_cnt;i++)
	printf("%5d",sch[i].endtime);
}
void print_output()
{
	float avgtat=0,avgwt=0;
	printf("\n");
	printf("\nPID\tFBT\tNBT\tAT\tFT\tTAT\tWT\tprio\n");
	for(i=0;i<np;i++)
	{
		printf("\n P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,P[i].first_bt,P[i].next_bt,P[i].at,P[i].ft,P[i].tat,P[i].wt,P[i].prio);
		avgtat+=P[i].tat;
		avgwt+=P[i].wt;
	}
	avgtat=avgtat/np;
	avgwt=avgwt/np;
	printf("average tat:%f",avgtat);
	printf(" average wt:%f",avgwt);
}
void main()
{
	take_input();
	while(1)
	{
		int x=getProcessByPriority();
		if(x==-1)
			break;
		sch[sch_cnt].pid=x;
		ct+=P[x].temp_bt;
		P[x].temp_bt=0;
		P[x].ft=ct;
		sch[sch_cnt].endtime=ct;
		sch_cnt++;
		P[x].tat=P[x].ft-P[x].at;
		P[x].wt=P[x].tat-P[x].first_bt;
	}
	showGanttChart();
	print_output();
}

