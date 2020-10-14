/*Tomar el código desarrollado en el Ejercicio 12.2 y mejore el handler utilizando la función waitpid (),
utilizando WNOHANG para el argumento opciones (3er. Argumento), de modo de poder cerrar la totalidad
de procesos childs que están solicitando exit (), por cada ciclo de uso del handler de SIGCHLD. Repita
el comando ps -elf | grep [nombre del programa ejecutable] | grep defunct |
wc -l en otra consola y observe el resultado. Escribir un pequeño reporte en un archivo de texto plano a
modo de reseña.*/

#include <stdio.h>
#include <unistd.h> // fork
#include <errno.h>  // errno
#include <string.h> // strerror
#include <unistd.h> // sleep
#include <sys/types.h>
#include <sys/wait.h> // wait
#include <stdlib.h>
#define CHILDS 10000

// pid_t fork(void);
// unsigned int sleep(unsigned int seconds);
void wait_childs_handler (int sig){
//	printf ("se murio un hijo. soy %d\n", getpid ());

    pid_t pid;
    
    while((pid = waitpid(-1, NULL, WNOHANG)) > 0)// waitpid(,,WNOHANG) es NO bloqueante. wait() es bloqueante. 
											// Y sumado al while, termina liberando a todos los hijos muertos.
    {
    }
}


int main ()
{
	signal (SIGCHLD, wait_childs_handler); 
	int i=0;
	for (;i<CHILDS;i++){
		int pid = fork ();
		if (pid == -1){
		    printf ("Hubo algun error: (%d) %s\n", errno, strerror (errno));
		}
		if (pid == 0){
			printf ("Soy un hijo, voy a esperar\n");
			sleep(5);
			printf ("Listo %d\n", i);
			exit(0); // El hijo espera 5 segundos y finaliza!
		}
		else{
			//padre
		}
	}
	while(1){
		sleep(3000);// corta ciclo si hubo una interrupción o handler
	}
	printf("Hi\n");
	return(0);
}
//ps -elf | grep main | grep defunct | wc -l  --> Da 10000 xq son 10000 procesos hijos Z. 
//				Y son Z porque el padre está durmiendo y no está en "wait()" para finalizar.


// Hay una cola de hijos, pero no de señales.
