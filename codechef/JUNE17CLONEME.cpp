//This is a solution to question "Cloning"(CLONEME) featured in June long contest.
//This is just a simulation to get 10 points.
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{ int T;
  cin>>T;
  while(T--)
  { int N, Q;
    cin>>N>>Q;
    int A[N];
    for(int i=0; i<N; i++)
      cin>>A[i];
    while(Q--)
    { int a,b,c,d;
      cin>>a>>b>>c>>d;
      a--; b--; c--; d--;
      int A1[b+1-a], A2[d+1-c];
      for(int i=a; i<=b; i++)
        A1[i-a]=A[i];
      for(int i=c; i<=d; i++)
        A2[i-c]=A[i];
      sort(A1, A1+b+1-a);
      sort(A2, A2+d+1-c);
      bool ans=1;
      int diff=0;
      for(int i=0; i<=b-a; i++)
      { if(A1[i]!=A2[i])
          diff++;
        if(diff==2)
          ans=0;
      }
      if(ans)
        cout<<"YES";
      else
        cout<<"NO";
      cout<<'\n';
    }
  }
return 0;
}
