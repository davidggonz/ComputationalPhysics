#include <iostream>
#include <mpi.h>

int main() {
	//Se definen tanto el rango como el número de procesos
   	int size, rank;
	//Se define el buffer
    	int buffer;
	
    	int tag = 0;
	//Se inicializa el entorno MPI
   	MPI_Init(NULL, NULL);

   	MPI_Comm_size(MPI_COMM_WORLD, &size);
    	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    	buffer = rank;  //Buffer = rango del proceso
	MPI_Status stat; //Se asigna el status a 'stat'
	//Se inicializa el for para la comunicación circular
    	for (int i = 0; i < size; ++i) {
        	int send_to = (rank + 1) % size; //Envío p+1
        	int recv_from = (rank - 1 + size) % size; //Recibimiento p-1
		//Para el rango actual:
        	if (rank == 0) {
			//Se actualiza el buffer con recv_from
            		MPI_Sendrecv_replace(&buffer, 1, MPI_INT, send_to, tag, recv_from, tag, MPI_COMM_WORLD, &stat);
			//Proceso actual tiene buffer 'p-1'
            		std::cout << "Iteración " << i << ": Proceso 0 tiene buffer: " << buffer << std::endl;
        	} else {
			//Manejo de excepciones
           		MPI_Send(&buffer, 1, MPI_INT, send_to, tag, MPI_COMM_WORLD);
            		MPI_Recv(&buffer, 1, MPI_INT, recv_from, tag, MPI_COMM_WORLD, &stat);
        	}
    	}
	//Finaliza el entorno MPI
    	MPI_Finalize();
    	return 0;
}
