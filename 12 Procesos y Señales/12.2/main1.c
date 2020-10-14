/*Tomar el código desarrollado en el Ejercicio 12.1 y agregarle un handler a la señal SIGCHLD dentro del
cual se invoque la función wait (), pasándole un puntero a NULL de modo de ignorar la información
de estado del proceso. Repetir la comprobación del estado de los zombies, por medio del comando ps
-elf | grep [nombre del programa ejecutable] | grep defunct | wc -l en otra
terminal. ¿Solucionó el problema observado en el Ejercicio anterior?. ¿Puede evaluar a partir del resultado el
comportamiento de las señales cuando se dirigen en forma masiva y cuasi simultánea a un mismo proceso?.
Escribir un pequeño reporte en un archivo de texto plano a modo de reseña.*/

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
	wait(NULL);
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


//¿Solucionó el problema observado en el Ejercicio anterior?.
//	Hubo una mejora pero no una solución total. La cantidad de hijos Z no es cero. Probándolo varias veces quedan aprox. un 40% de hijos Z.
//¿Puede evaluar a partir del resultado el comportamiento de las señales cuando se dirigen en forma masiva y cuasi simultánea a un mismo proceso?
//	El handler recepciona algunas de todas las señales que le llegan de forma simultánea y masiva. No quedan en una cola.
//	Si no ponemos un printf() en el handler la situación mejora. Es por el tiempo que demora el handler en ejecutar el printf(). 
// 	Un handler más corto permite una respuesta a señales más veloz.
