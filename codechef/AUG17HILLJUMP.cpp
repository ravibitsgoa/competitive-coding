//This is just a hack to get 20 points.
#include <iostream>
using namespace std;
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin>>N>>Q;
    long long A[N+1];
    for(int i=1; i<N+1; i++)
        cin>>A[i];
    while(Q--)
    {   int type;
        cin>>type;
        if(type==1)
        {   int i, k, j=N+1, last;
            cin>>i>>k;
            last=i;
            while(k)
            {   for(j=last+1; j<=N && j<=(100+last); j++)
                {   if(A[j] > A[last])
                    {   k--;
                        last=j;
                        break;
                    }
                }
                if(j>N || j>(100+last))
                    break;
            }
            cout<<last<<'\n';
        }
        else if(type==2)
        {   long long L, R, X;
            cin>>L>>R>>X;
            for(int i=L; i<=R; i++)
                A[i]+=X;
        }
        else
            return 1;
    }
    return 0;
}
