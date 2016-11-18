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
                MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, 1, tag, MPI_COMM_WORLD);
                printf("enviado desde %d el mensaje: %s\n",my_rank,msg);
                MPI_Recv(msg,20,MPI_CHAR,1,tag,MPI_COMM_WORLD,&status);
                printf("recibido en %d el mensaje %s",my_rank ,msg);
        } else if (my_rank == 1) {
                MPI_Recv(msg, 20, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &status);
                printf("recibido en %d el mensaje %s",my_rank ,msg);
                MPI_Send(msg, strlen(msg)+1,MPI_CHAR,0,tag, MPI_COMM_WORLD);
                printf("enviado desde %d el mensaje: %s\n",my_rank,msg);
}
        MPI_Finalize();
}
