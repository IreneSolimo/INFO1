#include "sock-lib.h"
#include "aux.h"

//variables globales
int childs=0;
int max_childs=0;
int flag_max_childs=0;


//debería ser corto~
void sig_handler_new_config (int sig){
	flag_max_childs =1;
}


void wait_childs_handler (int sig){

    pid_t pid;
    
    while((pid = waitpid(-1, NULL, WNOHANG)) > 0)// waitpid(,,WNOHANG) es NO bloqueante. wait() es bloqueante. 
											// Y sumado al while, termina liberando a todos los hijos muertos.
    {
		childs --;
    }
}

/*
	int  fd = open    // file descriptor (UNIX)
	FILE * fp = fopen // file pointer (Cross-platform)
*/

// N + 1 File descriptors (N: cant de clientes + 1 por el socket)

int main ()
{
	int sockfd; /* File Descriptor del socket por el que el servidor "escuchará" conexiones*/
	char message[] = "Hello, world!";
	struct sockaddr_in my_addr;	/* contendrá la dirección IP y el número de puerto local */
	int sockdup;
	int pidFork; 
	
	max_childs = leerArchivoConfig("./etc/servidor.conf", "childs");

	signal (SIGHUP, sig_handler_new_config);
	signal (SIGCHLD, wait_childs_handler);
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
				if (write (sockdup, message , sizeof (message)) == -1)
				{
					perror("Error escribiendo mensaje en socket");
					exit (1);
				}
				sleep (5); //Simula un cierto proceso del hijo
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

// los hijos dejaron de estar Z. Funciona todo como debería.
// Al probarlo dos veces seguidas y cerrar servidor con ctrl+C, se debe cambiar desde sock-lib.h el nro de puerto o esperar.
// Aparece error desde la función bind. Nunca ejecuta correctamente close(sockfd) ->Open_conection


// haciendo ps en ejecución se ven 10 hijps "S".