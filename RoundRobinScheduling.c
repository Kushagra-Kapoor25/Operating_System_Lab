#include<stdio.h>
 
int main()
{
      int i, n, current_time = 0, completed, flag = 0, time_quantum;
      int waiting_time[10], turnaround_time[10] , arrival_time[10], burst_time[10], burst_remaining[10];
      int total_waiting_time=0, total_turnaround_time= 0;
      float average_waiting_time, average_turnaround_time;
      
      printf("Enter Total Number of Processes:");
      scanf("%d", &n);
      completed = n;
      
      for(i = 0; i < n; i++)
      {
            printf("Enter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:");
            scanf("%d", &burst_time[i]);
            burst_remaining[i] = burst_time[i];
            printf("\n");
      }
 
 
      printf("Enter Time Quantum:");
      scanf("%d", &time_quantum);
      
      for(current_time = 0, i = 0; completed != 0;)
      {
            if(burst_remaining[i] <= time_quantum && burst_remaining[i] > 0)
            {
                  current_time += burst_remaining[i];
                  burst_remaining[i] = 0;
                  flag = 1;
            }
            else if(burst_remaining[i] > 0)
            {
                  burst_remaining[i] = burst_remaining[i] - time_quantum;
                  current_time+= time_quantum;
            }
            if(burst_remaining[i] == 0 && flag == 1)
            {
                  completed--;
                  turnaround_time[i] = current_time - arrival_time[i];
                  waiting_time[i] =turnaround_time[i] - burst_time[i];
                  total_turnaround_time+=turnaround_time[i];
                  total_waiting_time+=waiting_time[i];
                  flag = 0;
            }
            if(i == n - 1)
            {
                  i = 0;
            }
            else if(arrival_time[i + 1] <= current_time)
            {
                  i++;
            }
      }
	  printf("PID\t\tBT\t\tAT\t\tTAT\t\tWT\n");
      printf("----------------------------------------------------------------------------\n");
      for(i=0;i<n;i++)
      {
      	printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,burst_time[i],arrival_time[i],turnaround_time[i],waiting_time[i]);
	  }
 
      average_waiting_time = (float)total_waiting_time/n;
      average_turnaround_time = (float)total_turnaround_time / n;
      printf("Average Waiting Time:%.2f\n", average_waiting_time);
      printf("Avg Turnaround Time:%.2f", average_turnaround_time);
      return 0;
}
