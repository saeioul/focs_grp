#include <stdio.h>
#include <stdlib.h>

/*Definiendo la estructura de datos*/
//Nodo:
struct nodoLista {
    int dato;
    struct nodoLista *ptrSiguiente;
};
//Sinónimo (para no tener que escribir struct nodoLista en todos lados)
typedef struct nodoLista NodoLista;
//Este es el tipo que vamos a usar durante todo el demo: Estamos interesados en el apuntador solamente
typedef NodoLista *ptrNodoLista;

/*Prototipos*/
void instrucciones(void);
void insertar(ptrNodoLista *ptrList, int valor);
int  eliminar_last(ptrNodoLista *ptrList);
int  is_empty(ptrNodoLista ptrList);
void printlist(ptrNodoLista ptrList);

int main(){

    //Variables para la elección del usuario y el elemento a crear.
    int eleccion;
    int elemento;
    ptrNodoLista lista_de_enteros = NULL;

    instrucciones();

    scanf("%d", &eleccion);

    while( eleccion != 4){

        switch( eleccion ){
            case 1:
                printf("Ahora introduzca un número a guardar: ");
                scanf("%d",&elemento);
                insertar(&lista_de_enteros, elemento);
                break;
            
            case 2:
                printf("Eliminando último elemento ... \n");
                int data = eliminar_last(&lista_de_enteros);
                printf("Elemento elminado: %d\n",data);
                break;

            case 3:
                printlist(lista_de_enteros);
                break;

            default:
                printf("Opción no reconocida.\n");
                instrucciones();
                break;
        }

        printf("Elección: ");
        scanf("%d", &eleccion);

    }

}

void instrucciones(void){
    printf("BIENVENIDO AL DEMO DE LISTAS LIGADAS! \n");
    printf("Introduzca su eleccion:\n"
    " 1 -> insertar un elemento en la lista.\n"
    " 2 -> elimina el último elemento de la lista.\n"
    " 3 -> imprime la lista.\n"
    " 4 -> finalizar.\n");
}

void insertar(ptrNodoLista *ptrList, int valor){
    ptrNodoLista ptrNuevo;
    ptrNodoLista ptrAnterior;
    ptrNodoLista ptrActual;
    
    ptrNuevo = malloc ( sizeof( NodoLista ));

    if (ptrNuevo != NULL){
        ptrNuevo->dato = valor;
        ptrNuevo->ptrSiguiente = NULL;

        ptrAnterior = NULL;
        ptrActual = *ptrList;

        while(ptrActual != NULL){
            ptrAnterior = ptrActual;
            ptrActual   = ptrActual->ptrSiguiente;
        }

        //Si estábamos en una lista vacía,
        //Convierte al nodo nuevo en el primer elemento,
        //y el siguiente elemento , de por si es null
        if ( ptrAnterior == NULL){
            ptrNuevo->ptrSiguiente = *ptrList;
            *ptrList = ptrNuevo;
        }else{
            ptrAnterior->ptrSiguiente = ptrNuevo;
            ptrNuevo->ptrSiguiente = ptrActual;
        }

    }else{
        printf("No se puede crear nuevo elemento.\n");
    }

}

int  is_empty(ptrNodoLista ptrList){
    return ptrList == NULL;
}

void printlist(ptrNodoLista ptrList){

    if(is_empty(ptrList)){
        printf("La lista está vacía :)\n");
    }else{
        printf("La lista es:\n");
        while(ptrList != NULL){
            printf("%d -> " , ptrList->dato);
            ptrList = ptrList->ptrSiguiente;
        }
        printf("NULL\n\n");
    }   

    printf("\n");
}

int  eliminar_last(ptrNodoLista *ptrList){

    ptrNodoLista ptrActual   = NULL;
    ptrNodoLista ptrAnterior = NULL;
    ptrNodoLista ptrToKill   = NULL;
    ptrNodoLista ptrAnteAnte = NULL;

    int dataToRetrieve       = -1;

    ptrActual = *ptrList;
    if(ptrActual == NULL){
        printf("ERROR: La lista está vacía.\n");
        return dataToRetrieve;
    }

    //Hay que parar un paso antes del final de la lista.
    
    while(ptrActual!= NULL){

        if(ptrActual != *ptrList){
            ptrAnteAnte = ptrAnterior;
        }

        ptrAnterior    = ptrActual;
        ptrActual      = ptrActual->ptrSiguiente;
    }

    dataToRetrieve = ptrAnterior->dato;


    //printf("Nuevo nodo Final:\n");
    if(ptrAnteAnte == NULL){
        //printf("DEBUG: Elemento de una sola lista.\n");
        //printf("Elemento a borrar: ");
        //printf("%d\n",dataToRetrieve);
        ptrToKill = *ptrList;
        *ptrList = NULL;
    }else{
        ptrToKill = ptrAnterior;
        //printf("DEBUG: Elemento de mas de una lista\n");
        //printf("Elemento a borrar: %d\n",dataToRetrieve);
        //printf("Nuevo elemeno final será %d\n",ptrAnteAnte->dato);
        ptrAnteAnte->ptrSiguiente = NULL;
    }

    free(ptrToKill);
    return dataToRetrieve;
}
