// Ejercicio 10.3| Archivos/Streams
// Programa que abre un archivo de números flotantes. Entrega en pantalla, por cada grupo de 100 valores, su varianza y valor medio.
//OBS.: Utiliza fscanf() y printf()

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
   
int main(int argc, char **argv){ 
	    FILE *fToRead;
	    int i;
	    double buffer[N]; 
    	double valorMedio = 0, varianza = 0;
  		
  		if(argc > 1){
  			putchar('\n');
      		if(fToRead = fopen(argv[1], "r")){
        		do{
        			imprimir_valores_medios(fToRead,buffer);
        		} 
        		while (!feof(fToRead)); // Hasta encontrar el EOF (fin de archivo)
            	fclose(fToRead); // Cierre del archivo
        	}else{ // Si fopen devolvión NULL, la apertura falló
        		printf("Error al abrir el archivo.\n");
      		} 
      		putchar('\n');     		
      		if(fToRead = fopen(argv[1], "r")){
        		do{
        			imprimir_varianzas(fToRead,buffer);
        		} 
        		while (!feof(fToRead)); // Hasta encontrar el EOF (fin de archivo)
            	fclose(fToRead); // Cierre del archivo
        	}else{ // Si fopen devolvión NULL, la apertura falló
        		printf("Error al abrir el archivo.\n");
      		}
      	}	
    	// Nueva línea
    	putchar('\n');
    
    	return 0; 
}