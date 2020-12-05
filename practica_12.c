#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct automovil{

            int no_auto;
            char licencia;
            char placa[15];
            char marca[30];
            char modelo[30];
            char color[30];
            int contador_alq;
            int valor_alq_x_dia;
            int valor_alquilado;
            struct cliente Info_automovil;
}

struct cliente{

            int no_cliente;
            int no_auto;
            int no_licencia;
            char nombre_1[25];
            char nombre_2[25];
            char apellido_1[25];
            char apellido_2[25];
            char telefono[15];
            struct automovil Info_cliente;
}

void f_menu(void){

            printf("\n\tMENU\n\n");
            printf("\t\t0) Salir.\n");
            printf("\t\t1) Alquilar Vehiculo ");
            printf("\t\t2) Ver vehiculos disponibles ");
            printf("\t\t3) Captura de datos ");
            printf("\t\t4) Impresion de datos ");
            printf("\t\t5) Devlocion de Vehiculo \n");
}


void f_menu_captura(void){

            printf("\n\tLECTURA\n\n");
            printf("\t\t0) REGRESAR A MENU ANTERIOR.\n");
            printf("\t\t1) Modificar informacion Cliente.\n");
            printf("\t\t2) Captura nuevo Automovil.\n");
            printf("\t\t3) Modificar informacion de Automovil.\n");
}

void f_menu_imp_dat(void){

            printf("\n\tIMPRIMIR DATOS\n\n");
            printf("\t\t0) REGRESAR A MENU ANTERIOR.\n");
            printf("\t\t1) Impirmir informacion de clientes.\n");
            printf("\t\t2) Impirmir informacion de autos.\n");
            printf("\t\t3) Impirmir informacion de autos dispinibles.\n");
}

void f_lectura_auto(automovil A[], *contador_autos, *apuntador_1)){

            A[contador_autos].licencia = *apuntador_1;
            A[*contador_autos].no_auto = *contador_autos + 1;
            printf("\nINGRESE DATOS DEL VEHICULO %d ", *contador_autos + 1);
            printf("\nIngrese Matricula del auto: ");
            fflush(stdin);
            scanf("%s", A[*contador_autos].placa);
            printf("\nIngrese Marca del auto: ");
            fflush(stdin);
            scanf("%s", A[*contador_autos].marca);
            printf("\nIngrese Modelo del auto: ");
            fflush(stdin);
            scanf("%s", A[*contador_autos].modelo);
            printf("\nIngrese Color del auto: ");
            fflush(stdin);
            scanf("%s", A[*contador_autos].color);
            printf("\nIngrese Precio por dia de Alquiler del auto: ");
            fflush(stdin);
            scanf("%d", &A[*contador_autos].precio);
}
void f_lectura_cliente(){

            A[*contador_clientes].no_auto = *apuntador_2;
            A[*contador_clientes].no_cliente = *contador_clientes + 1;
            printf("\nINGRESE DATOS DEL CLIENTE %d ", *contador_clientes + 1);
            printf("\nIngrese No de Licencia: ");
            fflush(stdin);
            scanf("%s", A[*contador_clientes].no_licencia);
            printf("\nIngrese Primer nombre del ciente: ");
            fflush(stdin);
            scanf("%s", A[*contador_clientes].nombre_1);
            printf("\nIngrese Segundo nombre del ciente: ");
            fflush(stdin);
            scanf("%s", A[*contador_clientes].nombre_2);
            printf("\nIngrese Primer apellido del ciente: ");
            fflush(stdin);
            scanf("%s", A[*contador_clientes].apellido_1);
            printf("\nIngrese Segundo apellido del ciente: ");
            fflush(stdin);
            scanf("%s", A[*contador_clientes].apellido_1);
            printf("\nIngrese Numero de Telefono del ciente: ");
            fflush(stdin);
            scanf("%s", A[*contador_clientes].telefono);

}
int main (){
              struct cliente ARRE_1[50];
              struct automovil ARRE_2[50];
              int TAM_autos = 0, TAM_clientes;
              int *apuntador_1, *apuntador_2;
              int contador_autos = 0, contador_clientes = 0, num_auto = 0;
              char opcion = 'E';
              char opcion_lectura, opcion_imp;
              printf("\nEs necesario tener al menor un vehiculo antes de entrar al menu principal.");
              printf("\nSe le solicitara un valor de los vehiculos que despues tendra que capturar.");
              do {
                      fflush(stdin);
                      printf("\nIngrese numero posible maximo de vehiculos que ALQUILARA: ");
                      scanf("%d", &TAM_autos);
              } while ( TAM_autos > 50 || TAM_autos < 1);
contador_clientes = 0;
              do {
                      ++ contador_clientes;
                      ARRE_1[contador_clientes].no_licencia = 0;
                      apuntador_1 = &ARRE_1[contador_autos].no_licencia);
                      fflush(stdin);
                      f_lectura_auto(ARRE_2, &contador_autos, &apuntador_1);
                      ++ contador_autos;
              } while (contador_autos < TAM_autos);

              do {
                      fflush(stdin);
                      f_menu();
                      fflush(stdin);
                      printf("\nIngrese opcion del menu: ");
                      scanf("%c", &opcion);
                      switch (opcion){

                              case '0': printf("\nEligio la opcion SALIR\n");
                                        break;
                              case '1': do {
                                              printf("\nIngrese numero de Vehiculo que desea alquilar: " );
                                              scanf("%d", &num_auto);
                                              if (num_auto > 0 || num_auto <= TAM_autos){
                                                          ARRE_1[contador_clientes].no_auto = num_auto;
                                                          if (ARRE_2[num_auto - 1].licencia == 0){
                                                                    apuntador_2 = &ARRE_2[num_auto - 1].no_auto;
                                                                    f_lectura_cliente(ARRE_1, &contador_clientes, &apuntador_2);
                                                                    apuntador_1 = &ARRE_1[contador_clientes].no_licencia;
                                                                    ARRE_2[num_auto - 1].licencia = *apuntador_1;
                                                          }
                                              }
                                        }
                                        f_lectura_cliente();

                      }


              }



return 0];
}
