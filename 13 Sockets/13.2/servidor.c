#include "sock-lib.h"

void wait_childs_handler (int sig){

    pid_t pid;
    
    while((pid = waitpid(-1, NULL, WNOHANG)) > 0)// waitpid(,,WNOHANG) es NO bloqueante. wait() es bloqueante. 
											// Y sumado al while, termina liberando a todos los hijos muertos.
    {
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
		sockdup = Aceptar_pedidos (sockfd); // File descriptor del cliente que se conectó
			// Aceptar_pedidos es BLOQUEANTE. Se queda esperando a que un cliente se conecte.
		pidFork = fork();

		if(pidFork==0){ // Hijo
			close(sockfd);
			if (write (sockdup, message , sizeof (message)) == -1)
			{
				perror("Error escribiendo mensaje en socket");
				exit (1);
			}
			close(sockdup);
			exit(0);
		}else if(pidFork==-1){ // Error al llamar fork()
				perror ("Falló la conexión (función fork()"); 
				exit (1);
		}else{
			close(sockdup);
		}		
	}
}

// los hijos dejaron de estar Z. Funciona todo como debería.
