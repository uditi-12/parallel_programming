/*Matrix Transpose*/
#include<stdio.h>
#include<mpi.h>

int main(){
	int arr[3][3],ans[3][3];
	int k=1;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			arr[i][j]=k++;
		}
	}
	int world_rank,world_size;
	MPI_Init(NULL,NULL);
	
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	printf("%d %d \n",world_rank,world_size);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			ans[j][i]=arr[i][j];
		}
	}
	for(int i=0;i<3;i++){
		printf("[");
		for(int j=0;j<3;j++){
			printf(" %d ",ans[i][j]);
		}
		printf("]\n");
	}
	MPI_Finalize();
	
	return 0;
}
