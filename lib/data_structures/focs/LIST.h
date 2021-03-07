#include "CELL.h"
/*Moving typedef structures to another .h file
as having them mashed in the same file will
cause an error with gcc+: "redefinition of '<LIST_TYPE>'*/

//These sentences define a type called <TYPE>_LIST
//wich contains a pointer to a struct
//defined in turn as <TYPE>_CELL.
typedef struct INT_CELL  *INT_LIST;
typedef struct CHAR_CELL  *CHAR_LIST;
typedef struct FLOAT_CELL  *FLOAT_LIST;
typedef struct DOUBLE_CELL  *DOUBLE_LIST;
