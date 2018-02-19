#include <bits/stdc++.h>

#define MODt 1001
#define MODa 1000000001
#define MODn 100001

using namespace std;

int main ()
{
    /* initialize random seed: */
    srand (time(NULL));

    int t=rand()%MODt;

    cout<<t<<endl;

    while (t--)
    {
        int n=rand()%MODn;  //for n > 1e5 use n=rand()%MODn+MODn
        cout <<n<<endl;
        while (n--)
        {
            int a=rand()%MODa;
            cout<<a<<" ";
        }
        cout<<endl;
    }
    return 0;
}
