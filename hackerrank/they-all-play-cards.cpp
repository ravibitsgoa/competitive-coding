#include <cstdio>
#include <set>
#include <iostream>
using namespace std;


int main() {
    int N, M;
    cin>>N>>M;
    int cardNum[N];
    int cards[N][M]={0};
    for(int i=0; i<N; i++)
    {   cin>>cardNum[i];
        for(int j=0; j<M; j++)
            cards[i][j]=0;
        for(int j=0; j<cardNum[i]; j++)
        {   int x;
            cin>>x;
            cards[i][x]=1;
        }
    }
    if(N>12 || (1<<N)>M)
    {   cout<<"YES";
    }
    else
    {   set<string> atLeastOneMissing;
        for(int i=1; i<=M; i++)
        {   char s[N]="";
            for(int j=0; j<N; j++)
            {   if(cards[j][i])
                    s[j]='1';
                else
                    s[j]='0';
            }
            s[N]=0;
            atLeastOneMissing.insert(s);
            //cout<<s<<endl;
        }
        //cout<<atLeastOneMissing.size();
        if(atLeastOneMissing.size() < (1<<N))
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}
