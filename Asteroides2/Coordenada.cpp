#include <iostream>
#include "Coordenada.h"
#include <math.h> 
using namespace std;
Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)
{ }
double Coordenada::obtenerX()
{

	return x;
}

double Coordenada::obtenerY()
{

	return y;
}
double Coordenada::calcDistancia(Coordenada c)
{
	return sqrt((c.obtenerX()-x)*(c.obtenerX()-x) + (c.obtenerY()-y)*(c.obtenerY()-y));
}
