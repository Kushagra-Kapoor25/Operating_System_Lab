#include <stdio.h>

void main()
{
 
    int nop, nor, i, j;
    printf("Enter number of processes:");
    scanf("%d",&nop);
    printf("Enter number of resources:");
    scanf("%d",&nor);
    
	int alloc[nop][nor]; // Allocation Matrix
	int max[nop][nor];   // Maximum Matrix
	int avail[nor];      // Available Matrix
	
	for(i=0;i<nop;i++)
	{
		printf("Enter number of resources ALLOCATED to P%d\n",i);
		for( j=0;j<nor;j++)
		{
			printf("R%d: ",j);
			scanf("%d",&alloc[i][j]);
		}
	}
    printf("\n");
    for(i=0;i<nop;i++)
	{
		printf("MAXIMUM RESOURCES that can be allocated to P%d\n",i);
		for( j=0;j<nor;j++)
		{
			printf("R%d: ",j);
			scanf("%d",&max[i][j]);
		}
	}
	printf("\n");
    printf("AVAILABLE RESOURCES:\n");
    for(i=0;i<nor;i++)
    {
    	printf("R%d :",i);
    	scanf("%d",&avail[i]);
	}
	printf("\n");
	
    int fin[nop], safeSeq[nop], ind = 0;
    
    for (i = 0; i < nop; i++) 
        fin[i] = 0;
        
    int need[nop][nor];
    for (i = 0; i < nop; i++)
        for (j = 0; j < nor; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    
	int k,x = 0;
    for (k = 0; k < nop; k++) 
	{
        for (i = 0; i < nop; i++) 
		{
            if (fin[i] == 0) 
			{
                int flag = 0;
                for (j = 0; j < nor; j++) 
				{
                    if (need[i][j] > avail[j])
					{
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) 
				{
                    safeSeq[ind++] = i;
                    for (x = 0; x < nor; x++)
                        avail[x] += alloc[i][x];
                    fin[i] = 1;
                }
            }
        }
    }
    
    int flag = 0;
    for(i=0;i<nop;i++)
    {
    	if(fin[i]==0)
    	{
    		flag = 1;
    		break;
		}
	}
	
  if(flag == 0)
  	{
  		printf("No DEADLOCK occurs\n");
  		printf("==================\n");
   		printf("Following is the SAFE Sequence:\n");
   		for (i = 0; i < nop - 1; i++)
        printf(" P%d ->", safeSeq[i]);
  		printf(" P%d", safeSeq[nop - 1]);
  	}
  else
	{
  		printf("========================================================\n");
		printf("DEADLOCK will occur so no safe sequence can be generated.\n");  
	}
}
