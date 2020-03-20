#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int pid = fork();
	int pidd;
	if(pid == 0){
		pidd = fork();
		if(pidd == 0){
			printf("The child after fork(), launching ps -ef\n");
			char *arg[]={"/bin/ps", "-ef", NULL};
			execvp("/bin/ps", arg);
		}
		wait(NULL);
		printf("The child after fork(), launching free -h\n");
		char *args[]={"free", "-h", NULL};
		execvp("free", args);
	}
	else {
		wait(NULL);
		printf("Parent after fork()\n");
	}
	return 0;
}
	
