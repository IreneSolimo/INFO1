// Ejercicio 10.1| Archivos/Streams
// Programa que abre su propio archivo fuente y lo presenta en pantalla
// OBS.: No utiliza printf para acceder a stdout

#include <stdio.h> 
#include "funciones.h"
   
int main(void) 
{ 
    FILE *fp; 
    fp=fopen(__FILE__,"r"); // La macro __FILE__ tiene la ruta a este archivo
    if (imprimir_archivo_fuente(fp)==0){
    	return 0;
    }else{
    	printf("Error al abrir el archivo.\n");
    }
    return 0;
}