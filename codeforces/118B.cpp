#include<iostream>
using namespace std;
int main()
{   int n, i, j;
    cin>>n;n++;
    for(int i=0; i<2*n -1; i++)
    {   for(int j=0; (i<n && j<i+2) || (i>=n && i+j<((3*n)-2)); j++)
        {   if(j%2==0){cout<<' ';}
            if(i+j<n-1) cout<<"  ";
            else if(i<n && j<=n-1 && j<i+1)   cout<<i+j-n+1<<' ';
            else if(i<n && j==i+1)            cout<<i+j-n+1;
            else if(i<n && j>=n && n-1>j-i)   cout<<n-1-(j-i)<<' ';
            else if(i<n && j>=n && n-1==j-i)  cout<<n-1-(j-i);
            else if(i<n)                      break;
            else if(i>=n && i-j>n-1)          cout<<"  ";
            else if(i>=n && j<n)              cout<<(n-1)-(i-j)<<' ';
            else if(i>=n && j>=n && i+j<((3*n)-2))cout<<3*n-3-(i+j)<<' ';
            else break;
        }
        cout<<endl;
    }
    return 0;
}
