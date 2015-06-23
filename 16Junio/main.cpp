#include <stdio.h>
#include <stdlib.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <set>
#include <iostream>
#include <errno.h>

//Librerias incluidas
#include <inttypes.h>
#include "header.h"

sem_t listenerSem;
sem_t senderSem;
SocketDatagrama* socketDat;
PaqueteDatagrama* paqueteEnviarDat;
PaqueteDatagrama* paqueteRecibirDat;
std::set<char*> listaIps;
void imprimeSet()
{
	printf("El tamaño del set es : %d\n", listaIps.size());
	for(std::set<char*>::iterator it = listaIps.begin(); it!=listaIps.end();++it)
	{
		printf("%s\n",*it );
	}
}
void limpiaTabla()
{
	imprimeSet(); 	
	listaIps.clear();
	imprimeSet();
}
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
void enviaPeticiones(void)
{

	printf("Enviando petición a : %s\n",paqueteEnviarDat->obtieneDireccion());
	int aux = socketDat->envia(*paqueteEnviarDat);
	if(aux==-1) 
	{
		char* msjError = new char[700];
		printf("Ocurrio algún error en el envío\n");
		printf ("Error al enviar : %s\n",strerror(errno));
		perror(msjError);
		printf("%s\n",msjError);
		delete msjError;
	}
	for(;;)
	{		
		//printf("Wait sobre senderSem \n");
		//sem_wait(&senderSem);	
		imprimeSet();
		printf("Limpiando la tabla\n");
		limpiaTabla();
		socketDat->envia(*paqueteEnviarDat);
		//printf("Post sobre listenerSem\n");
		//sem_post(&listenerSem);
		sleep(10);
		//printf("Wait sobre listenerSem \n");
		//sem_wait(&listenerSem);
		//printf("Post sobre senderSem\n");
		//sem_post(&senderSem);
	}
}
void GeneraTabla(void)
{
	int nume = 0 ;
	
	for(;;)
	{
		//printf("Wait sobre listenerSem \n");
		//sem_wait(&listenerSem);
		printf("Esperando ŕespuesta...\n");
		socketDat->recibe(*paqueteRecibirDat);
		nume = 0;
		memcpy(&nume,paqueteRecibirDat->obtieneDatos(),sizeof(int));
		printf("Respuesta de %s\n",paqueteRecibirDat->obtieneDireccion());	
		listaIps.insert(paqueteRecibirDat->obtieneDireccion());
		//printf("Post sobre listenerSem\n");
		//sem_post(&listenerSem);
	}
}
int main(int args, char* argv[])
{
	//SocketDatagrama socket  = NULL;

	printf("%s primer parametro del linea de comandos\n",argv[1]);
	printf("%s segundo parametro del linea de comandos\n",argv[2]);
	printf("%s tercer parametro del linea de comandos\n",argv[3]);

	//char ipParcial[] = "10.211.55.255";
	char* ipParcial = argv[1];
	printf("%s primer parametro del linea de comandos\n",ipParcial);
	int num[2];
	char* aux;
	int ultOcteto;
	int puerto = StringToInt(argv[2]);
	printf("Puerto %d\n", puerto);
	printf("Ingresa un numero \n");
	scanf("%d",&num[0]);
	printf("Ingresa un numero \n" );
	scanf("%d",&num[1]);
	aux = (char *)num;
	
	//Inicializacion de variables
	struct messageCS msgToServer;
	msgToServer.opcode = READ;
	msgToServer.count = 1000;
	msgToServer.offset = 0;
	memcpy(msgToServer.name,argv[3],strlen(argv[3])*sizeof(char));
	printf("%d\n",msgToServer.opcode);
	printf("%d\n",msgToServer.count);
	printf("%d\n",msgToServer.offset);
	printf("%s\n", msgToServer.name);
	int nume;	
	PaqueteDatagrama paqueteRecibir = PaqueteDatagrama(4);
	PaqueteDatagrama paqueteEnviar = PaqueteDatagrama((char*)&msgToServer,(sizeof(struct messageCS)),ipParcial,7777);
	SocketDatagrama socket= SocketDatagrama(puerto);
	//Asignación de variables a apuntadores globales
	socketDat = &socket;
	paqueteRecibirDat = &paqueteRecibir;
	paqueteEnviarDat = &paqueteEnviar;
	printf("Enviando petición a : %s\n",paqueteEnviarDat->obtieneDireccion());
	int auxnum = socketDat->envia(*paqueteEnviarDat);
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
	socketDat->recibe(*paqueteRecibirDat);
	nume = 0;
	memcpy(&nume,paqueteRecibirDat->obtieneDatos(),sizeof(int));
	printf("Respuesta de %s\n",paqueteRecibirDat->obtieneDireccion());	

	printf("Ejecución Finalizada\n");
	return 0;
}