#include <iostream>
#include "complex.hpp"

int main(){
	Complex comp(0.0,0.0);
	std::cout << "Parte real: " << comp.real << ", Parte imaginaria: " << comp.imagin << std::endl;
	return 0;
}

