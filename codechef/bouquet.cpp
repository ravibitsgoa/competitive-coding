#include<iostream>
using namespace std;
int main()
{   int t;
    cin>>t;
    for(int k=0; k<t; k++)
    {   int x[3][3], s1, s2, s3, s4, s5, s6;
        for(int i=0; i<3; i++)
        {   for(int j=0; j<3; j++)
            {   cin>>x[i][j];
            }
        }
        s1 =x[0][0]+x[0][1]+x[0][2];
        s2 =x[1][0]+x[1][1]+x[1][2];
        s3 =x[2][0]+x[2][1]+x[2][2];
        s4 =x[0][0]+x[1][0]+x[2][0];
        s5 =x[0][1]+x[1][1]+x[2][1];
        s6 =x[0][2]+x[1][2]+x[2][2];
        if(s6%2==0){s6=0;}
        if(s6<s5 && s5%2){s6=s5;}
        if(s6<s4 && s4%2){s6=s4;}
        if(s6<s3 && s3%2){s6=s3;}
        if(s6<s2 && s2%2){s6=s2;}
        if(s6<s1 && s1%2){s6=s1;}
        cout<<s6<<endl;
    }
    return 0;
}
