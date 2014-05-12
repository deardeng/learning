#ifndef PART_H
#define PART_H
#define MAX_DESCRIPTION 20
#define DESCRIPTION_FIELD_LEN ( MAX_DESCRIPTION + 1 )
typedef unsigned long Part_number;
typedef unsigned short Quantity; 
typedef double Value;
typedef struct {
	char description[ DESCRIPTION_FIELD_LEN ];
	Quantity quantity;
	Value total_value;
} Part;
#define TRUE 1
#define FALSE 0
#endif
