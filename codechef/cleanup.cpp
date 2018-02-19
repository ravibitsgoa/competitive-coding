#include<iostream>
using namespace std;
int main()
{   int t, tot, com, i, n[1000], c[1000];
    bool turn =0;
    cin>>t;
    while(t--)
    {   cin>>tot;
        cin>>com;
        for(i=0; i<1000; i++)
        { n[i]=i;
        }
        n[0]=1;//filling useless random values to n.
        for(i=0; i<com; i++)
        {   cin>>c[i];
        }
        for(i=0; i<tot; i++)
        {   if(n[i]!=0){n[i]=i+1;}
            if(i<com)
            {   n[c[i]-1]=0;
            }
        }
        turn =0;
        for(i=0; i<tot; i++)
        {   if(n[i]!=0)
            {   if(turn==0)
                {   cout<<n[i]<<' ';
                    turn=1;
                }
                else{turn = 0;}
            }
        }
        cout<<endl;
        turn =0;
        for(i=0; i<tot; i++)
        {   if(n[i]!=0)
            {   if(turn==1)
                {   cout<<n[i]<<' ';
                    turn=0;
                }
                else{turn = 1;}
            }
        }
        cout<<endl;
    }
    return 0;
}
