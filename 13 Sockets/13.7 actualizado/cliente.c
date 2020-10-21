#include "sock-lib.h"
#define PATH "./bin"
#define SIZE_BUF 128
#define MSG_ERROR "ERROR!: "

#define MAXDATASIZE 4096/* máxima cantidad de bytes que puede recibir en una transacción*/
#define PEDIDOS 10000
/*
	IP -> Computadora en una red
	Puerto -> proceso corriendo en la computadora
*/

int main(int argc, char * argv[])
{
	int sockfd;  /*File Descriptor para sockets*/
	int numbytes;/*Contendrá el número de bytes recibidos por read () */
	char buf[MAXDATASIZE];  /* Buffer donde se reciben los datos de read ()*/
	int i =0;
/* Tratamiento de la línea de comandos. */
	if (argc < 2)
	{
		fprintf(stderr,"uso: %s hostname [port]\n",argv [0]);
		exit(1);
    }
	sockfd = conectar (argc, argv);
	proceso(sockfd);
	close(sockfd);
	return 0;
}

void proceso(int s){
	char msg_serv[SIZE_BUF];
	int aux;

    write(s, PATH, strlen(PATH)+1);
    read(s, msg_serv, SIZE_BUF);
	if(strlen(msg_serv)>2){
		printf("Error al abrir archivo: %s \n", msg_serv+strlen(MSG_ERROR));
		exit(-1);
	}
	while(1){
		alarm(30);
		aux=read(s, msg_serv, SIZE_BUF);
		if(aux==-1 && errno==EINTR){ // falló porinterrupción EINTR
		/////////
			printf("Fin de transmisión\n");
			exit(0);
		}		
	}
	return 0;
}