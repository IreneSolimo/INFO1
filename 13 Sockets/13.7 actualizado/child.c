#define SIZE_BUF 128
#define MSG_OK "OK"

void child_process (int s){
    FILE* fp;
    char buffer[SIZE_BUF];
    char buffer_msg_error[SIZE_BUF]="ERROR!: ";
    char buffer_file[SIZE_BUF];
    char buffer_read_file[SIZE_BUF];
    int aux;

    read(s, buffer, SIZE_BUF); // punto a) es bloqueante!
    fp=fopen(buffer,"rb"); // punto b)
    if(fp==NULL){ //   punto c)
        strcat(buffer_msg_error, strerror(errno));
        write(s, buffer_msg_error , strlen(buffer_msg_error)+1);
        close(s);  
        exit (-1);
    }

    // punto d) transmite el archivo y manda OK
    aux = write(s, MSG_OK, strlen(MSG_OK)+1);
    if (aux == -1){
        close(s);
        fclose(fp);  
        exit(-2);
    } 
    while (feof (fp) == 0)
    {
        aux = fread (buffer_read_file, 1, SIZE_BUF, fp);
        if (aux > 0){
            aux = write(s, buffer_read_file, aux);
            if (aux == -1){
                close(s);
                fclose(fp);
                exit(-2);
            }                        
        }else if (aux==0 && feof(fp)==0){
            close(s);
            fclose(fp);
            exit(-2);
        }
    }
    close(s);
    fclose(fp);    
    exit(0);
}
