#include<stdio.h>
#include<math.h>
void main()
{
	int size,i,head;
	printf("Enter initial head position: ");
	scanf("%d",&head);
	printf("Enter the size of request sequence: ");
	scanf("%d",&size);
	int arr[size];
	printf("Enter request sequence:\n");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	int total_seek_count = 0;
	
	int current_track = head;
	for(i=0;i<size;i++)
	{
		total_seek_count = total_seek_count + abs(current_track-arr[i]);	
		current_track = arr[i];
	}
	printf("Total number of seek operations: %d\n",total_seek_count);
	printf("Seek sequence is: ");
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
}
