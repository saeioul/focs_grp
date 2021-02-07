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
typedef struct INT_CELL *INT_LIST;

//The CELL struct is defined here:
struct INT_CELL {
    int element;
    INT_LIST next;
};

//Repeating for other data types we may want in
//linked lists.
//TODO: Find a way to stop repeating ourselves.

typedef struct CHAR_CELL *CHAR_LIST;
struct CHAR_CELL {
    char element;
    CHAR_LIST next;
};

typedef struct FLOAT_CELL *FLOAT_LIST;
struct FLOAT_CELL {
    float element;
    FLOAT_LIST next;
};

typedef struct DOUBLE_CELL *DOUBLE_LIST;
struct DOUBLE_CELL {
    double element;
    DOUBLE_LIST next;
};