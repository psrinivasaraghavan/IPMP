#include<bits/stdc++.h>
# define NO_OF_CHARS 256
using namespace std;


void fillCharCounts(char *str, int *count)
{
    int i;
    for (i = 0; *(str + i); i++)
    count[*(str + i)]++;
}


void printDups(char *str)
{
    int *count = (int *)calloc(NO_OF_CHARS, sizeof(int));
    fillCharCounts(str, count);
    int i;
    for (i = 0; i < NO_OF_CHARS; i++)
    if(count[i] > 1) printf("%c, count = %d \n", i, count[i]);
    free(count);
}
 

int main()
{
    char str[] = "Hello World";
    printDups(str);
    return 0;
}