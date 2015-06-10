#include <stdio.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <string.h>
using namespace std;
char * intToString(int num)
{
	char* arr = new char[3];
	arr[0] = (num/100) +48;
	arr[1] = ((num%100)/10) +48;
	arr[2] = ((num%10)) +48;
	return arr;
}
void funcion()
{
	PaqueteDatagrama paqueteRecibir = PaqueteDatagrama(4);
	socket.recibe(paqueteRecibir);
}
int main()
{
	const char* ipParcial = "192.168.0.";
	char* ip = new char[18];
	int num[2];
	char* aux;
	int ultOcteto;
	printf("Ingresa un numero \n");
	scanf("%d",&num[0]);
	printf("Ingresa un numero \n" );
	scanf("%d",&num[1]);
	aux = (char *)num;
	PaqueteDatagrama paqueteRecibir = PaqueteDatagrama(4);
	PaqueteDatagrama paqueteEnviar = PaqueteDatagrama((char*)num,(sizeof(num)/sizeof(char)),"192.168.0.127",7200);	
	SocketDatagrama socket = SocketDatagrama(7201);
	for(ultOcteto = 125 ; ultOcteto<= 130; ultOcteto++)
	{	
		memcpy(ip,        ipParcial,strlen(ipParcial));
		memcpy(ip + strlen(ipParcial), intToString(ultOcteto), 3);
		ip[strlen(ipParcial)+3]='̈́\0';
		printf("Enviando petición a : %s\n",ip );
		socket.envia(paqueteEnviar,ip);
		pthread_t th1;
		pthread_create(&th1,NULL,(void *) funcion, NULL);
		socket.recibe(paqueteRecibir);
		int nume = 0;
		memcpy(&nume,paqueteRecibir.obtieneDatos(),sizeof(int));
		printf("Respuesta de %s : %d\n",ip,nume);
	
	}
	return 0;
}