/*Write an OpenMP program to implement a parallel Heap sort. Construct an array of 10000 elements. Distribute the loop iterations to 16, 32, 64 concurrent threads (static, dynamic and auto) with a chunk-size of 5. Record your execution times for static, dynamic, auto and guided scheduling.    */

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
void swap(int a, int b)
{
	
	int temp = a;
	
	a = b;
	
	b = temp;
}
void heapify(int arr[], int N, int i)
{
	
	// Initialize largest as root
	int largest = i;
	
	// left = 2*i + 1
	int l = 2 * i + 1;
	
	// right = 2*i + 2
	int r = 2 * i + 2;
	
	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;
	
	// If right child is larger than largest
	// so far
	if (r < N && arr[r] > arr[largest])
		largest = r;
	
	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);
		
		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}
/*
// Main function to do heap sort
void heapSort(int arr[], int N)
{
	
	// Build heap (rearrange array)
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
	
	// One by one extract an element
	// from heap
	for (int i = N - 1; i > 0; i--) {
		
		// Move current root to end
		swap(arr[0], arr[i]);
		
		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}
*/
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	double t1=omp_get_wtime();
	/*
	#pragma omp parallel for schedule (static,10)
	heapSort(arr,n);
	*/
	#pragma omp parallel for schedule (static,5)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	#pragma omp parallel for schedule (static,5)
	for (int i = n - 1; i > 0; i--) {
		
		// Move current root to end
		swap(arr[0], arr[i]);
		
		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
	
	double t2=omp_get_wtime();
	printf("%f",t2-t1);
}
