#include<iostream>
using namespace std;
int main()
{   int k, n;
    cin>>k>>n;
    string A[k], B;
    for(int i=0; i<k; i++)
        cin>>A[i];
    for(int i=0; i<n; i++)
    {   cin>>B;
        bool flag=0;
        if(B.length()>=47)
        {   flag=1;
        }
        for(int j=0; j<k && flag==0; j++)
        { for(int a=0, b=0; flag==0 && b<B.length(); b++)
          { if((A[j][a]!=B[b])) //&& (a<A[j].length()-1) && (A[j][a]!=A[j][a+1]))
            { a=0;
            }
            if(A[j][a]==B[b])
            { a++;
            }
            if(a==A[j].length())
              flag=1;
          }
        }
        if(flag)	cout<<"Good"<<'\n';
        else 		cout<<"Bad"<<'\n';
    }
    return 0;
}//This is still buggy. :(
