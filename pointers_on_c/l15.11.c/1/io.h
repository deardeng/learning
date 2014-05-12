#ifndef IO_H
#define IO_H
#include"part.h"
#include"process.h"
int open_file( char const *filename );
void close_file(void);
Part_number last_part_number( void );
Part_number next_part_number( void );
int read_part( Part_number part_number, Part *part );
void write_part( Part_number part_number, Part const *part );
#endif
