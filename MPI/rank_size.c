/*Print Rank, World size and Processor name

*/

#include<stdio.h>
#include<mpi.h>

int main(){
	
	MPI_Init(NULL,NULL);
	int world_size,world_rank,name_len;
	MPI_Comm_size(MPI_COMM_WORLD,&world_size);
	MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	MPI_Get_processor_name(processor_name,&name_len);
	printf("The size is: %d\n",world_size);
	printf("The rank is: %d\n",world_rank);
	printf("The processor_name is: %s\n",processor_name);
	MPI_Finalize();
	return 0;
}
