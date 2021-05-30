#include<stdio.h>
#include<string.h>

int kw = 0;
int op = 0;
int sp = 0;
int id = 0;

char* keyword[] = {"if","else","while","do","break","continue","int","double","float","char","return","case","long","static","void","short","unsigned"};
char oper[] = {'!','%','&','*','+','/','-','=','<','>'};
char seper[] = {'(',')','{','}','[',']',',',';','.',':'};

const static int ls = sizeof(seper)/sizeof(seper[0]);
const static int lo = sizeof(oper)/sizeof(oper[0]);
const static int lkw = sizeof(keyword)/sizeof(keyword[0]);

int spi[sizeof(seper)/sizeof(seper[0])] = {0};
int opi[sizeof(oper)/sizeof(oper[0])] = {0};
int kwi[sizeof(keyword)/sizeof(keyword[0])] = {0};

void isSeperator(char* w)
{
	int i;
	for(i=0;i<strlen(w);i++)
	{
		int j;
		for(j=0;j<ls;j++)
		{
			if(w[i] == seper[j])
			{
				spi[j]++;
				sp++;
			}
		}						
	}
}

void isOperator(char* w)
{
	int i;
	for(i=0;i<strlen(w);i++)
	{
		int j;
		for(j=0;j<lo;j++)
		{
			if(w[i] == oper[j])
			{
				opi[j]++;
				op++;
			}
		}		
				
	}
}

void isKeyword(char* w)
{
	int i;
	for(i=0;i<lkw;i++)
	{
		if(!strcmp(w,keyword[i]))
		{
			kwi[i]++;
			kw++;
		}		
	}
}

void isIdentifier(char *w)
{
	int i;
	int flag = 0;
	for(i=0;i<lkw;i++)
	{
		if(!strcmp(w,keyword[i]))
		{
			flag = 1;
			break;
		}		
	}
	if(flag == 0)
	{
		id++;
	}
}

void checkToken(char* word)
{
	isSeperator(word);
	isOperator(word);
	isKeyword(word);
	isIdentifier(word);
}

void printDetails()
{
		int i;
		printf("For keywords:\n");
		for(i=0;i<lkw;i++)
		{
			if(kwi[i]>0)
				printf("%s : %d\n",keyword[i],kwi[i]);
		}
		printf("Number of keywords: %d\n\n",kw);
		
		printf("For operators:\n");
		for(i=0;i<lo;i++)
		{
			if(opi[i]>0)
				printf("%c : %d\n",oper[i],opi[i]);
		}
		printf("Number of operators: %d\n\n",op);
		
		printf("For seperators:\n");
		for(i=0;i<ls;i++)
		{
			if(spi[i]>0)
				printf("%c : %d\n",seper[i],spi[i]);		
		}
		printf("Number of seperators: %d\n\n",sp);
		
		printf("Number of identifiers: %d\n\n",id);
		
}

void main()
{
	FILE *fp = fopen("myfile.c","r");
	if(fp == NULL)
		printf("Cannot find the file.\n");
	else
	{
		printf("File opened and is now being read...\n");
		char line[80];
		while(fgets(line, 80, fp)!=NULL)
		{
			printf("%s",line);
			char* token = strtok(line," ");
			while(token!=NULL)
			{
				checkToken(token);
				token = strtok(NULL, " ");
			}
		}
		printf("\n");
		printDetails();
	}
	fclose(fp);	
}
