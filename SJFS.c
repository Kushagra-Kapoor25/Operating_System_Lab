#include<stdio.h>
void main()
{
    int n,temp,tt=0,min,d,i,j;
    float atat=0,awt=0,stat=0,swt=0;
    printf("Enter no of process: ");
    scanf("%d",&n);
    int a[10],b[10],ct[10],tat[10],wt[10];
    for(i=0;i<n;i++)
    {
    	printf("Enter arrival time P[%d]: ",i+1);       // input for arrival time
    	scanf("%d",&a[i]);
	}
    for(i=0;i<n;i++)
    {
    	printf("Enter burst time P[%d]: ",i+1);      // input for burst time 
    	scanf("%d",&b[i]);
    }
    
    // sorting based on burst time (Ascending order)
    for(i=0;i<n;i++)
    {
		for(j=i+1;j<n;j++)
  		{
			if(b[i]>b[j])
			{
      			temp=a[i];
      			a[i]=a[j];
      			a[j]=temp;
      			temp=b[i];
      			b[i]=b[j];
      			b[j]=temp;
            }
        }
    }
    
    // finding the min arrival time
    min=a[0];
    for(i=0;i<n;i++)
    {
        if(min>a[i])
        {
            min=a[i];
            d=i;
        }
    }
    
    tt=min;
    ct[d]=tt+b[d];
    tt=ct[d];
    for(i=0;i<n;i++)
    {
        if(a[i]!=min)
        {
    		ct[i]=b[i]+tt;
            tt=ct[i];
        }
    }
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-a[i];
        stat=stat+tat[i];
    	wt[i]=tat[i]-b[i];
        swt=swt+wt[i];
    }
    atat=stat/n;
    awt=swt/n;
    printf("Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n");
    for(i=0;i<n;i++)
    {
    	printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,a[i],b[i],wt[i],tat[i]);
    }
    printf("average waiting time=%f\naverage turn around time=%f",awt,atat);  //average waiting time and turn around time
}
