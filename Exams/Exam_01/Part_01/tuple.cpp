#include "tuple.hpp"

using namespace std;

Tuple::Tuple() : size(1) {
	data = new double[1]{0.0}; //Solo '1' valor al iniciar y es '0.0'
}

Tuple::Tuple(size_t n) : size(n) { //Contructor personalizado con 'n' como tamaño de la tupla
	//Hay que hacer manejo de excepciones por 'n = 0'
	if (n<=0) {
		throw invalid_argument("Escoja un valor mayor a 0");
	}
	//else {
	//	continue
	//}
	data = new double[n](); //Inicializa en 0.0 todos los n elementos de memoria	
}

//Copy constructor
Tuple::Tuple(const Tuple& other) : size(other.size) {
	data = new double[size]; //Se guardará en el heap
	for (size_t i = 0; i < size; ++i) {
		data[i] = other.data[i]; //Se copiarán los valores por cada i dentro del rango size
	}
}

Tuple& Tuple::operator=(const Tuple& other) {
	if (this == &other) return *this; //Evita autoasignación (no se necesita {})
	
	delete[] data; //Elimina lo guardado en el heap
	size = other.size;
	data = new double[size]; //Asigna nueva memoria
	for (size_t j=0; j < size; ++j) { //Se copiarán los valores elementos por elemento con el for
		data[j] = other.data[j];
	}
	return *this;
}

Tuple::~Tuple() {
	delete[] data; //Elimina lo guardado en el heap
}

Tuple Tuple::operator+(const Tuple& other) const {
    if (size != other.size) {
        throw runtime_error("Tienen que ser del mismo tamaño."); //Manejo de excepciones
    }
    Tuple result(size); //Se recibe el resultado
    for (size_t i = 0; i < size; ++i) {
        result.data[i] = data[i] + other.data[i]; //Suma por elementos de la tupla
    }
    return result;
}

Tuple Tuple::operator-(const Tuple& other) const {
    if (size != other.size) {
        throw runtime_error("Tienen que ser del mismo tamaño."); //Manejo de excepciones
    }
    Tuple result(size); //Se recibe el resultado
    for (size_t i = 0; i < size; ++i) {
        result.data[i] = data[i] - other.data[i]; //Resta por elemento de la tupla
    }
    return result;
}

Tuple Tuple::operator*(const Tuple& other) const {
    if (size != other.size) {
        throw runtime_error("Tienen que ser del mismo tamaño."); //Manejo de excepciones
    }
    Tuple result(size); //Se recibe el resultado
    for (size_t i = 0; i < size; ++i) {
        result.data[i] = data[i] * other.data[i]; //Resta por elemento de la tupla
    }
    return result;
}

Tuple Tuple::operator/(const Tuple& other) const {
    if (size != other.size) {
        throw runtime_error("Tienen que ser del mismo tamaño."); //Manejo de excepciones
    }
    Tuple result(size); //Recibe el resultado
    for (size_t i = 0; i < size; ++i) {
        if (other.data[i] == 0) {
            throw runtime_error("No se puede dividir entre cero."); // Para evitar que se divida entre 0
        }
        result.data[i] = data[i] / other.data[i]; //Divide por elemento de la tupla
    }
    return result;
}

//Se imprime todo como una lista '[a,b,c,d,...]'
void Tuple::print() const {
	cout << "[";
	for (size_t i=0; i < size; ++i) {
		cout <<  data[i] << " ";
	}
	cout << "]" << endl;
}

void Tuple::assignValues(const double* values, size_t n) {
    if (n != size) {
        throw std::invalid_argument("El tamaño de los valores no coincide con el tamaño de la tupla.");
    }
    for (size_t i = 0; i < size; ++i) {
        data[i] = values[i];
    }
}
