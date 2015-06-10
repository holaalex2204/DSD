#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);
class Circulo
{
private:
	double radio;
public:
	Circulo(double = 1.0);
	double calcval();
};
Circulo::Circulo(double r) : radio(r)
{ }
double Circulo::calcval() //Calcula el área del círculo
{
	return(PI * radio * radio);
}
class Cilindro : public Circulo
{
private:
	double longitud;
public:
	Cilindro(double r = 1.0, double l = 1.0) : Circulo(r), longitud(l) {}
	double calcval();
};
double Cilindro::calcval() //Calcula el volumen del cilindro
{
	return (longitud * Circulo::calcval());
}
int main()
{
	double piDouble = PI;
	long double piLong = PI;
	float piFLoat = PI;
	Circulo Circulo_1, Circulo_2(2);
	Cilindro Cilindro_1(3,4);
	cout << "El área de Circulo_1 es " << Circulo_1.calcval() << endl;
	cout << "El área de Circulo_2 es " << Circulo_2.calcval() << endl;
	cout << "El volumen de Cilindro_1 es " << Cilindro_1.calcval() << endl;
	Circulo_1 = Cilindro_1;

	cout << "\nEl área de Circulo_1 es ahora " << Circulo_1.calcval() << endl;
	cout.precision(40);
	cout << "piDouble: \t" <<piDouble << endl;
	cout << "piLong: \t" <<piLong << endl;
	cout << "piFLoat: \t" <<piFLoat << endl;
	return 0;
}