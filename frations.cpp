#include <iostream>
using namespace std;
int main()
{   int N, x=0, sum=0, num=0;
    cin >> N;
    int B[N];
    for(int i = 0;i < N;i++)
    {  cin >> B[i];
       if(B[i]%2)
       {    if(x){sum+=2*(i-x); x=0;}// cout<<B[i]<<' ';}
            else{x=i;}// cout<<B[i]<<' ';}
            num++;
       }
    }
    if(num%2==0)cout<<sum;
    else cout<<"NO";
    return 0;
}
