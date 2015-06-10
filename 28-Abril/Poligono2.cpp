#include <iostream>
#include <algorithm>
#include "Coordenada.h"
#include "Poligono2.h"
using namespace std;
int Poligono2::cantVertices;
Poligono2::Poligono2() { 
	vertices.reserve(200);
	cuenta = 0;
}

void Poligono2::imprimeVertices()
{
	vector<Coordenada>::iterator i;
	for(i= vertices.begin() ; i!= vertices.end();i++)
	{
		cout << "Para el vértice " << "  entonces, ("<< i->obtenerX() <<"," << i->obtenerY() << " con distancia " << i->obtenerDist() <<endl;
	}
}
void Poligono2::anadeVertice(Coordenada punto)
{
	vertices.push_back( punto);
	cuenta++;
	Poligono2::cantVertices++;
}

void Poligono2::ordenaVertices()
{
	sort(vertices.begin(),vertices.end(),Coordenada::miFuncion);
}