/* Definiciones necesarias para los clientes y el servidor de archivos */ 
#define BUF_SIZE     1000
//Cantidad de bytes que se transfieren por paquete 
/* Definición de las operaciones permitidas */ 
/* Formato del mensaje
que viaja del cliente hacia el servidor
*/ 
struct messageCS
{ 
	uint32_t cantidadSolicitada; //Cantidad de paquetes solicitada
};
/* Formato del mensaje
que viaja del servidor
hacia el cliente
*/ 
struct messageSC
{ 
	uint32_t id;             //Identificador
	char data[BUF_SIZE];    //Datos del archivo basura 
}; 
