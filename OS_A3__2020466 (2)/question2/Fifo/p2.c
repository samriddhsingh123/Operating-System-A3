#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main (void) {
    

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


fd1=open("abf",O_RDONLY);
fd2=open("xya",O_WRONLY);
int count=0;

while(count<47){
    char str2[100];
    read(fd1,str2,100);
    printf("%s\n",str2);
    char *temp="";
    temp=strtok(str2," ");
    for(int i=0;i<8;i++){
        temp=strtok(NULL," ");
    }
    count=atoi(temp);
    sprintf(str2,"%d",count);
    write(fd2,str2,100);
    printf("HIGHEST ID: %s\n", str2);
    
}

}
