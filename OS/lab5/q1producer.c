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
	struct msg_struct arr[4];
	int msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid == -1) {
		printf("Error in creating message queue\n");
		exit(-1);
	}
	int num;
	while(1) {
		printf("Enter four numbers to send to consumer(-1 to stop) : \n");
		for(int i = 0;i < 4;i++) {
			scanf("%d",&num);
			arr[i].msg_type = 1;
			arr[i].num = num;
			if(msgsnd(msgid,(void*)&arr[i],sizeof(int),0) == -1) {
				printf("Error is sending message\n");
				exit(-1);
			}
			if(num < 0) {
				printf("Exiting...\n");
				exit(0);
			}
		}
	}
	return 0;
}
