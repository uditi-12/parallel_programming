/*Master prints, “I am Master”, and worker prints, “I am 
worker”*/
#include<stdio.h>
#include<mpi.h>

int main(){
	MPI_Init(NULL,NULL);
	int world_size,world_rank;
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
	if(world_rank==0)
		printf("I am the master with rank : %d\n",world_rank);
	else
		printf("I am the worker with rank : %d\n",world_rank);
	MPI_Finalize();
}
