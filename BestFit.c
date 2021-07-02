#include<stdio.h>
void main()
{
	int fragment[20],b[20],p[20],i,j,nb,np,temp,lowest=9999;
	int barray[20],parray[20];
	
	printf("\n\t\t\tMemory Management Scheme - Best Fit");
	
	printf("\nEnter the number of blocks:");
	scanf("%d",&nb);
	
	printf("Enter the number of processes:");
	scanf("%d",&np);
	
	printf("\nEnter the size of the blocks:-\n");
	for(i=0;i<nb;i++)
    {
		printf("Block no.%d:",i+1);
        scanf("%d",&b[i]);
    }
	
	printf("\nEnter the size of the processes :-\n");
	for(i=0;i<np;i++)
    {
        printf("Process no.%d:",i+1);
        scanf("%d",&p[i]);
    }
	
	for(i=0;i<np;i++)
	{
		for(j=0;j<nb;j++)
		{
			if(barray[j]!=1)
			{
				temp=b[j]-p[i];
				if(temp>=0)
				{
					if(lowest>temp)
					{
						parray[i]=j;
						lowest=temp;
					}	
				}
			}
		}
		fragment[i]=lowest;
		barray[parray[i]]=1;	
		lowest=9999;
	}
	
	printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment\n");
	printf("---------------------------------------------------------------------------");
	for(i=0;i<np && parray[i]!=0;i++)
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,p[i],parray[i],b[parray[i]],fragment[i]);

}
