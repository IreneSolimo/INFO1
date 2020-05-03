#include "funciones.h"

double maxRandValue = 100.0;
    
void ordenarX(strPunto* coords, strPunto* coordsX, int n){
  int i;
  int j;
  double tempx;
  double tempy;

  coordsX = (strPunto*) malloc(n*sizeof(strPunto));
  // Se ordena por el método burbujeo
  for(i = 0; i < n; i++){
    coordsX[i].x=coords[i].x;
    coordsX[i].y=coords[i].y;
  }  
  for (i = 0; i < (n - 1); i++){ 
    for (j = i + 1; j < n; j++){ 
      if (coordsX[j].x < coordsX[i].x){ 
        tempx = coordsX[j].x;
        tempy = coordsX[j].y; 

        coordsX[j].x = coordsX[i].x; 
        coordsX[j].y = coordsX[i].y; 
        
        coordsX[i].x = tempx; 
        coordsX[i].y = tempy;
      } 
    } 
  }
  printf ("Los puntos ordenados por la coordenada X son:\n"); 
  imprimirPuntos(coordsX, n);
  free(coordsX);
}

void imprimirPuntos(strPunto* coords, int n){
  int i;
  for (i=0; i<n ; i++){
    printf("[X;Y]: (%lf; %lf)\n", coords[i].x,coords[i].y);
  }
}

