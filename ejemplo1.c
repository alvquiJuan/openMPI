#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#define  MASTER         0


int main (int argc, char *argv[])
{
  int   numtasks, taskid, len,claimed;
  char hostname[MPI_MAX_PROCESSOR_NAME];

  MPI_Init(&argc, &argv);
  MPI_Query_thread(&claimed);
  //Obtener el número total de tareas e imprimir ese número (línea 24)
  MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
  
  MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
  printf ("Hello from task %d on %s!\n", taskid, hostname);
  if (taskid == MASTER){
    //Identifique el maestro, quien imprimirá la frase “yo soy el maestro”
    printf("yo soy el maestro");
    //Obtener el número total de tareas (línea 15) e imprimir ese número
    //El maestro deberá imprimir el número total de tareas
    printf("MASTER: Number of MPI tasks is: %d\n",numtasks);
    }
  /* Imprimir el nombre del procesador solo si es un proceso par */
  if (taskid % 2 == 0) {
  printf("Processor name: %d\n",MPI_Get_processor_name(hostname, &len));
  }
  printf("Query thread level= %d\n",claimed);
  MPI_Finalize();

}
