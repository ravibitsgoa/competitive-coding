#include<iostream>
using namespace std;
int f(int n, int k, int a)
{ if(k>a+1) {return f(n, 2*a +1 -k ,a);}
  else if(n==1 && (k<1 || k>a))
    return 0;
  else if(n==1)
    return 1;
  else
  { int sum=0;
    for(int j=1; j<k; j++)
    { sum+=f(n-1, k-j, a);
    }
    return sum;
  }
}
int main()
{ for(int i=1; i<13; i++)
    cout<<f(2,i,6);
return 0;
}
