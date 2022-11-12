/*Write a multithreaded program in OpenMP program to implement the following. Given three arrays sorted in increasing order. Find the elements that are common in all three arrays. Also find out the sum of these common elements in all the three arrays. Record your execution times for static, dynamic, auto and guided scheduling.  */

#include<stdio.h>
#include<omp.h>

int main(){
	
	int n=10;
	int arr1[] = { 1, 5, 10, 20, 40, 80 };
	int arr2[] = { 6, 7, 20, 80, 100 };
	int arr3[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
	int i=0,j=0,k=0;
	int arr_final[n],l=0;
	double t1=omp_get_wtime();
	#pragma omp parallel
	while(i<n && j<n && k<n){
		if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
			arr_final[l++]=arr1[i];
			i++;
			j++;
			k++;
		}
		else if(arr1[i]<arr2[j])
			i++;
		else if(arr2[j]<arr3[k])
			j++;
		else
			k++;
	}
	int sum=0;
	#pragma omp parallel for reduction(+:sum)
	for(int i=0;i<l;i++)
		sum+=arr_final[i];
	double t2=omp_get_wtime();
	printf("%d\n%f",sum,t2-t1);
	
}
