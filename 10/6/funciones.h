//Contiene declaraciones de variables y/o funciones del ejercicio 10.3

#ifndef FUNCIONESH
	#define FUNCIONESH

	#include <stdio.h> 
	#include <stdlib.h>
	#include <math.h>
	#include <time.h>

	//Deaclaración de variables:
		typedef struct punto{
		  double x;
		  double y;
		}strPunto;

		double maxRandValue;

	//Declaración de funciones:
		void ordenarX(strPunto* coords, strPunto* coordsX, int n);
		void imprimirPuntos(strPunto* coords, int n);

#endif