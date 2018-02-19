#include<stdio.h>
#include<stdlib.h>
int main()
{   srand(time(NULL));
    printf("%d\n%d\n%d\n",rand()%100,rand()%100,rand()%100);
    return 0;
}
