#include<iostream>
using namespace std;
int main()
{   int r, c, i, j;
    cin>>r>>c;
    for(i=0; i<r; i++)
    {   for(j=0; j<c; j++)
        {   if(i%2==1)
            {   if(j==c-1 && (i/2)%2==0)
                {   cout<<'#';
                }
                else if(j==0 && (i/2)%2 ==1)
                cout<<'#';
                else cout<<'.';
            }
            else cout<<'#';
        }
        cout<<endl;
    }
    return 0;
}
