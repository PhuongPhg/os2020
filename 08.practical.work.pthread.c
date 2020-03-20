#include <stdio.h>
#include <pthread.h>

void *primeNumber(void* param) {
	
	printf("The prime number is: \n");
	for(int i=2; i<1000001; i++){
		int check=0;
		for(int j=2; j<=i/2; j++){
			if(i%j==0) check = 1;
			}
		if (check ==0) printf("%d ", i);
	}
	printf("\n");
	return NULL;	
}

void *fibonancci (void* param){
	int a=1,b=2;
	int c=0, n=0;
	int arr[2000];
	printf("\nThe fibonancci sequence is\n");
	while (b<1000001){
		printf("%d ",b); 
		c=a+b;
		a=b;
		b=c;
	}
	printf("\n");
	return NULL;
}

int main() {
	pthread_t tid;
	pthread_t tidd;
	printf("This is the main thread speaking\n");
	getchar();
	pthread_create(&tid, NULL, primeNumber, NULL);
	pthread_join(tid, NULL);
	pthread_create(&tidd, NULL, fibonancci, NULL);
	pthread_join(tidd, NULL);
}




