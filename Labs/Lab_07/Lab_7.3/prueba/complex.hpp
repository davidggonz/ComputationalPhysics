#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex {
  private:
  	int m_n;	//Esto es solamente probando (no darle importancia)
	Complex();
  public:
	double real; // Número real
	double imagin; // Número imaginario
	double conjugate() const; // Obtención del conjugado
  	double norm() const; //Sacar la norma
	Complex(double real, double imagin); //Custom Constructor
	~Complex(); //Destructor
	float *data(); //Esto es solamente probando (no darle importancia)
	Complex(const Complex &obj); //Copy constructor
	Complex &operator=(const Complex &obj); //Assignment operator
	Complex operator+(const Complex &obj) const; //Sumation
	Complex operator-(const Complex &obj) const; //Sustraction
	Complex operator*(const Complex &obj) const; //Multiplication
	Complex operator/(const Complex &obj) const; //Division
};
#endif
