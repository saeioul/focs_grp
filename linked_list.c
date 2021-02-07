#include <stdio.h>
#include <stdlib.h>
#include "lib/data_structures/focs/CELL.h"

int valor = 10;
char letra = '!';

int main(){


    /* Using a couple of our available linked list types:
    integer and char LIST.
    **/
    INT_LIST lista_de_enteros = malloc( sizeof(INT_LIST));
    lista_de_enteros->element = valor;
    lista_de_enteros->next = NULL;

    CHAR_LIST lista_de_chars = malloc( sizeof(CHAR_LIST));
    //Why no use just://////////////
    //lista_de_chars->element = '!'; 
    //Hint: an alternative is lista_de_chars->element = (char)'!';
    lista_de_chars->element = letra;
    //////////////////////////////// 
    lista_de_chars->next = NULL;

    printf("Assigned for int: %d \n", lista_de_enteros->element);
    printf("Assigned for char : %c \n", lista_de_chars->element);
    return 0;
}
