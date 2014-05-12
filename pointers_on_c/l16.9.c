#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

#define TRIALS 10000

int main(int ac,char **av){
    int n_students=30;
    int *birthdays;
    int test;
    int match;
    int total_matches=0;

    if(ac>1){
        n_students=atoi(av[1]);
        assert(n_students>0);
    }

    srand((unsigned int)time(0));

    birthdays=(int *)malloc(n_students*sizeof(int));
    assert(birthdays!=NULL);

    for(test=0;test<TRIALS;test+=1){
        int i;
        match=FALSE;
        for(i=0;i<n_students&&!match;i++){
            int j;
            birthdays[i]=rand()%356;
            for(j=0;!match&&j<i;j+=1)
                if(birthdays[i]==birthdays[j])
                    match=TRUE;
        }
        if(match)
            total_matches+=1;
    }


    printf("The odds of any two people in a group of %d\n"
            "having the same birthdays are %g\n",n_students,
            (double)total_matches/TRIALS);
    free(birthdays);
}
