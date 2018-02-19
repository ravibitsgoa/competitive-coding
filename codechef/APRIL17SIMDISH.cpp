using namespace std;
#include <bits/stdc++.h>
int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    { string x[4], y;
      for(int i=0; i<4; i++)
        cin>>x[i];
      int count =0;
      for(int i=0; i<4; i++)
      { cin>>y;
        if(y==x[0] || y==x[1] || y==x[2] || y==x[3])
          count++;
      }
      if(count>=2)
        cout<<"similar"<<'\n';
      else
        cout<<"dissimilar"<<'\n';
    }
    return 0;
}
