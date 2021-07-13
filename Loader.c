#include <stdio.h>
#include <string.h>

void main()
{
    FILE *fp;
    fp = fopen("testCase.c","r");
    char word[20],c;
    int p = 0,mode = 0,i;
    int intcount = 0,charcount = 0,floatcount = 0,doublecount = 0;
    printf("Enter base address\n");
    int base;
    scanf("%d",&base);
    int addr = base;
    int arr = 0;
    while(1)
	{
    	word[p] = '\0';
        c = fgetc(fp);	
		if(c == '[')
		{
			arr = 1;
			int size = 0;
			char c = fgetc(fp);
			while(c != ']')
			{
				size = size * 10 + (int)(c-'0');
				c = fgetc(fp);
			}
			printf("%s starts at %d\n",word,addr);
			if(mode == 1) addr += size*2;
            else if(mode == 2) addr += size;
            else if(mode == 3) addr += size*4;
            else if(mode == 4) addr += size*8;
		}
		if((c == ',' || c == ';') && !arr)
		{
        	printf("%s starts at %d\n",word,addr);
            if(mode == 1) 
				addr += 2;
            else if(mode == 2) 
				addr += 1;
            else if(mode == 3) 
				addr += 4;
            else if(mode == 4) 
				addr += 8;
            arr = 0;
		}	
		if(c == ';') 
			mode = 0;
        if(c == ';' || c == ' ' || c == '\t' || c == '\n' || c == ',' || c == EOF)
		{
            if(mode == 0)
			{
                if(strcmp(word,"int") == 0) 
					mode = 1;
                else if(strcmp(word,"char") == 0) 
					mode = 2;
                else if(strcmp(word,"float") == 0) 
					mode = 3;
                else if(strcmp(word,"double") == 0) 
					mode = 4;
            }
            p = 0;
            if(c == EOF)
				break;
        }
        else 
			word[p++] = c;        
    }
    printf("Ending address %d\n",addr);
    printf("Size of program %d",addr-base);
}
