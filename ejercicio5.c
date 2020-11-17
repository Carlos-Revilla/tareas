#include<stdio.h>

int main()
{ int dimension = 5;
  int matriz_uno [dimension][dimension], matriz_dos [dimension][dimension];
  int matriz_resultante [dimension][dimension];
  int indice_i, indice_j;

  for (indice_j = 0; indice_j < dimension; indice_j ++)
     {
       for(indice_i = 0; indice_i < dimension; indice_i ++)
          {
            matriz_uno [indice_j][indice_i] = indice_i + indice_j;
            matriz_dos [indice_j][indice_i] = indice_i + indice_j + 100;
            matriz_resultante [indice_j][indice_i] =
            matriz_uno [indice_j][indice_i] + matriz_dos [indice_j][indice_i];

          }
     }
  printf("La Primera matriz es: \n" );
  for (indice_j = 0;indice_j < dimension; indice_j ++)
     {
       for (indice_i = 0; indice_i < dimension; indice_i ++)
          {
            printf("%d, ", matriz_uno[indice_j][indice_i]);
          }
       printf("\n");
     }
     printf("La Segunda matriz es: \n" );
     for (indice_j = 0;indice_j < dimension; indice_j ++)
        {
          for (indice_i = 0; indice_i < dimension; indice_i ++)
             {
               printf("%d, ", matriz_dos[indice_j][indice_i]);
             }
          printf("\n");
        }
        printf("La matriz resultante es: \n" );
        for (indice_j = 0;indice_j < dimension; indice_j ++)
           {
             for (indice_i = 0; indice_i < dimension; indice_i ++)
                {
                  printf("%d, ", matriz_resultante[indice_j][indice_i]);
                }
             printf("\n");
           }
           return 0;                
}
