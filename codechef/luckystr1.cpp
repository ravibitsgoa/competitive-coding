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
        {   cout<<"good"<<endl; break; flag=1;
        }
        for(int j=0; j<k; j++)
        {   int z=0;
            for(int a=0; a<B.length(); a++)
            {   if(A[j][z]==B[a])
                    z++;
            }
            if(z==A[j].length()){cout<<"good"<<endl; flag=1; break;}
        }
        if(!flag)cout<<"bad"<<endl;
    }
    return 0;
}
