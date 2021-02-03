#include <stdio.h>
#include <stdlib.h>
#include "lib/data_structures/focs/CELL.h"

LIST lista_ligada = NULL;
int valor = 10;

int main(){

    //Will it work (sizeof(CELL)) ???
    LIST nuevo_nodo = malloc( sizeof(LIST));
    nuevo_nodo->element = valor;
    nuevo_nodo->next = NULL;
    printf("Assigned: %d \n", nuevo_nodo->element);
    return 0;
}
