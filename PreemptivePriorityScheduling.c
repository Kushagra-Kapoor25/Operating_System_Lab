#include <stdio.h>
#include<string.h>

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void main() 
{
    int n;
    struct process p[20];
    float avg_turnaround_time;
    float avg_waiting_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int burst_remaining[20];
    int is_completed[20];
    int current_time = 0;
    int completed = 0;
    int prev = 0;
    int i,j;
    memset(is_completed,0,sizeof(is_completed));
    
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i = 0; i < n; i++)
	{
    	printf("Enter arrival time of process %d :",i+1);
        scanf("%d",&p[i].arrival_time);
        printf("Enter burst time of process %d :",i+1);
        scanf("%d",&p[i].burst_time);
        printf("Enter priority of the process %d :",i+1);
        scanf("%d",&p[i].priority);
        p[i].pid = i+1;
        burst_remaining[i] = p[i].burst_time;
        printf("\n");
    }

    while(completed != n)
	{
        int idx = -1;
        int mx = -1;
        for(i = 0; i < n; i++) 
		{
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) 
			{
                if(p[i].priority > mx) 
				{
                    mx = p[i].priority;
                    idx = i;
                }
                if(p[i].priority == mx) 
				{
                    if(p[i].arrival_time < p[idx].arrival_time) 
					{
                        mx = p[i].priority;
                        idx = i;
                    }
                }
            }
    	}
        
        if(idx != -1) 
		{
            burst_remaining[idx] -= 1;
            current_time++;
            prev = current_time;
            if(burst_remaining[idx] == 0) 
			{
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

                total_turnaround_time += p[idx].turnaround_time;
                total_waiting_time += p[idx].waiting_time;    

                is_completed[idx] = 1;
                completed++;
            }
        }
        else 
		{
             current_time++;
        }  
    }
    
	avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;

    printf("#P\tAT\tBT\tPRI\tCT\tTAT\tWT\t\n");
    printf("----------------------------------------------------\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",p[i].pid,p[i].arrival_time,p[i].burst_time,p[i].priority,p[i].completion_time,p[i].turnaround_time,p[i].waiting_time);
    }
    printf("\n");
    printf("Average Turnaround Time = %.2f\n",avg_turnaround_time);
    printf("Average Waiting Time = %.2f\n",avg_waiting_time);
}

/*
AT - Arrival Time of the process
BT - Burst time of the process
CT - Completion time of the process
TAT - Turnaround time of the process
WT - Waiting time of the process


Formulas used:
--------------
TAT = CT - AT
WT = TAT - BT

*/


