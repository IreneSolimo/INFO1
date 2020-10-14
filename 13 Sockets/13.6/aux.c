#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 100
int leerArchivoConfig(char* ArchivoConfig, char* parametro){
    FILE* fp;
    char* aux;
    fp = fopen(ArchivoConfig,"r");
    char cadena[MAXSIZE];
    if(fp==NULL){
        perror("Error en archivo de configuración");
        return(-1);
    }
    while(fgets(cadena,MAXSIZE,fp)!=NULL){
        if(strstr(cadena,parametro)==cadena){
            aux = cadena + strlen(parametro)+1;
            fclose(fp);
            return atoi(aux);
        }
    }
    fclose(fp);
    return (-2);
}
