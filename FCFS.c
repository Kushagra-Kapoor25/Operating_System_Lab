#include<stdio.h>
void calcWaitingTime(int burst_time[],int waiting_time[],int arrival_time[], int n)
{
	int i;
	waiting_time[0] = 0;
	for(i=1;i<n;i++)
	{
		waiting_time[i] = waiting_time[i-1] + burst_time[i-1] - arrival_time[i]; 
	}
}

void calcTurnAroundTime(int burst_time[],int waiting_time[], int turn_around_time[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		turn_around_time[i] = burst_time[i]  + waiting_time[i];
	}
}

void fcfsDetails(int processes[], int burst_time[],int arrival_time[], int n)
{
	int i;
	int waiting_time[n], turn_around_time[n];
	int total_waiting_time = 0;
	int total_turn_around_time = 0;
	calcWaitingTime(burst_time,waiting_time,arrival_time, n);
	calcTurnAroundTime(burst_time,waiting_time,turn_around_time, n);
	printf("Process ID\tBurstTime(ms)\tArrivalTime(ms)\tWaitingTime(ms)\tTurnAroundTime(ms)\n");
	printf("----------------------------------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		total_waiting_time+=waiting_time[i];
		total_turn_around_time+=turn_around_time[i];
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",processes[i],burst_time[i],arrival_time[i],waiting_time[i],turn_around_time[i]);
	}
	printf("\n\n");
	printf("Average waiting time: %dms\n",(total_waiting_time/n));
	printf("Average turn around time: %dms\n",(total_turn_around_time)/n);
}
void sort(int p[], int bt[], int at[],int nop)
{
	int i,j, temp;
	for(i=0;i<nop-1;i++)
	{
		for(j=i+1;j<nop;j++)
		{
			if(at[j]<at[i])
			{
				temp = at[j];
				at[j] = at[i];
				at[i] = temp;
				
				temp = bt[j];
				bt[j] = bt[i];
				bt[i] = temp;
				
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}
}
void main()
{
	int processes[] = {1,2,3,4,5};
	const int n = (sizeof(processes)/sizeof(int));
	int burst_time[] = {5,8,10,2,3};
	int arrival_time[] = {2,1,4,0,2};
	
	sort(processes,burst_time,arrival_time,n);
	fcfsDetails(processes,burst_time,arrival_time,n);
}

/*
AT - Arrival Time of the process
BT - Burst time of the process
CT - Completion time of the process
TAT - Turnaround time of the process
WT - Waiting time of the process


Formulas used:
--------------
TAT = BT + WT
WT = TAT - BT
*/

