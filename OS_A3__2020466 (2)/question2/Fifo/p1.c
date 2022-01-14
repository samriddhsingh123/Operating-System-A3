#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
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

int fd1;
int fd2;
if(mkfifo("abf", 0660)==-1){
    if(errno != EEXIST){
			perror("Cannot create the FIFO");
			exit(EXIT_FAILURE);
		}
		else
			printf("Using existing file\n");
	}
    

if(mkfifo("xya",0660)==-1){
   if(errno != EEXIST){
			perror("Cannot create the FIFO");
			exit(EXIT_FAILURE);
		}
		else
			printf("Using existing file\n");
	}

fd1=open("abf",O_WRONLY);
fd2=open("xya",O_RDONLY);
int count=0;
while(count<47){
    char str2[100];
  
    sprintf(str2, "%d %s %d %s %d %s %d %s %d %s",count,str[count],count+1,str[count+1],count+2,str[count+2],count+3,str[count+3],count+4,str[count+4]);
    printf("Sent: %s\n",str2);
    write(fd1,str2,100);
    
    read(fd2,str2,100);
    
    count=atoi(str2);
    count++;
    printf("Recieved ID: %s\n",str2);
}


}
