#include<stdio.h>
#include<unistd.h>
int main()
{
   int pipefds[2],ret,id;
   char writemsg[2][45]={"System Software and Operating Systems Lab", "Subject Code - 18CS470"};
   char readmsg[45];
   ret = pipe(pipefds);
   if (ret == -1) 
   {
      printf("Unable to create pipe\n");
      return 1;
   }
   id = fork();
   if (id == 0)
   {
      read(pipefds[0], readmsg, sizeof(readmsg));
      printf("Child Process - Reading from pipe – Message 1 is:\t%s\n", readmsg);
      read(pipefds[0], readmsg, sizeof(readmsg));
      printf("Child Process - Reading from pipe – Message 2 is:\t%s\n", readmsg);
      
   }
   else 
   { 
      printf("Parent Process - Writing to pipe - Message 1 is:\t%s\n", writemsg[0]);
      write(pipefds[1], writemsg[0], sizeof(writemsg[0]));
      printf("Parent Process - Writing to pipe - Message 2 is:\t%s\n", writemsg[1]);
      write(pipefds[1], writemsg[1], sizeof(writemsg[1]));
   }
   return 0;
}
