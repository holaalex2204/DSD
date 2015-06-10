#include <iostream>
#include "Coordenada.h"
#include <math.h> 
using namespace std;
Coordenada::Coordenada(double r, double ang) : x(cos(ang)*r), y(sin(ang)*r)
{ }
double Coordenada::obtenerX()
{

	return x;
}

double Coordenada::obtenerY()
{

	return y;
}
