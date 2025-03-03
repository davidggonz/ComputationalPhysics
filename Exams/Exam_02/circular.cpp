#include <mpi.h> //Entorno MPI
#include <iostream> //Por defecto

int main(int argc, char** argv) { 
    	//Inicialización el entorno MPI
	MPI_Init(&argc, &argv);
    	//Se definen tanto el rango como el número total de procesos
	int rank, size;
    	MPI_Comm_rank(MPI_COMM_WORLD, &rank);  //Rango del proceso actual
    	MPI_Comm_size(MPI_COMM_WORLD, &size);  //Número total de procesos

    	int buffer_send = rank;  //Cada proceso almacena su rango en el buffer de envío
    	int buffer_recv;         //Inicialmente, cada proceso tiene un buffer en el cual almacena su rango

    	// Definir los rangos de los procesos vecinos
    	int next_rank = (rank + 1) % size;
    	int prev_rank = (rank - 1 + size) % size;

    	// Realizar la comunicación circular
    	for (int i = 0; i < size; ++i) {
		//Parte c) {{
        	// Enviar el mensaje al proceso siguiente
		// e)Comunicación bloqueada
        	MPI_Send(&buffer_send, 1, MPI_INT, next_rank, 0, MPI_COMM_WORLD);//Cada proceso p le envı́a un mensaje al proceso p + 1

        	// Recibir el mensaje del proceso anterior
		// e)Cominucación bloqueada
	        MPI_Recv(&buffer_recv, 1, MPI_INT, prev_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);//Recibe un mensaje del proceso p − 1
		//Final de la parte c}}
		//Parte d)
	        // Actualizar el buffer de envío con el mensaje recibido
	        buffer_send = buffer_recv;
		//Parte f)	
        	// Imprimir el mensaje recibido
	        std::cout << "Proceso " << rank << " recibió el mensaje " << buffer_recv << " del proceso " << prev_rank << std::endl;
	    }

	    // Finalizar el entorno MPI
	    MPI_Finalize();

	    return 0;
}
