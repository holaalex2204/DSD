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
	int destino = 0;
	char* ipParcial = argv[1];
	int puerto = StringToInt(argv[2]);
	struct messageCS msgToServer;
	struct messageSC msgFromServer;
	msgToServer.opcode = READ;
	msgToServer.count = BUF_SIZE;
	msgToServer.offset = 0;
	bzero(msgToServer.name,MAX_PATH-1);
	memcpy(msgToServer.name,argv[3],strlen(argv[3]));
	PaqueteDatagrama paqueteRecibir = PaqueteDatagrama(sizeof(struct messageCS));
	PaqueteDatagrama paqueteEnviar = PaqueteDatagrama((char*)&msgToServer,(sizeof(struct messageCS)),ipParcial,7777);
	SocketDatagrama socket= SocketDatagrama(puerto);
	printf("%d\n",sizeof(struct messageCS));
	printf("%d\n",sizeof(msgToServer));
	if((destino= open(argv[3], O_WRONLY|O_TRUNC|O_CREAT,0666))==-1)
	{
		char* msjError = new char[700];
		printf("Ocurrio algún error en el envío\n");
		printf ("Error al enviar : %s\n",strerror(errno));
		perror(msjError);
		printf("%s\n",msjError);
		delete msjError;
		return 0;
	}
	//Paquete Enviar Datos
	do
	{
		paqueteEnviar.inicializaDatos((char *)&msgToServer);
		printf("Enviando petición a : %s\n",paqueteEnviar.obtieneDireccion());
		int auxnum = socket.envia(paqueteEnviar);
		if(auxnum==-1)
		{
			char* msjError = new char[700];
			printf("Ocurrio algún error en el envío\n");
			printf ("Error al enviar : %s\n",strerror(errno));
			perror(msjError);
			printf("%s\n",msjError);
			delete msjError;
		}
		printf("Esperando ŕespuesta...\n");
		socket.recibe(paqueteRecibir);
		memcpy(&msgFromServer,paqueteRecibir.obtieneDatos(),sizeof(struct  messageSC));
		printf("Recibí %d en total, y %d en este paquete.\n", msgToServer.offset+msgFromServer.count, msgFromServer.count);
		msgToServer.offset+= BUF_SIZE;
		write(destino,msgFromServer.data,msgFromServer.count);
	}while(msgFromServer.count==BUF_SIZE);
	close(destino);
	printf("Ejecución Finalizada\n");
	return 0;
}