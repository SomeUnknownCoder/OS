#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{ 

   int arr[100];
   for(int i=0;i<100;i++)
   {
      arr[i]=i+1;
   }
   int sum=0;
   pid_t child[3];
   int sumarr[4];
   for(int a=0;a<25;a++)
   {
       sum+=arr[a];
       sumarr[0]=sum;
   }
   printf("The sum of the array is %d\n: ",sumarr[0]);
   for(int i=0; i<3; i++)
   { 
      child[i]=fork();
      if(child[i]<0)
      {
        printf("Fork failed\n");
        exit(1);
      }
      if(child[i]==0)
      {
         if(i==0)
         { 
           sum=0;
           for(int j=25;j<50;j++)
           {
              sum+=arr[j];
              sumarr[1]=sum;
           }
           printf("The sum of the array is %d\n:",sumarr[1]);
           exit(0);
         }
         else if(i==1)
         {
           sum=0;
           for(int k=50;k<75;k++)
           {
              sum+=arr[k]; 
              sumarr[2]=sum;
              
           }
           printf("The sum of the array is %d\n:",sumarr[2]);
           exit(0);
         }
        else if(i==2)
        {
          sum=0;
          for(int x=75;x<100;x++)
          {
              sum+=arr[x];
              sumarr[3]=sum;
             
              
          }
          printf("The sum of the array is :%d\n",sumarr[3]);
          exit(0);
        }
      }
     else 
      {  
         
          wait(&child[i]);
      }
   }
   
   
}
