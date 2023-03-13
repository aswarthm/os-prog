#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex, wr;
int count;

void writer(void *val){
	int *o = (int*)val;
	sem_wait(&wr);
	printf("Writer %d Writing\n", (* o));
	sem_post(&wr);
}

void reader(void *val){
	int *o = (int *)val;
	sem_wait(&mutex);
	count++;
	if(count == 1){
		sem_wait(&wr);
	}
	sem_post(&mutex);
	printf("reder %d reading\n", (* o));
	sem_wait(&mutex);
	count--;
	if(count == 0){
		sem_post(&wr);
	}
	sem_post(&mutex);
}

int main(){
	sem_init(&mutex, 0, 1);
	sem_init(&wr, 0, 1);

	int a[] = {1, 2, 3, 4};

	pthread_t p[6];
	for(int i = 0; i < 3; i++){
		pthread_create(&p[i], NULL, writer, &a[i]);
	}
	for(int i = 3; i < 6; i++){
		pthread_create(&p[i], NULL, reader, &a[i-3]);
	}

	for(int i = 0; i < 6; i++){
		pthread_join(p[i], NULL);
	}
}
