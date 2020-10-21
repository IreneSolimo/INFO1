// 2. Crear el archivo seniales.c en el que se tengan las funciones manejadoras (handlers) de las difer-
// entes señales que se reemplacen para el sistema en desarrollo, así como una función que reemplace los
// manejadores de las mismas por dichas funciones, cuyo prototipo se escribe a continuación:
// int sig_trap (void);
// La función devuelve 0 si todas las señales se reemplazaron exitosamente, y devuelve SIG_ERR en
// caso que al menos una no se haya podido reemplazar.

#include "aux.h"

int sig_trap (void){
  if((signal (SIGHUP, sig_handler_new_config)== SIG_ERR) || (signal (SIGCHLD, wait_childs_handler)== SIG_ERR)){
    return (SIG_ERR);
  }else return 0;
}

void sig_handler_new_config (int sig){
	flag_max_childs =1;
}

void wait_childs_handler (int sig){

    pid_t pid;
    
    while((pid = waitpid(-1, NULL, WNOHANG)) > 0)// waitpid(,,WNOHANG) es NO bloqueante. wait() es bloqueante. 
											// Y sumado al while, termina liberando a todos los hijos muertos.
    {
		childs --;
    }
}