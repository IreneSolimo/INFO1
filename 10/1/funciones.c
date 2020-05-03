#include "funciones.h"

int imprimir_archivo_fuente(FILE* fp){
    char a, b;  
    // Si fopen devulve algo distinto de NULL, la apertura fue exitosa
    //"r": Abre un archivo para leer, el archivo debe existir
   	if(fp!=NULL){
   		a = fgetc(fp);// Trae un caracter del archivo
   		b = fgetc(fp);
   		// Se usan a y b para imprimir de forma correcta el último caracter
   		do
	    { 
	    	putchar(a); // Lo imprime
	    	a=b;
	    	b=fgetc(fp);
	    }
	    while (b != EOF); // Hasta encontrar "fin de archivo"
	    putchar(a);
	    fclose(fp); // Cierra del archivo	   	
   	}else{ // Si fopen devolve NULL, la apertura falló
   		return 1;
   	}    
    putchar('\n'); // Nueva línea
    return 0; 
}