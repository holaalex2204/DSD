#include <stdlib.h>
#include <iostream>
using namespace std;
class Fecha
{
private:
	int dia;
	int mes;
	int anio;
	static int vecesMuestF;
public:
	static int getVecesMuestF();
	Fecha(int = 3, int = 4, int = 2014);
	void inicializaFecha(int, int, int);
	void muestraFecha();
};
int Fecha::vecesMuestF = 0;
int Fecha::getVecesMuestF()
{
	/*
	Experimiento de intentar acceder a variables no estáticas desde una función estática:


ej1.cpp: In static member function ‘static int Fecha::getVecesMuestF()’:
ej1.cpp:7:6: error: invalid use of member ‘Fecha::dia’ in static member function
ej1.cpp:20:2: error: from this location
ej1.cpp:7:6: error: invalid use of member ‘Fecha::dia’ in static member function
ej1.cpp:20:8: error: from this location
ej1.cpp:8:6: error: invalid use of member ‘Fecha::mes’ in static member function
ej1.cpp:21:2: error: from this location
ej1.cpp:8:6: error: invalid use of member ‘Fecha::mes’ in static member function
ej1.cpp:21:8: error: from this location
ej1.cpp:9:6: error: invalid use of member ‘Fecha::anio’ in static member function
ej1.cpp:22:2: error: from this location
ej1.cpp:9:6: error: invalid use of member ‘Fecha::anio’ in static member function
ej1.cpp:22:9: error: from this location


	
	dia = dia+1;
	mes = mes +1;
	anio = anio +1;
	*/
	return vecesMuestF;
}
Fecha::Fecha(int dd, int mm, int aaaa)
{
	mes = mm;
	dia = dd;
	anio = aaaa;
}
void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
	anio = aaaa;
	mes = mm;
	dia = dd;
	return;
}
void Fecha::muestraFecha()
{
	cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
	vecesMuestF++;
	return;
}
int main()
{
	Fecha a, b, c(21, 9, 2000);
	b.inicializaFecha(17, 6 , 2000);
	a.muestraFecha();
	cout << "Se ha mandado llamar muestraFecha() " << a.getVecesMuestF() << " veces\n";
	b.muestraFecha();
	cout << "Se ha mandado llamar muestraFecha() " << b.getVecesMuestF() << " veces\n";
	c.muestraFecha();
	cout << "Se ha mandado llamar muestraFecha() " << c.getVecesMuestF() << " veces\n";
	return 0;
}