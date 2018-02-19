#include<iostream>
using namespace std;
int main()
{ int T;
  cin>>T;
  for(int i=1; i<=T; i++)
  { int N, it=0, N0;
    cin>>N;
    N0=N;
    int arr[10]={0}, count=0;
    for(it=0; it<=100; it++)
    { int Ncopy=N;
      while(Ncopy>0)
      { if(arr[Ncopy%10]==0)
        { arr[Ncopy%10]=1;
          count++;
        }
        if(count==10)
          break;
        Ncopy/=10;
      }
      if(count==10)
        break;
      N+=N0;
    }
    if(count==10)
      cout<<"Case #"<<i<<": "<<N<<'\n';
    else
      cout<<"Case #"<<i<<": INSOMNIA"<<'\n';
  }
  return 0;
}
