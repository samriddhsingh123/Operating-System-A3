#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <mqueue.h>


int main (void) {
    
    char str[50][11] = {{0}};                
    srand (time(NULL));                             
    int afq=0;
    for (int i = 0; i < 5; i++) {              
        for (int j = 0; j < 50; j++){
            afq= rand() % 26 ;
            str[j][i] = afq + 65;   }}  

    for (int i = 0; i < 50; i++)                    
        printf ("%s\n", str[i]);
    mqd_t fd1;
    mqd_t fd2;
    struct mq_attr x;
    x.mq_flags=0;
    x.mq_maxmsg=5;
    x.mq_curmsgs=0;
    x.mq_msgsize=100;
    char efg[5]="/jfn";
    fd1=mq_open(efg,O_CREAT|O_RDWR, 0666,&x);
    
    if(fd1==-1){
        perror("error");
       exit(1);
    }
    char file[6]="/jixf";
    fd2=mq_open(file,O_RDWR | O_CREAT, 0666,&x);
    
    if(fd2==-1){
        perror("error");
       exit(1);
    }
    
    int count=0;
while(count<47){
    char str2[100];
    
    sprintf(str2, "%d %s %d %s %d %s %d %s %d %s",count,str[count],count+1,str[count+1],count+2,str[count+2],count+3,str[count+3],count+4,str[count+4]);
    printf("Sent: %s\n",str2);
    if(mq_send(fd1,str2,100,0)==-1){
        perror("errorr");
        exit(1);
    };
    
    
    //block io as waiting for write
    int ac=mq_receive(fd2,str2,100,NULL);
    if(ac==-1){
        perror("errorr");
        exit(1);
    }
    count=atoi(str2);
    count++;
    printf("Recieved ID: %s\n",str2);
   
}
}