#include <stdio.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <string.h>
using namespace std;
int main()
{
	int num[2];
	char* aux;
	printf("Ingresa un numero \n");
	scanf("%d",&num[0]);
	printf("Ingresa un numero \n" );
	scanf("%d",&num[1]);
	aux = (char *)num;
	PaqueteDatagrama paqueteRecibir = PaqueteDatagrama(4);
	PaqueteDatagrama paqueteEnviar = PaqueteDatagrama((char*)num,(sizeof(num)/sizeof(char)),"192.168.0.127",7200);	
	SocketDatagrama socket = SocketDatagrama(7201);
	socket.envia(paqueteEnviar);
	socket.recibe(paqueteRecibir);
	int nume = 0;
	memcpy(&nume,paqueteRecibir.obtieneDatos(),sizeof(int));
	printf("%d\n",nume);
	/*
	printf("%c\n",nume);
	printf("%s\n",nume);
	printf("%d\n",nume);
	printf("%i\n",nume);
	printf("%o\n",nume);
	printf("%u\n",nume);
	printf("%x\n",nume);
	*/
	return 0;
}