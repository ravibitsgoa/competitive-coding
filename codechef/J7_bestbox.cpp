#include<stdio.h>
#include<math.h>
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int p, s;
        scanf("%d %d",&p,&s);
        float a, b, c;
        a=p/2;
        a-=sqrt((p*p/4) - (6*s));;
        a/=6;
        b=p/4 - a;
        b-=sqrt((p*p/16) - (3*s/2));
        b/=2;
        c=(p/4) - a - b;
        printf("%.2f\n",a*b*c);
    }
    return 0;
}
