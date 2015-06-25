#include "Asteroide.h"
#include "Coordenada.h" 
#include <iostream>
#include <cmath>
#include <stdlib.h> 
#include <time.h>
#include "Vector2D.h"
using namespace std;
Asteroide::Asteroide(int cantLados, long double radio) 
{ 
	
	double aux;
	r = radio;
	numLados = cantLados;
	alpha = 2*PI/cantLados;
	for(int i = 0; i<cantLados; i++)
	{
		srand (i*7367);
		aux =100/((float)((rand()%30 + rand()%10)+100));
		vertices.push_back(Coordenada(sin(alpha*i)*r*1,cos(alpha*i)*r*1));		
	}
	centro = Coordenada(-100,-100);
	rot = 0;
	desplazamiento = Vector2D((float)rand(),(float)rand());
	if(((int)desplazamiento.getX())%2==0)	desplazamiento.setX(-desplazamiento.getX());
	if(((int)desplazamiento.getY())%2==0)	desplazamiento.setY(-desplazamiento.getY());
	desplazamiento.normaliza();
}
double Asteroide::calcArea() //Calcula el área del círculo
{
	return(numLados*sin(alpha/2)*cos(alpha/2)*r*r);
}
void Asteroide::posicionaCentro(Coordenada cent)
{
	centro = cent; 
}
Coordenada Asteroide::obtenCentro()
{
	return centro;
}
vector<Coordenada> Asteroide::obtenVertices()
{
	vector<Coordenada> v;
	double x = 0;
	double y = 0;
	for(int i = 0; i<numLados;i++)
	{
		//aplicamos rotacion
		x = vertices[i].obtenerX()*cos(rot)-vertices[i].obtenerY()*sin(rot);
		y = vertices[i].obtenerY()*cos(rot)+vertices[i].obtenerX()*sin(rot);
		v.push_back(Coordenada(x + centro.obtenerX() ,  y + centro.obtenerY()));
	}
	return v;
}
int Asteroide::obtenNumLados()
{
	return numLados;
}
long double Asteroide::obtenRadio()
{
	return r;
}
void Asteroide::rota(long double velocidad)
{
	rot = rot + 2*PI/1000*velocidad;
}
bool Asteroide::choca(Asteroide* ast)
{
	if (obtenCentro().calcDistancia(ast->obtenCentro())< (obtenRadio() + ast->obtenRadio()))
	{
		return true;
	}
	return false;
}