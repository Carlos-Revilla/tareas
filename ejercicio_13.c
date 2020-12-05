#include <stdio.h>
#include <stdio.h>
#include <string.h>


typedef struct{
    char Matricula[15];
    int PrimerParcial;
    int SegundoParcial;
    int PIA;
    float Final;
}Evaluacion;

void funcion_captura(Evaluacion *, int *);
/*void funcion_impresion_en_archivo(FILE *, Evaluacion *, int *);*/

int main(){


   FILE *fp;
   int contador_1, i, num_max_struct = 0;

   printf("Ingrese numero de estudiantes que desea capturar: ");
   scanf("%d", &num_max_struct);
   fp = fopen("C://Users//USER//Desktop//archivos//EvaluacionesConFunciones.csv", "w+");
   Evaluacion Evaluaciones[50];

   for (contador_1 = 0; contador_1 < num_max_struct; contador_1 ++){
          funcion_captura (Evaluaciones, &contador_1);
          /*funcion_impresion_en_archivo(*fp_puedesSerDiferente, Evaluaciones, &contador_1);*/
   }

   fprintf(fp, "Matricula, PrimerParcial, SegundoParcial, PIA, Final\n");
   for(i = 0; i < num_max_struct; i++){
       Evaluaciones[i].Final = (float) (Evaluaciones[i].PrimerParcial + Evaluaciones[i].SegundoParcial + Evaluaciones[i].PIA) / 3;
       fflush(stdin);
       fprintf(fp, "%s, %d, %d, %d, %.2f\n", Evaluaciones[i].Matricula, Evaluaciones[i].PrimerParcial, Evaluaciones[i].SegundoParcial, Evaluaciones[i].PIA, Evaluaciones[i].Final);
   }

   fclose(fp);
   printf("Archivo guardado");
 return 0;}

 void funcion_captura(Evaluacion A[], int *contador_1){

         printf("\n\tALUMNO %d\n", *contador_1 + 1);
         printf("\nIngrese numero de matricula: ");
         fflush(stdin);
         scanf("%s", A[*contador_1].Matricula);
         printf("\nIngrese Calificacion del primer parcial: ");
         fflush(stdin);
         scanf("%d", &A[*contador_1].PrimerParcial);
         printf("\nIngrese Calificacion del segundo parcial: ");
         fflush(stdin);
         scanf("%d", &A[*contador_1].SegundoParcial);
         printf("\nIngrese Calificacion del PIA: ");
         fflush(stdin);
         scanf("%d", &A[*contador_1].PIA);

 }

/* void funcion_impresion_en_archivo(FILE *fp, Evaluacion A[], int *contador_1){

         if(*contador_1 == 0){
                 fprintf(fp, "Matricula, PrimerParcial, SegundoParcial, PIA, Final\n");
                 fprintf(fp, "%s, %d, %d, %d, %.2f\n", A[*contador_1].Matricula, A[*contador_1].PrimerParcial, A[*contador_1].SegundoParcial, A[*contador_1].PIA, A[*contador_1].Final);
         }else{
                 fprintf(fp, "%s, %d, %d, %d, %.2f\n", A[*contador_1].Matricula, A[*contador_1].PrimerParcial, A[*contador_1].SegundoParcial, A[*contador_1].PIA, A[*contador_1].Final);
         }
 }*/
