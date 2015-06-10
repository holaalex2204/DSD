#include <iostream>
using namespace std;
int main()
{
	int n;
	cout <<"Ingresa un número entero n: ";
	cin >> n;
	//Calculamos el valor de la expresión
	cout <<"La expresión   n + (++n)  es: " << n + (++n) << endl;
	return 0;
}
