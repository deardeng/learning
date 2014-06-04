#include <stdio.h>
int main()
{
    char str[100] = "hello,-567world 123this is my first 888";
    int n;
    int i;
    int j;
    int k;

    i = 0;
    while(str[i])
    {
        if('0'<=str[i] && str[i]<='9')
        {
            j = i;
            while('0'<=str[j] && str[j]<='9')
            {
                j++;
            }
            k = j;

            n = 0;
            j = i;
            while(j<k)
            {
                n = n*10 + str[j] - '0';
                j++;
            }
            printf("%d\n",n);
            i = k;
            continue;//此处continue是为了检查最后一个数字之后的字母，否则最后一个数字后的字母，不会给11行的while检查。
            //如7后面的w，可以给11行，13行检查。
        }
        i++;
    }
    return 0;
}
