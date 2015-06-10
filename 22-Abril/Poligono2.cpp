#include <iostream>
#include "Poligono2.h"
using namespace std;
int Poligono2::cantVertices;
Poligono2::Poligono2() { 
	vertices.reserve(200);
	cuenta = 0;
}

void Poligono2::imprimeVertices()
{

	for(int i = 0 ; i< vertices.size();i++)
	{
		cout << "Para el vértice " << i << "  entonces, ("<< vertices[i].obtenerX() <<"," <<vertices[i].obtenerY() << ")" <<endl;
	}
}
void Poligono2::anadeVertice(Coordenada punto)
{
	vertices.push_back( punto);
	cuenta++;
	Poligono2::cantVertices++;
}