#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "Poligono.h"
using namespace std;
int main()
{
	Poligono pol;
	pol.anadeVertice(Coordenada(0,0));
	pol.anadeVertice(Coordenada(1,1));
	pol.anadeVertice(Coordenada(2,0));
	pol.imprimeVertices();
	return 0;	
}