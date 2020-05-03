#include "funciones.h"

int imprimir_archivo_fuente(FILE* fp){
    char a, b;  
    // Si fopen devulve algo distinto de NULL, la apertura fue exitosa
    //"r": Abre un archivo para leer, el archivo debe existir
   	if(fp!=NULL){
      fread(&a, sizeof(char), 1, fp); // Trae un caracter del archivo
      fread(&b, sizeof(char), 1, fp);
   		// Se usan a y b para imprimir de forma correcta el último caracter
   		do
	    { 
	    	fwrite(&a, sizeof(char), 1, stdout); // Lo imprime
	    	a=b;
	    	fread(&b, sizeof(char), 1, fp);
	    }
	    while (!feof(fp)); // Hasta encontrar "fin de archivo"
	    fwrite(&a, sizeof(char), 1, stdout);
	    fclose(fp); // Cierra del archivo	   	
   	}else{ // Si fopen devolve NULL, la apertura falló
   		return 1;
   	}    
  return 0; 
}