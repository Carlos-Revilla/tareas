#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int f_suma (int num_1, int num_2){
          return num_1 + num_2;
}

int f_dif (int num_1, int num_2){
          return num_1 - num_2;
}

int f_prod (int num_1, int num_2){
          return num_1 * num_2;
}

int f_div (int num_1, int num_2){
          return num_1 / num_2;
}

int f_result(int num_1, int num_2){
          if (num_1 == num_2){
                printf("\n\n%cMuy Bien!\n\n", 173);
          } else{
                printf("\n\nNo, Por favor intente de nuevo.");
          }
}

void menu (void){
          fflush(stdin);
          printf("\n\tMENU DE OPCIONES\n\n");
          printf("\t\t1) Generar suma\n");
          printf("\t\t2) Generar resta\n");
          printf("\t\t3) Generar multiplicacion\n");
          printf("\t\t4) Generar division\n");
          printf("\t\t0) SALIR\n");
}

int main(){

          int variable_1 = 0, variable_2 = 0, result = 0;
          int respuesta = 0;
          char opcion = '>';
srand(time(NULL));
          do {
                  menu ();
                  fflush(stdin);
                  printf("\nIngrese opcion del menu anterior: ");
                  scanf("%c", &opcion);
                  switch(opcion){
                          case '0': break;
                          case '1': variable_1 = 1 + rand()% 100;
                                    variable_2 = 1 + rand()% 100;
                                    result = f_suma (variable_1, variable_2);
                                    do {
                                          printf("\n%cCuanto es: %d + %d = ?", 168, variable_1, variable_2);
                                          printf("\nIngrese su respuesta: ");
                                          scanf("%d", &respuesta);
                                          f_result(respuesta, result);
                                    } while (respuesta != result);
                                    break;
                          case '2': variable_1 = 1 + rand()% 100;
                                    variable_2 = 1 + rand()% 100;
                                    result = f_dif (variable_1, variable_2);
                                    do {
                                          printf("\n%cCuanto es: %d - %d = ?", 168, variable_1, variable_2);
                                          printf("\nIngrese su respuesta: ");
                                          scanf("%d", &respuesta);
                                          f_result(respuesta, result);
                                    } while (respuesta != result);
                                    break;
                          case '3': variable_1 = 1 + rand()% 100;
                                    variable_2 = 1 + rand()% 100;
                                    result = f_prod (variable_1, variable_2);
                                    do {
                                          printf("\n%cCuanto es: %d * %d = ?", 168, variable_1, variable_2);
                                          printf("\nIngrese su respuesta: ");
                                          scanf("%d", &respuesta);
                                          f_result(respuesta, result);
                                    } while (respuesta != result);
                                    break;
                          case '4': variable_1 = 1 + rand()% 100;
                                    variable_2 = 1 + rand()% 100;
                                    result = f_div (variable_1, variable_2);
                                    do {
                                          printf("\n%cCuanto es: %d / %d = ?", 168, variable_1, variable_2);
                                          printf("\nIngrese su respuesta: ");
                                          scanf("%d", &respuesta);
                                          f_result(respuesta, result);
                                    } while (respuesta != result);
                                    break;
                  }
                  fflush(stdin);
          } while (opcion != '0');


  return 0;
}
