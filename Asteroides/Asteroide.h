#ifndef Asteroide_H_
#define Asteroide_H_ 
#include <iostream>
#include <cmath>
#include <vector>
#include "Coordenada.h"
#include "Vector2D.h"
using namespace std;

class Asteroide
{
private:
	long double alpha;
	long double rot;
	int numLados;
	long double r;
	Coordenada centro;
	const long double PI = acos(-1.0);
	vector <Coordenada> vertices;

public:
	Vector2D desplazamiento;
	Asteroide(int cantLados =3, long double radio =1.0);
	double calcArea();
	void posicionaCentro(Coordenada );
	Coordenada obtenCentro();
	vector<Coordenada> obtenVertices();
	int obtenNumLados();
	long double obtenRadio();
	void rota(long double velocidad);
};
#endif