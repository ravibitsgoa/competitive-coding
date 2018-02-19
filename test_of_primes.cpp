#include <stdio.h>
#include <math.h>

int isPrime(int n){
    int i;

    if (n==2)
        return 1;

    if (n%2==0)
        return 0;

    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
            return 0;

    return 1;
}

int main(){
    int i;
    int count = 0;

    for (i=2;i<10000000000;i++){
        if(isPrime(i))
            count++;
    }

    printf("count=%dn",count);

return 0;
}
