Arani sir has given me 1 day relief in deadline submission. My deadline is 15 th 11:59pm without any fine.
 
FIFO:
     Compiling and running:
	Go to the fifo directory
	run "make" command to compile
	then ./p1 to run p1 and ./p2 to run p2
     Expalnantion and logic:
	FIFO is a data structure. Fifo is a named pipes which enables communications between two processes(p1 and p2).
	In this we open a file in which we read and write from different processes.
	In P1 we create an array(of size 50) of strings of a fixed length which are randomly generated. we use srand and rand function to generate.
	we make file discripter in which we read and write. We created FIFO using the commant mkfifo()
	We initialize count variable to run the loop till the last index of that array. 
	We initialize the str2[100] in which we put the 5 indexes and 5 strings from str using sprintf which is to be send to the p2. 
	Then we write this str2 in fd1. It will wait for instruction which is to be given by P2.
	In p2 we read from fifo file ehich p1 wrote and sendback the largest id from the 
	fifo file through whuch p1 will read the largest id sent by p2. And this will goes on till we recieved the largest id i.e 49.

Message queue:
     Compiling and running:
	Go to the messagequeue directory
	run "make" command to compile
	then ./p1 to run p1 and ./p2 to run p2

     Expalnantion and logic:
	We used posix message queue. POSIX message queues allow processes to exchange data in the form
        of messages.
	In P1 we created structure named mq_attr in which we set maximum messsges
	which is 5 and maximum size which is 100 bytes here.
	We created message queue using mq_open().
	We store its return value in the fd1 which is a message queue discrptor(mqd_t).
	It will be created using O_CREATE. We write in fd1 in P1 and read fd1 in P2 and vice versa.
	We send 5 strings along with there indexes in P2 by mq_send.
	In P2 it will wait at mq_recieve then it will be print our recieved value and
	then find the max index then sendback the largest id to P1 using mq_send. 
	And this will goes on till we recieved the largest id i.e 49.
	

	
      
Socket:
     Compiling and running:
	Go to the socket directory
	run "make" command to compile
	then ./p1 to run p1 and ./p2 to run p2
     
     Expalnantion and logic:
	A socket is a type of data structure used to communicate amongst processes.
	It has a server and a client. We used posix socket. It has a server and a client.
	When the server listens, the client can connect to it, if the server accepts its request to connect.
	After the connection, data can be received and sent amongst server and client.

	In P1 we create an array(of size 50) of strings of a fixed length which are randomly generated.
	we use srand and rand function to generate. We create a socket in P1 and then connect to the server in P2.
	The server accepts its request to connect.
	We initialize the str2[100] in which we put the 5 indexes and 5 strings from str using sprintf which is to be send to the p2.
	In P2 we receive the strings and their ids using 'read'. Then we send back the largest id back to P1.
	In P1 we set the counter of while loop and the next 5 ids are sent. This goes on till the last id 49 is received.
	