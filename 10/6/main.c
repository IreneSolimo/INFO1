// Ejercicio 10.6| Archivos/Streams
// 1° Programa que genera un array de estructuras punto. (La cantidad de elementos del array, se recibe como argumento por línea de comandos).
// 2° Los almacena en un archivo ./puntos.dp.
// 3° Presenta un menú con dos opciones:
//        • Presentar cada par de valores generados en el archivo
//        • Ordenar los valores mediante la coordenada X de cada punto.

#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "funciones.h"

int main(int argc, char **argv){ 
  FILE *fToRead,*fToWrite;
  strPunto* coords;
  strPunto* coordsX;
  int n=0;
  int i;
  int menu_index;
  
// 1° Se generan los puntos
  srand((unsigned int)time(NULL));
  if(argc > 1){
    n = atoi(argv[1]); // argv[1] es un string -> a entero con atoi()
    coords = (strPunto*) malloc(n*sizeof(strPunto)); // se pide memoria para coords ya sabiendo la cantidad de elementos
    for(i = 0; i < n; i++){
      coords[i].x = (double)rand()/(double)(RAND_MAX/maxRandValue);
      coords[i].y = (double)rand()/(double)(RAND_MAX/maxRandValue); 
    }
// 2° Se genera el archivo .dp
    if(fToWrite = fopen("puntos.dp", "w")){
      for(int i = 0; i < n; i++){
        fprintf(fToWrite, "(%lf,%lf)\n", coords[i].x,coords[i].y);
      } 
    } 
    fclose(fToWrite);
// 3° Presenta el menú
    puts("1 -Presentar cada par de valores generados en el archivo.");
    puts("2 -Ordenar los valores mediante la coordenada X de cada punto.");
    scanf("%d", &menu_index);
    if (menu_index==1){
      imprimirPuntos(coords,n);        
    }
    if (menu_index==2){
      ordenarX(coords, coordsX, n);
    }
    free(coords);
    putchar('\n');
  }
  return 0; 
}