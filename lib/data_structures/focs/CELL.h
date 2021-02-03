/** Header file fore basic CELL in a linked list.
 * 
 * Note that the whole list can be represented 
 * by the pointer to the first element to the list,
 * thus making a single cell also a linked list.
 * 
 * This is an alternative impletentation to
 * lib/data_structures/deitel/nodoLista.h 
 * 
*/

//This sentences defines a type called LIST
//wich contains a pointer to a struct
//defined in turn as CELL.
typedef struct CELL *LIST;

//The CELL struct is defined here:
struct CELL {
    int element;
    LIST next;
};
