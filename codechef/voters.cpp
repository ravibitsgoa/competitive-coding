#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int n1, n2, n3, A[150003], B[50001], n;
    cin>>n1>>n2>>n3;
    n1+=n2+n3;
    for(int i=0; i<n1; i++)
    {   cin>>A[i];
    }
    sort(A, A+n1); n=0;
    for(int i=0; i<n1; i++)
    {   if((A[i]==A[i-1] && i>1 && A[i-2]==A[i])||(A[i]==A[i-1] && i>1 && A[i+1]!=A[i] && A[i-2]!=A[i]))
        {   B[n]=A[i];
            n++;
        }
        else if(i==1 && A[i]==A[i-1] && A[i+1]!=A[i])
        {   B[n]=A[i];
            n++;
        }
    }
    cout<<n<<endl;
    for(int i=0; i<n; i++)
    {   cout<<B[i]<<endl;
    }
    return 0;
}
