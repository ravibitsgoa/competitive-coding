#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main()
{   
    int a=0;
    if (fork() == 0)
    { 
        printf("parent: %d\n",a);
        a = a + 5; 
        printf("%d, %p\n", a, &a); 
    }
    else
    {   
        printf("child: %d\n",a);
        a = a - 5; 
        printf("%d, %p\n", a, &a); 
    }
    /*fork();
    fork() && fork() || fork();
    fork();
   
    printf("forked\n");*/
    //join();
    printf("%d\n",a);
}
