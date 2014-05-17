#include <stdio.h>
#include "chtbl.h"
#include "list.h"
#define            TBLSIZ               11
static int match_char(const void *char1, const void *char2) {
    return (*(const char *)char1 == *(const char *)char2);
}
static int h_char(const void *key) {
    return *(const char *)key % TBLSIZ;
}
static void print_table(const CHTbl *htbl) {
    ListElmt           *element;
    int                i;
    fprintf(stdout, "Table size is %d\n", chtbl_size(htbl));

    for (i = 0; i < TBLSIZ; i++) {

        fprintf(stdout, "Bucket[%03d]=", i);

        for (element = list_head(&htbl->table[i]); element != NULL; element =list_next(element)) {

            fprintf(stdout, "%c", *(char *)list_data(element));

        }

        fprintf(stdout, "\n");

    }

    return;

}
int main(int argc, char **argv) {

    CHTbl              htbl;

    char               *data,
                       c;

    int                retval,
                       i;
    if (chtbl_init(&htbl, TBLSIZ, h_char, match_char, free) != 0)
        return 1;
    for (i = 0; i < TBLSIZ; i++) {

        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;

        *data = ((5 + (i * 6)) % 23) + 'A';

        if (chtbl_insert(&htbl, data) != 0)
            return 1;

        print_table(&htbl);

    }

    for (i = 0; i < TBLSIZ; i++) {

        if ((data = (char *)malloc(sizeof(char))) == NULL)
            return 1;

        *data = ((3 + (i * 4)) % 23) + 'a';

        if (chtbl_insert(&htbl, data) != 0)
            return 1;

        print_table(&htbl);

    }

    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;

    *data = 'd';

    if ((retval = chtbl_insert(&htbl, data)) != 0)
        free(data);//释放上面malloc分配的内存

    fprintf(stdout, "Trying to insert d again...Value=%d (1=OK)\n", retval);

    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;

    *data = 'G';

    if ((retval = chtbl_insert(&htbl, data)) != 0)
        free(data);

    fprintf(stdout, "Trying to insert G again...Value=%d (1=OK)\n", retval);

    fprintf(stdout, "Removing d, G, and S\n");

    c = 'd';
    data = &c;

    if (chtbl_remove(&htbl, (void **)&data) == 0)
        free(data);

    c = 'G';
    data = &c;

    if (chtbl_remove(&htbl, (void **)&data) == 0)
        free(data);

    c = 'S';
    data = &c;

    if (chtbl_remove(&htbl, (void **)&data) == 0)
        free(data);//释放chtbl_remove返回的data,其中存的是哈系表中.

    print_table(&htbl);

    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;

    *data = 'd';

    if ((retval = chtbl_insert(&htbl, data)) != 0)
        free(data);

    fprintf(stdout, "Trying to insert d again...Value=%d (0=OK)\n", retval);

    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;

    *data = 'G';

    if ((retval = chtbl_insert(&htbl, data)) != 0)
        free(data);

    fprintf(stdout, "Trying to insert G again...Value=%d (0=OK)\n", retval);

    print_table(&htbl);

    fprintf(stdout, "Inserting X and Y\n");

    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;

    *data = 'X';

    if (chtbl_insert(&htbl, data) != 0)
        return 1;

    if ((data = (char *)malloc(sizeof(char))) == NULL)
        return 1;

    *data = 'Y';

    if (chtbl_insert(&htbl, data) != 0)
        return 1;

    print_table(&htbl);

    c = 'X';
    data = &c;

    if (chtbl_lookup(&htbl, (void **)&data) == 0)
        fprintf(stdout, "Found an occurrence of X\n");
    else
        fprintf(stdout, "Did not find an occurrence of X\n");

    c = 'Z';
    data = &c;

    if (chtbl_lookup(&htbl, (void **)&data) == 0)
        fprintf(stdout, "Found an occurrence of Z\n");
    else
        fprintf(stdout, "Did not find an occurrence of Z\n");
    fprintf(stdout, "Destroying the hash table\n");
    chtbl_destroy(&htbl);

    return 0;

}
