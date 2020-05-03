#include "funciones.h"

int N=100;

void imprimir_valores_medios(FILE* fToRead, double* buffer){
  int i;
  double valorMedio;

  for(i = 0; i < N; i++){
    fscanf(fToRead, "%lf\n", &buffer[i]);
    valorMedio += buffer[i];
  }
  valorMedio = valorMedio/N;
  printf("Valor medio %f\n", valorMedio);
  valorMedio = 0;
}

void imprimir_varianzas(FILE* fToRead, double* buffer){
  int i;
  double valorMedio;
  double varianza;

  for(i = 0; i < N; i++){
    fscanf(fToRead, "%lf\n", &buffer[i]);
    valorMedio += buffer[i];
  }
  valorMedio = valorMedio/N;
  for(i = 0; i < N; i++){
    double diferencia = pow(buffer[i] - valorMedio, 2.0);
    varianza += diferencia;
  }
  varianza = varianza/N;
  varianza = sqrt(varianza);
  printf("Varianza %f\n", varianza);
  varianza = 0;
}