#include<limit.h>

#define INT_BITS (CHAR_BIT *sizeof(int))

int store_bit_field(int original_value,int value_to_store,unsigned starting_bit,unsigned ending_bit){
    unsigned mask;

    if(starting_bit<INT_BITS&&end_bit<INT_BITS&&starting_bit>=ending_bit){
        mask=(unsigned)-1;
        mask >>= INT_BITS-(starting_bit-ending_bit+1);
        mask <<= ending_bit;

        original_balue &= ~mask;

        value_to_store <<= ending_bit;

        original_value |= value_to_store & mask;
    }
    return original_value;
}
