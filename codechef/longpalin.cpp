//http://opc.iarcs.org.in/index.php/problems/LONGPALIN
#include <iostream>
#include <cassert>
using namespace std;
int main()
{   int n;
    string x;
    cin>>n>>x;
    int ispalin[n][n]={0}, mxlen=0, mxi=0;

    /*for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ispalin[i][j] = -1;

    for(int i=0; i<n; i++)
    {   ispalin[i][i] = 1;
        if(i+1<n && (x[i] == x[i+1]))
        {   ispalin[i][i+1] = true;
            mxlen=1;
            mxi=i;
        }
        else
            ispalin[i][i+1] = false;
    }

    for(int len=2; len<n; len++)
    {   for(int i=0; i<n; i++)
        {   if(i+len < n)
            {   if( (x[i]==x[i+len]) && (ispalin[i+1][i+1 + len-2]) )
                    ispalin[i][i+len] = true;
                else
                    ispalin[i][i+len] = false;
                assert(ispalin[i+1][i+1 + len-2] != -1);
                if(ispalin[i][i+len] && len>mxlen)
                {   mxlen = len;
                    mxi = i;
                }
            }
            else
                break;
        }
    }

    cout<<mxlen+1<<endl;
    for(int i=mxi; i<mxi+mxlen+1; i++)
        cout<<x[i];*/
    return 0;
}
