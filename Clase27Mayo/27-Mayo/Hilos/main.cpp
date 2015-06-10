#include <stdio.h>
#include <stdlib.h>
#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

char * intToString(int num)
{
	char* arr = new char[3];
	arr[0] = (num/100) +48;
	arr[1] = ((num%100)/10) +48;
	arr[2] = ((num%10)) +48;
	return arr;
}
int main()
{
	//SocketDatagrama socket  = NULL;
	const char* ipParcial = "192.168.0.255";
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
	SocketDatagrama socket= SocketDatagrama(7201);	
	int nume = 0;	

	//variable temporal
	unsigned char* ipAnterior;
	int hayIPanterior=0;
	int peticionIgual=0;
	printf("Enviando petición a : %s\n",ipParcial );
	socket.envia(paqueteEnviar,ipParcial);
	int k0=0;
	while(1){
		printf("Entro en while y es el ciclo k0: %d\n",k0);
		k0=k0+1;
		//socket.envia(paqueteEnviar,ipParcial);
		pid_t pid;
		int estado = 0;
		pid= fork();
		printf("PRINT debajo del PID\n");
		switch(pid){
			case -1:
			printf("Entro en condicion ERROR\n");
			//error
			break;
			case 0:
				printf("aRRIBA DE SocketRecive\n");
				socket.recibe(paqueteRecibir);
				
				nume = 0;
				if(hayIPanterior==1){
					if(paqueteRecibir.obtieneDireccion()==ipAnterior){
						peticionIgual=1;
					}
					else{
						peticionIgual=0;
					}
				}
				if(peticionIgual==0){
					memcpy(&nume,paqueteRecibir.obtieneDatos(),sizeof(int));
					printf("Respuesta de %s : %d\n",paqueteRecibir.obtieneDireccion(),nume);
					//Obtiene direccion Anterior
					memcpy(ipAnterior,paqueteRecibir.obtieneDireccion(),sizeof(paqueteRecibir.obtieneDireccion()));
					hayIPanterior=1;
				}
				
				//paqueteRecibir.inicializaIp("                ");
				//printf("Respuesta de %s : %d\n",paqueteRecibir.obtieneDireccion(),nume);
			break;
			default:
				printf("Entro en condicion DEFAULT\n"); 
				wait(&estado);
				exit(0);
			break;
		}
	}
	return 0;
}