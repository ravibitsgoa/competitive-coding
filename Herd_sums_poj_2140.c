#include<stdio.h>
#include<math.h>
int main()
{   int n, k, ans=0;
    float x;
    scanf("%d",&n);
    k=(1+sqrt(1.00+(8*n)))/2;
    for(int i=1; i<k+1; i++)
    {   x=(2*n - (i*(i-1)))/(2.0*i);//aa 2.0 nu importance samjya ke nahi? :D
        int y=x;
        if(x==y && x>0)//aa shu karyu kai samjaay chhe? no samjaay to mane malo :D
        {   ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
