/*10000 instancias child(van en paralelo)
Cada una debe dormir durante 5 segundos y finalizar
Mientras tanto el proceso padre deberá dormir 30 segundos o mas y terminar
Ejecutar en consola: ps -elf | grep [nombre del programa ejecutable] | grep defunct | wc -l*/

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

int main ()
{
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
	sleep(30);
	return(0);
}
//ps -elf | grep main | grep defunct | wc -l  --> Da 10000 xq son 10000 procesos hijos Z. 
//				Y son Z porque el padre está durmiendo y no está en "wait()" para finalizar.