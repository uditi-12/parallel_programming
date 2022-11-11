/*1.	Write an OpenMP program to implement a parallel Selection sort. Initialize an array of 5000 elements. Distribute the loop iterations to 32, 64, 128, 256 concurrent threads (static, dynamic, auto and guided) with a chunk-size of 10. Record your execution times for static, dynamic, auto and guided scheduling.  */

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int main(){
	int arr[5000];
	for(int i=0;i<5000;i++){
		arr[i]=rand()%10;
	}
	double t1=omp_get_wtime();
	
	#pragma omp prallel for schedule (static,10)
	for(int i=0;i<5000-1;i++){
		int min_idx=i;
		//#pragma omp parallel for
		for(int j=i+1;j<5000;j++){
			if(arr[j]<arr[min_idx])
				min_idx=j;
		}
		if(min_idx!=i){
			int t=arr[min_idx];
			arr[min_idx]=arr[i];
			arr[i]=t;
		}
		
	}
	
	double t2=omp_get_wtime();
	printf("%f",t2-t1);
	return 0;
}

/* use 
export SET_NUM_THREADS=16...256 for each type of concurrent threads
*/
