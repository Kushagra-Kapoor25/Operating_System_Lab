#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 5
int mutex = 1;
int full = 0, empty = BUFFER_SIZE, item = 0;
int flag = 1;
void producer()
{
    mutex--;
    full++;
    empty--;
    item++;
    printf("Producer produces item %d\n",item);
    mutex++;
}
  
void consumer()
{
    mutex--;
  	full--;
    empty++;
    printf("Consumer consumes item %d\n",item);
    item--;
    mutex++;
}
  
void main()
{
    int c;
    printf("1. Press 1 for Producer\n");
    printf("2. Press 2 for Consumer\n");
    printf("3. Press 3 for Exit\n");
    
    while(flag) 
	{
  		printf("Enter your choice:");
        scanf("%d", &c);
        
        switch (c) 
		{
        case 1:
            if ((mutex == 1) && (empty != 0)) 
			{
                producer();
            }
          	else 
			{
                printf("Buffer is full!\n");
            }
            break;
        case 2:
  			if ((mutex == 1) && (full != 0)) 
			{
                consumer();
            }
            else 
			{
                printf("Buffer is empty!\n");
            }
            break;

        case 3:
            flag = 0;
            break;
        default:
        	break;
        }
    }
}
