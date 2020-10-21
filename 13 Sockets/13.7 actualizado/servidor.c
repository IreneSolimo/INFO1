#include "servidor.h"

//variables globales
int childs=0;
int max_childs=0;
int flag_max_childs=0;

int main ()
{
	int sockfd; /* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
	char message[] = "Hello, world!";
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */
	int sockdup;
	int pidFork; 
	
	max_childs = leerArchivoConfig("./etc/servidor.conf", "childs");
	sig_trap();
		//sockfd es el socket original, para establecer la conexión -> de ahí N + 1
		//se usa sólo para Aceptar_pedidos()
	if ((sockfd = Open_conection (&my_addr)) == -1) // File descriptor del socket
	{
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}

	while(1)
	{
		if(childs<max_childs){
			if(flag_max_childs==1){
				max_childs = leerArchivoConfig("./etc/servidor.conf", "childs");
				flag_max_childs=0;
				printf("Nuevo parámetro MAX CHILDS:%i\n",max_childs);
			}
			sockdup = Aceptar_pedidos (sockfd); // File descriptor del cliente que se conectó
				// Aceptar_pedidos es BLOQUEANTE. Se queda esperando a que un cliente se conecte.
			childs ++;
			pidFork = fork(); 

			if(pidFork==0){ // Hijo
				close(sockfd);
				child_process(sockdup);
				close(sockdup);
				exit(0);
			}else if(pidFork==-1){ // Error al llamar fork()
					perror ("Falló la conexión (función fork()"); 
					exit (1);
			}else{
				close(sockdup);
			}
		}else{sleep (5);//forma de limitar recursos
		}				
	}
}