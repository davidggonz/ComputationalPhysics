#include <iostream>
#include <vector>
#include <mpi.h>

int main(int argc, char** argv) {
    int rank, size; // Número de procesos e identificación
    int size_vec = 100; // Tamaño de los vectores
    int loc_prod = 0;
    int tot_prod = 0;

    // Entorno MPI
    MPI_Init(&argc, &argv); // Inicializa MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Identificador del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Tamaño

    // Verifica si se proporcionó un argumento (tamaño del vector)
    if (argc != 2) {
        if (rank == 0) { // Proporciona el funcionamiento correcto del script
            std::cerr << "Uso: " << argv[0] << " [Tamaño del vector]" << std::endl;
        }
        MPI_Finalize(); // Finaliza MPI
        return 1;
    }

    try {
        size_vec = std::stoi(argv[1]); // Verificación del tamaño de los vectores
    }
    catch (const std::invalid_argument& e) {
        if (rank == 0) {
            std::cerr << "El tamaño del vector debe ser un número entero. MPI Finalizará." << std::endl;
        }
        MPI_Finalize();
        return 1;
    }

    // Verifica que el tamaño del vector sea divisible entre el número de procesos
    if (size_vec % size != 0) {
        if (rank == 0) {
            std::cerr << "El tamaño del vector debe ser múltiplo del número de procesos. MPI Finalizará." << std::endl;
        }
        MPI_Finalize();
        return 1;
    }

    // Rango de trabajo del script
    int nlocal = size_vec / size;

    // Declaración de los vectores involucrados en la distribución de datos
    std::vector<int> vect_a(size_vec), vect_b(size_vec);
    std::vector<int> local_a(nlocal), local_b(nlocal);

    local_a.resize(size_vec);
    local_b.resize(size_vec);

    // Llenar los vectores en el proceso 0
    if (rank == 0) {
	    vect_a.resize(size_vec);
            vect_b.resize(size_vec);
        	for (int i = 0; i < size_vec; ++i) {
            		vect_a[i] = vect_b[i] = i + 1;
        }
    }

    // Distribuir los datos a todos los procesos
    MPI_Scatter(vect_a.data(), nlocal, MPI_INT, local_a.data(), nlocal, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(vect_b.data(), nlocal, MPI_INT, local_b.data(), nlocal, MPI_INT, 0, MPI_COMM_WORLD);

    // Calcular el producto interno local en cada proceso
    for (int i = 0; i < nlocal; ++i) {
        loc_prod += local_a[i] * local_b[i];
    }

    // Sumar los productos locales en el proceso 0
    MPI_Reduce(&loc_prod, &tot_prod, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Imprimir el resultado en el proceso 0
    if (rank == 0) {
        std::cout << "El producto interno total es: " << tot_prod << std::endl;
    }

    MPI_Finalize();
    return 0;
}
