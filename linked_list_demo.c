#include <stdio.h>
#include <stdlib.h>
#include "lib/data_structures/focs/LIST.h"
#include "lib/data_structures/deitel/list_operations.h"

int main(){

    printf("BIENVENIDO AL DEMO DE LISTAS LIGADAS! \n");

    //Creamos nuestra lista
    INT_LIST lista_de_enteros = NULL;

    int val1 = 1;
    int val2 = 10;
    int val3 = 2;

    lista_de_enteros = insert_int( lista_de_enteros , val1);
    lista_de_enteros = insert_int( lista_de_enteros , val2);
    lista_de_enteros = insert_int( lista_de_enteros , val3);
    print_int_list(lista_de_enteros);

}