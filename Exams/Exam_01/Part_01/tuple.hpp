#ifndef TUPLE_HPP
#define TUPLE_HPP

#include <iostream>
#include <stdexcept>

class Tuple {
private:
	double* data; //Puntero para datos
	size_t size; //Tamaño de la tupla
public:
	Tuple(); //Custom constructor con solo un valor 0.0
	Tuple(size_t n); //Custom constructor con n elementos 0.0
	Tuple(const Tuple& other); //Copy constructor
	~Tuple(); //Destructor que libera memoria de forma dinámica			 
	
	Tuple& operator=(const Tuple& other); //Operador asignación que elimina las fugas de memoria
	Tuple operator+(const Tuple& other) const; //Operador suma
	Tuple operator-(const Tuple& other) const; //Operador resta
	Tuple operator*(const Tuple& other) const; //Operador multiplicación
	Tuple operator/(const Tuple& other) const; //Operadr división
	
	void print() const; //Impresión de la tupla
	void SetValue(); //Asignación de valores para las tuplas
	void assignValues(const double* values, size_t n); // Asignación de valores
};

#endif
