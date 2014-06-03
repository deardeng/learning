#include<stdio.h>
void showDiamond( int level )
{
    int i;
    char ch = '*';

    printf("%*c\n", level, ch);
    for( i = 1; i < level ; ++i )
    {
        printf("%*c%*c\n", level - i, ch , 2 * i, ch);
    }

    for( i += 2; i < 2 * level; ++i )
    {
        printf("%*c%*c\n", i - level, ch, 4 * level - 2 * i, ch);
    }
    printf("%*c\n", level, ch);
}

int main(){
    showDiamond(3);
}
