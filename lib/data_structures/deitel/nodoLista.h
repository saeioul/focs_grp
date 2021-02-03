/** Header file fore basic nodoLista in a linked list.
 * 
 * Note that the whole list can be represented 
 * by the pointer to the first element to the list,
 * thus making a single cell also a linked list.
 * 
 * This is an alternative impletentation to
 * lib/data_structures/focs/CELL.h 
 * 
*/

struct nodoLista
{
    char dato;
    struct nodoLista *ptrNodoLista;
};

//New type: NodoLista is a "struct nodoLista"
typedef struct nodoLista NodoLista;
//Yet another new tipe: NodoLista is a pointer to NodoLista
typedef NodoLista *ptrNodoLista;