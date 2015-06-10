#include <vector>

#include "Coordenada.h"
using namespace std;
#ifndef POLIGONO_H_
#define POLIGONO_H_ 
class Poligono
{
private:
	vector <Coordenada> vertices;
	int cuenta;
public:
	static int cantVertices;
	Poligono();
	void imprimeVertices();
	void anadeVertice(Coordenada punto);

};
#endif
