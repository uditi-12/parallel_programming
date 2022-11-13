/*Master generates 1/2,1/4,1/8,1/16...1/n; Worker generates 
2,4,8,16...n*/
#include<stdio.h>
#include<mpi.h>
int i=2;
int main(){
	MPI_Init(NULL,NULL);
	int world_rank,world_size;
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
	if(world_rank==0){
		printf("From master : ");
		for(int i=2;i<10;i=i*2)
		printf("1/%d , ",i);
		printf("\n");
	}
	else{
		printf("From worker: ");
		for(int i=2;i<10;i=i*2)
		printf("%d , ",i);
		printf("\n");
	}
	MPI_Finalize();
	return 0;
}
