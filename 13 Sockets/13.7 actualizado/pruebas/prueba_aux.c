#include <stdio.h>
#include "aux.h"

int main(){
    int childs;
    childs = leerArchivoConfig("./etc/servidor.conf", "childs");
    printf("%i \n",childs);
    return 0;
}
