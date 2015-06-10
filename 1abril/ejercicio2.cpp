#include <iostream>
using namespace std;
int main()
{
	int iValorA;
	int iValorB;
	float fValorC;
	cout <<"EJERCICIO 2. " << endl;
	cout <<"Ingresa un número entero A: " << endl;
	cin >> iValorA;
	//Leemos B pero nos aseguramos de que sea distinto de 0 para que no haya ningun problema
	do{
		cout <<"Ingresa un número entero B diferente de 0: " << endl;
		cin >> iValorB;	
	}while(iValorB==0);
	//Leemos C pero nos aseguramos de que sea distinto de 0 para que no haya ningun problema
	do{
		cout <<"Ingresa un número flotante C diferente de 0: " << endl;
		cin >> fValorC;	
	}while(fValorC==0);
	//Imprimimos los valores de la división
	cout <<" La división de A/B es " << iValorA/iValorB << endl;
	cout <<" La división de A/C es " << iValorA/fValorC << endl;
	return 0;
}
