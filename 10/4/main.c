// Ejercicio 10.4| Archivos/Streams
// Programa que recibe un archivo como argumento por línea de comando y lo imprime en pantalla. 
// OBS.: No utiliza printf para acceder a stdout.
// OBS.: Utiliza fread y fwrite.

#include <stdio.h> 
#include "funciones.h"
   
int main(int argc, char **argv){ 
    FILE *fp; 
    // Si hay más de un argumento en la ejecución del programa
    if(argc > 1){
      	// Utilizar el segundo argumento
      	// OBS.: El primer argumento argv[0] es el nombre del ejecutable "./executable"
      	fp = fopen(argv[1], "rb");
    	if (imprimir_archivo_fuente(fp)==0){
    		return 0;
    	}else{
    		puts("Error al abrir el archivo.");
    	}
    }
    return 0;
}
