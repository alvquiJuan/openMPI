#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv) {
        int my_rank, p, tag = 0;
        char msg[20];
        MPI_Status status;

        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &p);
        if (my_rank == 0) {
                strcpy(msg, "Hello ");
                //Modifique el programa de modo que el maestro envie una cadena y después espere por la cadena modificada 

                MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
                //Haga los ajustes correspondientes de modo que sea mas explícito para el usuario final que se han enviado y recibido los datos
                printf("enviado desde %d el mensaje: %s\n",my_rank,msg);
                MPI_Recv(msg,20,MPI_CHAR,1,tag,MPI_COMM_WORLD,&status);
                 //Haga los ajustes correspondientes de modo que sea mas explícito para el usuario final que se han enviado y recibido los datos
                printf("recibido en %d el mensaje %s",my_rank ,msg);
        } else if (my_rank == 1) {
                MPI_Recv(msg, 20, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
                 //Haga los ajustes correspondientes de modo que sea mas explícito para el usuario final que se han enviado y recibido los datos
                printf("recibido en %d el mensaje %s",my_rank ,msg);
                char tmp[20];
                strcpy(tmp,msg);
                for (int i=0; i<strlen(tmp);i++){
                        //cambia mayúsculas por minúsculas
                        if (65<tmp[i]&& tmp[i]<90){
                        msg[i]= tmp[i] + 32;
                        }
                        //cambia minúsculas por mayúsculas
                        if (97<tmp[i]&& tmp[i]<122){
                        msg[i]= tmp[i] - 32;
                        }
                }
                MPI_Send(msg, strlen(msg)+1,MPI_CHAR,0,tag, MPI_COMM_WORLD);
                 //Haga los ajustes correspondientes de modo que sea mas explícito para el usuario final que se han enviado y recibido los datos
                printf("enviado desde %d el mensaje: %s\n",my_rank,msg);
}
        MPI_Finalize();
}
