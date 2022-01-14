
#include <time.h>  
#define _GNU_SOURCE
#include<stdio.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#define sys_set_total_wt 449
int main(){
   int pid= fork();
   if(pid==0){
    int long am = syscall(sys_set_total_wt, 5000);
    if(am==0){
	printf("Syscall Returned 0\nSuccess!\n");
    }
    else {
    perror("error:");

    }
   double num;
   int remainder;
   double reverse_num;
   int temp;
   double time_spent = 0.0;
 
    clock_t begin = clock();

   long start=1;
   long long end=700000000;
   for(num=start;num<=end;num++){
      temp=num;
      reverse_num=0;
      while(temp){
         remainder=temp%10;
         temp=temp/10;
         reverse_num=reverse_num*10+remainder;
      }
   }
   clock_t ending = clock();
    time_spent += (double)(ending - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);

   return 0;
   }
   else{
       int pid2=fork();
       if(pid2==0){
            double num;
   int remainder;
   double reverse_num;
   int temp;
   double time_spent = 0.0;
 
    clock_t begin = clock();

   long start=1;
   long long end=700000000;
   for(num=start;num<=end;num++){
      temp=num;
      reverse_num=0;
      while(temp){
         remainder=temp%10;
         temp=temp/10;
         reverse_num=reverse_num*10+remainder;
      }
   }
    clock_t ending = clock();
    time_spent += (double)(ending - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);

   return 0;
       }
   }
   
}

