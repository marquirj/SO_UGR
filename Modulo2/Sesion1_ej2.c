#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[]){

int fd,fd1;
char cadena[80];
char bloques[20];
int i=0;

    if(argc<2){
        fd=STDIN_FILENO;//Apertura archivoo entrada estandar
    }else{
        if((fd=open(argv[1],O_RDONLY))<0){//Compruebo si se abre el archivo correspondiente devolviendo el error si no se abre
            printf("\nError %d en open",errno);
            exit(-1);
        }
    }
    if((fd1=open("salida4.txt",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR))<0){//Compruebo si se abre el archivo correspondiente devolviendo el error si no se abre
        printf("\nError %d en open",errno);
        exit(-1);
    }
    int controlador=100;
    while((controlador = read(fd,&cadena,80))>0){
        i++;
        sprintf(bloques,"Bloque %i\n",i);//Añadir el comentario bloque con el número de bloque
        write(fd1,&bloques,9);//Añado al fichero creado el comentario anterior

        write(fd1,&cadena,sizeof(cadena));//Añado lo leído en el while. una cadena de 80 bytes del archivo pasado por argumento
    }

    close(fd1);
    close(fd);

    return 0;
}
