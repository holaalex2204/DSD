#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "Poligono2.h"
using namespace std;
int main()
{
	srand(time(NULL));
	vector<Poligono2> pol;
	pol.reserve(100000);
	for(int i = 0 ; i<1; i++)
	{	
		pol.push_back( Poligono2());
		for(int j = 5 ; j>0;j--)
		{
			pol[i].anadeVertice(Coordenada(((rand()%200)-100), ((rand()%200)-100)));
		}
		pol[i].imprimeVertices();
		pol[i].ordenaVertices();
		cout << "Los vértices ordenados son;:" << endl << endl;
		pol[i].imprimeVertices();
	}
	cout << "La cantidad de vertices es" << Poligono2::cantVertices << endl;
	return 0;	
}