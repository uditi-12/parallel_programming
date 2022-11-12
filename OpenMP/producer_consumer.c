/*Write a program to implement a producer-consumer framework in OpenMP using sections to create a single producer task and a single consumer task. Ensure appropriate low level synchronization construct using locks. Test your program for a varying number of producers and consumers. */

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int mutex=1, full=0, empty=10,x=0;

void consumer(){
	--mutex;
	printf("\nConsumer consumes item %d",x);
	x++;
	--full;
	++empty;
	++mutex;
}

void producer(){
	--mutex;
	
	x++;
	printf("\nProducer produces item %d",x);
	++full;
	--empty;
	++mutex;
}

int main(){
	int n;
	#pragma omp critical
	
	for (int i = 1; i > 0; i++) {
		
		printf("\nEnter your choice:");
		scanf("%d", &n);
		
		// Switch Cases
		switch (n) {
			case 1:
				
				if ((mutex == 1) && (empty != 0)) {
					producer();
					}
					
					else {
						printf("Buffer is full!");
					}
					break;
				
			case 2:
				
				
				if ((mutex == 1) && (full != 0)) {
					consumer();
					}
					

					else {
						printf("Buffer is empty!");
					}
					break;
				
			case 3:
				exit(0);
				break;
		}
	}
}
	
