#include <iostream>
#include "Poligono.h"
using namespace std;
Poligono::Poligono() { }

int Poligono::cantVertices;
void Poligono::imprimeVertices()
{

	for(int i = 0 ; i< vertices.size();i++)
	{
		cout << "Para el vértice " << i << "  entonces, ("<< vertices[i].obtenerX() <<"," <<vertices[i].obtenerY() << ")" <<endl;
	}
}
void Poligono::anadeVertice(Coordenada punto)
{
	vertices.push_back(punto);
	Poligono::cantVertices++;
}