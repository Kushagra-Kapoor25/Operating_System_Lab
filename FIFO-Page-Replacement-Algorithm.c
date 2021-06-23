#include<stdio.h>
struct fnode
{
	int pno;
};
int nof;
struct fnode frames[] = {0};

// Checks if the given page is in the frame or not 
int checkFrame(int p_no)
{
	int i;
	for(i = 0;i<nof;i++)
	{
		if(frames[i].pno == p_no)
			return 1;		
	}
	return 0;
}

void main()
{
	int n,i,k;
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
		frames[i].pno = 0;
		
	printf("\nUsing FIFO Page Replacement Technique:\n");
	printf("Page Number\t\tPage Frame\t\tPage Fault\n");
	printf("----------------------------------------------------------\n");
	for(k=0;k<n;k++)
	{
		int flag = 0;
		if(checkFrame(ref_string[k]) == 0)
		{
			frames[page_fault%nof].pno = ref_string[k];
			flag = 1;
			page_fault++;
		}
		printf("%d\t\t\t",ref_string[k]);
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
