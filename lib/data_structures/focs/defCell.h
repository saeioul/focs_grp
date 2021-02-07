//DefCell is defined in the macro section so it will easily
//expand to the required value.

#define DefCell(EltType, CellType, ListType) \
typedef struct CellType *ListType; \
struct CellType { \
EltType element; \
ListType next; \
}