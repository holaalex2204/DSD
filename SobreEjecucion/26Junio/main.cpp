#include <stdio.h>
#include <stdlib.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>
#include <inttypes.h>
#include <fcntl.h>
#include "header.h"
SocketDatagrama* socketDat;
PaqueteDatagrama* paqueteEnviarDat;
PaqueteDatagrama* paqueteRecibirDat;
uint32_t ultimo = 0;
char * intToString(int num)
{
	char* arr = new char[3];
	arr[0] = (num/100) +48;
	arr[1] = ((num%100)/10) +48;
	arr[2] = ((num%10)) +48;
	return arr;
}
int StringToInt(char * a)
{
	int res = 0;
	int pos = 0;
	while(a[pos]!='\0')
	{
		res = res*10 + a[pos]-48;
		pos++;
	}
	return res;
}
int main(int args, char* argv[])
{
	
	char* ipParcial = argv[1];
	int puerto = StringToInt(argv[2]);
	struct messageCS msgToServer;
	struct messageSC msgFromServer;
	msgToServer.cantidadSolicitada = StringToInt((argv[3]));
	PaqueteDatagrama paqueteRecibir = PaqueteDatagrama(sizeof(struct messageSC));
	PaqueteDatagrama paqueteEnviar = PaqueteDatagrama((char*)&msgToServer,(sizeof(struct messageCS)),ipParcial,7777);
	SocketDatagrama socket= SocketDatagrama(puerto);
	int auxnum = socket.envia(paqueteEnviar);
	do
	{
		socket.recibe(paqueteRecibir);
		ultimo= ultimo +1;
		memcpy(&msgFromServer,paqueteRecibir.obtieneDatos(),sizeof(struct  messageSC));
		if(ultimo < msgFromServer.id)
		{
			printf("\t\tTrama perdida en %zu \n", ultimo );
			ultimo = msgFromServer.id;
		}
		if(ultimo%(msgToServer.cantidadSolicitada/10)==0)
		{
			printf("Estoy en el paquete %zu\n",ultimo );
		}
	}while(ultimo< msgToServer.cantidadSolicitada);
	printf("Ejecución Finalizada\n");
	return 0;
}