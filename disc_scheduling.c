#include<stdio.h>
#include <stdlib.h>
int n;
int flag[1000];
void FCFS(int req[], int head)
{
	int tot_st = 0, d, cur_t,i;
	for (i = 0; i < n; i++) 
    {
		
		cur_t = req[i];
		d = abs(cur_t - head);
		tot_st += d;
		head = cur_t;
	}

	printf("\nFCFS :\n\nSeek Time : %d\n",tot_st);
	
	printf("\nSeek Sequence:\t");
	for ( i = 0; i < n; i++) 
    {
		printf("%d\t",req[i]);
	}
    printf("\n");
}

int diff(int a[],int curr)
{
	int i,min,min_pos,min_d =9999;
	for(i=0;i<n;i++)
    {
		min= abs(a[i]-curr);
		if(min<min_d && flag[i]==0){
			min_d=min;
			min_pos=i;
		}
	}
	return min_pos;
	
}

void SSTF(int req[],int head)
{
     
	 int tot_st = 0,d,cur_t,min_i,seq[n],i;
	 
    for (i = 0; i < n; i++) 
    {
		min_i =diff(req,head);
		flag[min_i]=1;
		cur_t= req[min_i];
		d = abs(cur_t - head);
		tot_st += d;
		head = cur_t;
		seq[i]=min_i;
	 }
	printf("\nSSTF:\n\nSeek Time : %d\n",tot_st);	
	printf("\nSeek Sequence:\t");
	for (i = 0; i < n; i++) 
    {
		printf("%d\t",req[seq[i]]);
	}
	printf("\n");
}

int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

void SCAN(int req[],int head)
{
	int tot_st = 0,c=0,dist,end_d, cur_t,seq[n],dir,s_i,i,f[n];
	printf("\nSCAN :\n\n0: Towards Left\t\t1: Towards Right\n");
	printf("\nEnter Direction and End of Disk\n");
	scanf("%d%d",&dir,&end_d);
	qsort(req,n, sizeof(int), cmpfunc);

	for(i=0;i<n;i++)
    {
		if(req[i]>head)
        {
			if(dir==1)
            {
				s_i=i;
			    break;
			}
			else
            {
				s_i=i-1;
				break;
			}
		}
	}
	if(dir==1)
    {
		for(i=s_i;i<=n;i++)
        {
			if(i==n)
            {
                dist = abs(req[i-1] - end_d);
                tot_st += dist;
                head=end_d;
                continue;	
			}
            f[i]=1;
            dist = abs(req[i] - head);
            tot_st += dist;
            head = req[i];
            seq[c++]=i;
		}

		for(i=n-1;i>=0;i--)
        {
		if(f[i]!=1)
        {
            f[i]=1;
            dist = abs(req[i] - head);
            tot_st += dist;
            head = req[i];
            seq[c++]=i;	
		} 
	 }
	}
	if(dir==0)
    {
		for(i=s_i;i>=0;i--)
        {
            f[i]=1;
            dist = abs(req[i] - head);
            tot_st += dist;
            head = req[i];
            seq[c++]=i;
		}
		dist = abs(req[0] -0);
		tot_st += dist;
		head = 0;
		
		for(i=0;i<n;i++)
        {
		if(f[i]!=1)
        {
            f[i]=1;
            dist = abs(req[i] - head);
            tot_st+= dist;
            head = req[i];
            seq[c++]=i;	
		}  
	 }
	}
	printf("\nSeek Time : %d\n",tot_st);
	
	printf("\nSeek Sequence:\t");

	for (i = 0; i < n; i++) 
    {
		printf("%d\t",req[seq[i]]);
	}
	printf("\n");
}

void CLOOK(int req[],int head)
{
	int tot_st = 0,c=0, d,seq[n],s_i,i,f[n];
	qsort(req,n,sizeof(int),cmpfunc);
	for(i=0;i<n;i++)
    {
		if(req[i]>=head)
        {
			s_i=i;
			break;
		}
	}	
	for(i=s_i;i<n;i++)
    {
	    d = abs(req[i] - head);
		tot_st += d;
        head = req[i];
		seq[c++]=i;
	}
	for(i=0;i<s_i;i++)
    {
		d = abs(req[i] - head);
		tot_st += d;
		head =req[i];
		seq[c++]=i;	
	}
	printf("\nCLOOK:\n\nSeek Time : %d\n",tot_st);
	printf("\nSeek Sequence:\t");
	for (i = 0; i < n; i++) 
    {
		printf("%d\t",req[seq[i]]);
	}
	printf("\n");
}

int main()
{
	int h,i;
    printf("\nEnter the Number of Requests:\n");
    scanf("%d",&n);
    int req[n];
    printf("\nEnter the Request Sequence:\n");
    for( i=0;i<n;i++)
    scanf("%d",&req[i]);
    printf("\nEnter the Initial Head Position:\n");
    scanf("%d",&h);
	FCFS(req, h);
    SSTF(req,h);
    SCAN(req,h);
    CLOOK(req,h);
	return 0;
}

