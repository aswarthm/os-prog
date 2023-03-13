#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* lol(void *o){
	int *val = (int *)o;
	printf("%d", (* val));
}

int main(){
	pthread_t p[4];

	int a[4] = {1, 2, 3, 4};

	for(int i = 0; i < 4; i++){
		pthread_create(&p[i], NULL, lol, (void*)&a[i]);
//		sleep(1);
	}
	for(int i = 0; i < 4; i++){
		pthread_join(p[i], NULL);
//		sleep(1);
	}
}
