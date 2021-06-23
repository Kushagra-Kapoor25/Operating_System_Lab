#include<stdio.h>
struct fnode
{
	int pno;
	int counter;
};
int nof;
struct fnode frames[] = {0};

// Checks if the given page is in the frame or not
int checkFrame(int p_no)
{
	int i;
	for(i=0;i<nof;i++)
	{
		if(frames[i].pno == p_no)
			return i;
	}
	return -1;
}

// Gets least recently used frame index
int get_lru()
{
	int i,min = 0;
	for(i=0;i<nof;i++)
	{
		if(frames[i].counter<frames[min].counter)
			min = i;
	}
	return min;
}
void main()
{
	int n,i;
	int page_fault = 0;
	printf("Enter the length of the ref string: ");
	scanf("%d",&n);
	int ref_string[n];
	printf("Enter the reference string: \n");
	for(i=0;i<n;i++)
		scanf("%d",&ref_string[i]);
	
	printf("Enter the number of frames: ");
	scanf("%d",&nof);
	
	frames[nof];
	for(i=0;i<nof;i++)
	{
		frames[i].pno = 0;
		frames[i].counter = -1;
	}
	
	
	printf("\nUsing LRU Page Replacement Technique:\n");
	printf("Page Number\t\tPage Frame\t\tPage Fault\n");
	printf("----------------------------------------------------------\n");
	int flag,curr_time = 1;
	for(i=0;i<n;i++)
	{
		flag = 0;
		int p = ref_string[i];
		int k = checkFrame(p);
		if(k == -1)
		{
			page_fault++;
			k = get_lru();
			frames[k].pno = p;
			flag = 1; 
		}
		frames[k].counter = curr_time;
		curr_time++;
		
		printf("%d\t\t\t",p);
		int j;
		for(j=0;j<nof;j++)
			printf("%d   ",frames[j].pno);
		printf("\t\t");
		if(flag == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	printf("----------------------------------------------------------\n");
	printf("Total number of page faults: %d\n",page_fault);
	printf("Hit Ratio: %d/%d",(n-page_fault),n);	
}
