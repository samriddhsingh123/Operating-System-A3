#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <mqueue.h>
#include <string.h>
#include <errno.h>
int main (void) {
    

    mqd_t fd1;
    mqd_t fd2;
    char efg[5]="/jfn";
   
    fd1=mq_open(efg,O_RDONLY | O_CREAT, 0660,NULL);
    
    char file[6]="/jixf";

    fd2=mq_open(file,O_WRONLY | O_CREAT, 0660,NULL);
    int count=0;
while(count<47){
    char str2[100];
   
    
   if(mq_receive(fd1,str2,100,NULL)==-1){
       perror("error");
       exit(1);
   }
       
    printf("%s\n",str2);
    char *temp="";
    temp=strtok(str2," ");
    for(int i=0;i<8;i++){
        temp=strtok(NULL," ");
    }

    count=atoi(temp);
    sprintf(str2,"%d",count);
    //write max int
    printf("HIGHEST ID: %s\n", str2);
    if(mq_send(fd2,str2,100,0)==-1){
        perror("error:");
        exit(1);
    }
   
}
}