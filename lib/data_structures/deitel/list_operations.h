
/*Incluímos también la definición de lista ligada*/
#include <stdio.h>
#include <stdlib.h>
#include "../focs/list.h"

/*PROTOTIPOS:
Como no sabemos como pasar cualquier tipo de valor
vamos a hacer una función para cada uno
TODO: Averigüar como hacer una función genérica*/

/*Operaciones de inserción*/
INT_LIST insert_int   (INT_LIST    lista, int valor);
void insert_char  (CHAR_LIST   lista, char valor );
void insert_float (FLOAT_LIST  lista, float valor);
void insert_double(DOUBLE_LIST lista, double valor);

/*Operaciones de eliminación*/
int    delete_int    (INT_LIST    lista, int valor);
char   delete_char   (CHAR_LIST   lista, char valor);
float  delete_float  (FLOAT_LIST  lista, float valor);
double delete_double (DOUBLE_LIST lista, double valor);

/*Operaciones de solo lectura*/
int is_int_list_empty    (INT_LIST    lista);
int is_char_list_empty   (CHAR_LIST   lista);
int is_float_list_empty  (FLOAT_LIST  lista);
int is_double_list_empty (DOUBLE_LIST lista);

void print_int_list      (INT_LIST     lista);
void print_char_list     (CHAR_LIST    lista);
void print_float_list    (FLOAT_LIST   lista);
void print_double_list   (DOUBLE_LIST  lista);

/*Definiciones de métodos: 
Por ahora, todas estas funciones trabajan con paso de variables por copia.
Esto quiere decir que la lista (y todas las variables que se pasan) se copian
localmente al método sin afectar la variable original. Por eso, al final el
método devuelve el nuevo valor para que quien llame actualice el valor original.
*/
INT_LIST insert_int   (INT_LIST lista, int valor){
    
    INT_LIST new_node = NULL;
    INT_LIST itr_node = NULL;
    INT_LIST prv_node = NULL;

    //Nuevo nodo a insertar
    new_node = malloc(sizeof(INT_LIST));

    if(new_node != NULL){

        //Crear nuevo nodo cuyo next sea null para que sea el final de la lista.
        new_node->element = valor;
        new_node->next    = NULL;

        //Lista es un valor local (es un apuntador copiado)
        //
        itr_node = lista;
        while(itr_node != NULL){
            prv_node = itr_node;
            itr_node = itr_node->next;
        }

        //Si el nodo previo es NULL, es por que itr_node fue NULL desde el principio.
        //Significando que la lista estaba vacía, así que insertamos al principio.
        if(prv_node == NULL){
            new_node->next = lista; //Ponemos lista (NULL) como siguiente elemento.
            lista = new_node;       //La lista original (NULL) ahora tiene un puntero
        }else{
            prv_node->next = new_node; //El nodo anterior va a apuntar a nuestro nuevo nodo en vez de NULL
            new_node->next = itr_node; //Nuestro nuevo nodo va ser NULL, por que ahí paramos el while.
        }

        //Debemos regresar lista por que contiene el valor inicial (principio del a lista)
        //En caso de regresar otra cosa, habremos perdido la lista.
        return lista;

    }else{
        printf("Cannot insert %d. Memory allocation for new node returned NULL.\n", valor);
        return NULL;
    }
    
}

int is_int_list_empty    (INT_LIST lista){
    return lista == NULL;
}

void print_int_list      (INT_LIST lista){
    
    if (lista == NULL){
        printf("La lista esta vacia.\n");
    }else{
        printf("La lista es:\n");
        while(lista != NULL){
            printf("%d -> " , lista->element);
            lista = lista->next;
        }
        printf("NULL\n\n");
    }

    
}