#include "sock-lib.h"
#include "aux.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void sig_handler_new_config (int sig);
void wait_childs_handler (int sig);
void child_process (int s);
int sig_trap (void);