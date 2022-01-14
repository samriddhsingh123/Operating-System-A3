#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

int main (void) {
    
    
struct sockaddr_un soc;
soc.sun_family =AF_UNIX;
strncpy(soc.sun_path, "/tmp/acg.socket",15);

int fd1=socket(AF_UNIX,SOCK_STREAM,0 );

if(fd1==-1){
    perror("socket error");
    exit(EXIT_FAILURE);
}

int f=connect(fd1,(struct sockaddr * )&soc,sizeof(soc)-1);

if(f==-1){
    perror("connect error");
    exit(EXIT_FAILURE);
}

int count=0;
while(count<47){
    char str2[100];
    
    int ax=read(fd1,str2,100);
     if(ax==-1){
        perror("errorr");
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
    int ac=write(fd1,str2,100);
     if(ac==-1){
        perror("errorr");
        exit(1);
    }
    printf("HIGHEST ID: %s\n", str2);
   
}
close(fd1);
unlink("/tmp/acg.socket");
}