#include <iostream>
#include <cmath>
using namespace std;

int main( )
{
	double precio = 78.7;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "EJERCICIO 6.\n";
	cout << "El precio es: \t" << precio << endl;
	return 0;
}
