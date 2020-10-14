#define SIZE_BUF 128

void child_process (int s){
    FILE* fp;
    char buffer[SIZE_BUF];
    read(s, buffer, SIZE_BUF); // (punto a)
    fp=fopen(buffer,"r")
    if(fp==NULL){
        return 
    }
    if (write (sockdup, message , sizeof (message)) == -1){
        perror("Error escribiendo mensaje en socket");
        exit (1);
    }
}
