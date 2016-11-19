#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv) {
        int my_rank, p, tag = 0;
        char msg[20];
        char msg_mod[20];
        MPI_Status status;

        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &p);
        if (my_rank == 0) {
                strcpy(msg, "Hello ");
                //envío y recepción en un solo comando, si se desea usar comados indepencientes comentar la lína siguente
                MPI_Sendrecv (&msg,1,strlen(msg) + 1, MPI_CHAR, 1,tag,&msg_mod,strlen(msg_mod)+1,MPI_CHAR,1,tag, MPI_COMM_WORLD,&Stat); 
                //Modifique el programa de modo que el maestro envie una cadena y después espere por la cadena modificada 
/* // este bloque envía tareas independientes de envío y recepción 
 //estas instrucciones deben ejecutarse en el orden establecido puesto que ejecutarlas al revés puede causar un deadlock
                MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
                MPI_Recv(msg,20,MPI_CHAR,1,tag,MPI_COMM_WORLD,&status);
                
*/
                //Haga los ajustes correspondientes de modo que sea mas explícito para el usuario final que se han enviado y recibido los datos
                printf("enviado desde %d el mensaje: %s\n",my_rank,msg);
                 //Haga los ajustes correspondientes de modo que sea mas explícito para el usuario final que se han enviado y recibido los datos
                printf("recibido en %d el mensaje %s",my_rank ,msg);
                
        } else if (my_rank == 1) {
                //envío y recepción en un solo comando, si se desea ussr comandos independiente comentar desde aquí hasta la línea 42
                MPI_Sendrecv (&msg_mod,strlen(msg_mod)+1, MPI_CHAR, 0,tag,&msg,strlen(msg)+1,MPI_CHAR,0,tag, MPI_COMM_WORLD,&Stat); 
                int i;
                for (i=0; i<strlen(msg);i++){
                        //cambia mayúsculas por minúsculas
                        if (65<msg[i]&& msg[i]<90){
                        msg_mod[i]= msg[i] + 32;
                        }
                        //cambia minúsculas por mayúsculas
                        if (97<tmp[i]&& msg[i]<122){
                        msg_mod[i]= msg[i] - 32;
                        }
                }
  /* // este bloque envía tareas independientes de envío y recepción 
                MPI_Recv(msg, 20, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
                 //Haga los ajustes correspondientes de modo que sea mas explícito para el usuario final que se han enviado y recibido los datos
                printf("recibido en %d el mensaje %s",my_rank ,msg);
                char tmp[20];
                strcpy(tmp,msg);
                int i;
                for (i=0; i<strlen(tmp);i++){
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
                */
                 //Haga los ajustes correspondientes de modo que sea mas explícito para el usuario final que se han enviado y recibido los datos
                printf("enviado desde %d el mensaje: %s\n",my_rank,msg);
}
        MPI_Finalize();
}
