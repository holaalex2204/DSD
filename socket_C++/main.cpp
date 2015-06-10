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

void enviaPeticiones(void)
{
	for(;;)
	{		
		//printf("Wait sobre senderSem \n");
		sem_wait(&senderSem);
		printf("Enviando petición a : %s\n",paqueteEnviarDat->obtieneDireccion());
		socketDat->envia(*paqueteEnviarDat);
		//printf("Post sobre listenerSem\n");
		sem_post(&listenerSem);
		sleep(10);
		//printf("Wait sobre listenerSem \n");
		sem_wait(&listenerSem);
		//printf("Post sobre senderSem\n");
		sem_post(&senderSem);
	}
}
void GeneraTabla(void)
{
	int nume = 0 ;
	
	for(;;)
	{
		//printf("Wait sobre listenerSem \n");
		sem_wait(&listenerSem);
		printf("Esperando ŕespuesta...\n");
		socketDat->recibe(*paqueteRecibirDat);
		nume = 0;
		memcpy(&nume,paqueteRecibirDat->obtieneDatos(),sizeof(int));
		printf("Respuesta de %s\n",paqueteRecibirDat->obtieneDireccion());	
		listaIps.insert(paqueteRecibirDat->obtieneDireccion());
		imprimeSet();
		//printf("Post sobre listenerSem\n");
		sem_post(&listenerSem);
	}
}
int main()
{
	//SocketDatagrama socket  = NULL;
	char ipParcial[] = "192.168.0.255";
	char* ip = new char[18];
	int num[2];
	char* aux;
	int ultOcteto;
	printf("Ingresa un numero \n");
	scanf("%d",&num[0]);
	printf("Ingresa un numero \n" );
	scanf("%d",&num[1]);
	aux = (char *)num;
	
	//Inicializacion de variables
	PaqueteDatagrama paqueteRecibir = PaqueteDatagrama(4);
	PaqueteDatagrama paqueteEnviar = PaqueteDatagrama((char*)num,(sizeof(num)/sizeof(char)),ipParcial,7200);
	SocketDatagrama socket= SocketDatagrama(7200);
	//Asignación de variables a apuntadores globales
	socketDat = &socket;
	paqueteRecibirDat = &paqueteRecibir;
	paqueteEnviarDat = &paqueteEnviar;
	
	
	pthread_t listenerTh;
	sem_init(&listenerSem,0,0);
	sem_init(&senderSem,0,1);
	pthread_create(&listenerTh,NULL,GeneraTabla, NULL);
	pthread_t senderTh;
	pthread_create(&senderTh,NULL,enviaPeticiones, NULL);
	pthread_join(listenerTh,NULL);
	pthread_join(senderTh,NULL);
	printf("Ejecución Finalizada\n");
	return 0;
}