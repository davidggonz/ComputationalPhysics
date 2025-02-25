#include <iostream>
#include <cmath>

//Se incluye el archivo por declaración
#include "complex.hpp"

//Constructor que inicializa
Complex::Complex() : real(0.0), imagin(0.0) {}

Complex::Complex(double real, double imagin) : real(real), imagin(imagin) {}

Complex::Complex(const Complex &obj){ //Constructor copia
  	std::cout << "Copy constructor invoked!" << std::endl;
  	real = obj.real;
  	imagin = obj.imagin;
}

//Destructor
Complex::~Complex() {}

Complex &Complex::operator=(const Complex &obj){ //Operador de asignación
  	std::cout << "Assignment operator invoked!" << std::endl;
  	real = obj.real;
 	imagin = obj.imagin;
  	return *this;
}

double Complex::norm(){ //Se crea la función para sacar la norma
 	double nor = real*real + imagin*imagin;
  	return std::sqrt(nor);
}

double Complex::conjugate() const { //Se crea la función para sacar el conjugado
 	return Complex(real - imagin);
}

Complex &Complex::operator+(const Complex &obj) const { //Operador suma
  	return Complex(real + obj.real, imagin + obj.imagin);
}

Complex &Complex::operator-(const Complex &obj){ //Operador sustracción
  	return Complex(real - obj.real,imagin - obj.imagin);
}

Complex &Complex::operator*(const Complex &obj){ //Operador multiplicación
  	//temp.real = real * obj.real + imagin * obj.imagin; (Pruebas)
  	//temp.imagin = real * obj.imagin imagin * obj.real
  	return Complex(real * obj.real + imagin * obj.imagin, real * obj.imagin imagin * obj.real);
}

Complex &Complex::operator/(const Complex &obj){ //Operador división
  	double den = obj.real * obj.real + obj.imagin * obj.imagin;
	return Complex((real * obj.real + imagin * obj.imagin)/(den),
		(-real * obj.imagin + imagin * obj.real)/(den));		
}








