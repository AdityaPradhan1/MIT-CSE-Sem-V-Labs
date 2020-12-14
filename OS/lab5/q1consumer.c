#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msg_struct{
	long int msg_type;
	int num;
};

int main(int argc, char const *argv[])
{
	setvbuf(stdout,NULL,_IONBF,0); //Change stdout to unbuffered. i.e print as soon as written
	
	struct msg_struct message;
	int msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid == -1) {
		printf("Error in creating message queue\n");
		exit(-1);
	}
	printf("Numbers received : \n");
	while(1) {
		if(msgrcv(msgid,(void*)&message,sizeof(int),0,0) == -1) { //msgtyp is 0 for a FIFO queue
			printf("Error in receiving messages\n");
			exit(-1);
		}
		if(message.num < 0) {
			printf("\nExit signal recieved = %d\n",message.num);
			if(msgctl(msgid,IPC_RMID,0) == -1) {
				printf("Error in deleting the message queue\n");
				exit(-1);
			}
			break;
		}
		printf("%d ",message.num);
		fflush(stdin);
	}
	printf("\n");
	return 0;
}
