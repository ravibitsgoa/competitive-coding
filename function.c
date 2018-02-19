#include<stdio.h>
int main()
{   long long int n, f;
    scanf("%lld",&n);
    if(n%2==0){f=n/2;}
    else{f=-1-(long long int)(n/2);}
    printf("%lld\n",f);

return 0;
}

