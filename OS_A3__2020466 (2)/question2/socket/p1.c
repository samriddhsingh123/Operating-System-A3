#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
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
struct sockaddr_un soc;
soc.sun_family =AF_UNIX;
char str3[16]="/tmp/acg.socket";
strncpy(soc.sun_path, str3,sizeof(str3)-1);
// printf("%s\n",soc.sun_path);

int fd1=socket(AF_UNIX,SOCK_STREAM,0 );
// printf("%d\n",fd1);
if(fd1==-1){
    perror("error");
    exit(EXIT_FAILURE);
}
int x=bind(fd1,(struct sockaddr * )&soc,sizeof(soc));
if(x==-1){
    perror("Bind Fail: ");
    exit(EXIT_FAILURE);
    // exit();
}
// printf("%d\n",x);
int c=listen(fd1,100);
// printf("%d\n",c);
if(c==-1){
    perror("listen fail: ");
    exit(EXIT_FAILURE);
}
int fd2=accept(fd1,NULL,NULL);
if(fd2==-1){
    perror("accept error");
    exit(EXIT_FAILURE);
    // exit();
}
// printf("%d\n",fd2);
int count=0;
while(count<47){
    char str2[100];
    
    sprintf(str2, "%d %s %d %s %d %s %d %s %d %s",count,str[count],count+1,str[count+1],count+2,str[count+2],count+3,str[count+3],count+4,str[count+4]);
    printf("Sent: %s\n",str2);
   
    int ac=write(fd2,str2,100);
    if(ac==-1){
        perror("errorr");
        exit(1);
    }
    int ax=read(fd2,str2,100);
     if(ax==-1){
        perror("errorr");
        exit(1);
    }
    count=atoi(str2);
    count++;
    printf("Recieved ID: %s\n",str2);
    
}
close(fd2);
unlink("/tmp/acg.socket");
}