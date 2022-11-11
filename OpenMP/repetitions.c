/*Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.  Implement using OpenMP.  
 	Example:
Input:
N = 5
a[] = {2,3,1,2,3}
Output: 2 3 
Explanation: 2 and 3 occur more than once in the given array.
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int ans[n],k=0;
	#pragma omp parallel for
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]==arr[j]){
				if(k==0){
					ans[k++]=arr[i];
				}
				for(int t=0;t<k;t++){
					if(ans[t]!=arr[i])
						ans[k++]=arr[i];
				}
			}
		}
	}
	if(k==0){
		printf("Empty");
	}
	else{
		for(int i=0;i<k;i++){
			printf("%d ",ans[i]);
		}
	}
}
