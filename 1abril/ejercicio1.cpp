#include <iostream>
#include <cmath>
using namespace std;

int main( )
{
	int radio;
	double area;
	const double PI = 3.1415926;
	cout << "EJERCICIO 1. AREA DE UN CIRCULO.\n";
	cout << "Introduce el radio del circulo: ";
	cin >> radio;
	area = PI * pow(radio,2);
	cout << "El area del circulo es: \t" << area << endl;
	//Modificando el valor de PI
	cout << "Introduce el nuevo valor de PI: \t" << endl;
	cin >> PI;
	area = PI * pow(radio,2);
	return 0;
}
