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
//The CELL struct is defined here:
//Repeating for other data types we may want in
//linked lists.
//TODO: Find a way to stop repeating ourselves.
#ifndef INT_CELL_DEFINED
struct INT_CELL {
    int element;
    struct INT_CELL *next;
};
struct CHAR_CELL {
    char element;
    struct CHAR_CELL *next;
};

struct FLOAT_CELL {
    float element;
    struct FLOAT_CELL *next;
};

struct DOUBLE_CELL {
    double element;
    struct DOUBLE_CELL *next;
};
#define INT_CELL_DEFINED
#endif