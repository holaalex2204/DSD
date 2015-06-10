#include <iostream>
#include <cmath>
using namespace std;
/* Descripción del problema:
Escriba un programa que i
mprima la altura de un edificio, si se conoce el tiempo que tardó una
pelota de tenis desde que se dejó caer en la parte más alta del e
dificio y hasta llegar al piso
*/
const double GRAVEDAD  = 9.81;
int main()
{
	
	float tiempoCaida;
	float altura;
	cout <<"Ingresa el tiempo que tardo la pelota de tennis en tocar el suelo" << endl;
	cin >> tiempoCaida;
	//Obtenemos la altura a partir de la siguiente ecuación y = 1/2 * 9.81* tiempoCaida
	altura = 0.5 * GRAVEDAD * pow(tiempoCaida,2);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout <<" La altura del edificio es " << altura << " metros"<< endl;
	return 0;
}