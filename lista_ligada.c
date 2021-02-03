#include <stdio.h>
#include <stdlib.h>
#include "lib/data_structures/deitel/nodoLista.h"


ptrNodoLista lista_ligada = NULL;
int valor = 10;

int main(){
    //Will it work with (sizeof(ptrNodolista)) ??
    ptrNodoLista nuevo_nodo = malloc( sizeof(NodoLista));
    nuevo_nodo->dato = valor;
    nuevo_nodo->ptrNodoLista = NULL;
    printf("Assigned: %d \n", nuevo_nodo->dato);
    return 0;
}