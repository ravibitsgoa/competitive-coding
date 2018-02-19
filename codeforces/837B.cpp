#include<map>
#include<iostream>
using namespace std;
int main()
{   int n, m;
    cin>>n>>m;
    char mat[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];
    map<char, int> arr;
    arr['R']=0;
    arr['G']=1;
    arr['B']=2;
    if(n%3 && m%3)
        cout<<"No";
    else if(n%3==0 && m%3!=0)
    {   int var[3]={0,0,0};
        var[arr[mat[0][0]]]=1;
        for(int i=0; i<n/3; i++)
        {   for(int j=0; j<m; j++)
            {   if(var[arr[mat[i][j]]]==0)
                {   cout<<"No";
                    return 0;
                }
            }
        }
        if(var[arr[mat[n/3][0]]]==0)
            var[arr[mat[n/3][0]]]=2;
        else
        {   cout<<"No";
            return 0;
        }
        for(int i=n/3; i<2*n/3; i++)
        {   for(int j=0; j<m; j++)
            {   if(var[arr[mat[i][j]]]!=2)
                {   cout<<"No";
                    return 0;
                }
            }
        }
        if(var[arr[mat[2*n/3][0]]]==0)
            var[arr[mat[2*n/3][0]]]=3;
        else
        {   cout<<"No";
            return 0;
        }
        for(int i=2*n/3; i<n; i++)
        {   for(int j=0; j<m; j++)
            {   if(var[arr[mat[i][j]]]!=3)
                {   cout<<"No";
                    return 0;
                }
            }
        }
        cout<<"Yes";
    }
    else if(n%3!=0 && m%3==0)
    {   int var[3]={0,0,0};
        var[arr[mat[0][0]]]=1;
        for(int j=0; j<m/3; j++)
        {   for(int i=0; i<n; i++)
            {   if(var[arr[mat[i][j]]]==0)
                {   cout<<"No";
                    return 0;
                }
            }
        }
        if(var[arr[mat[0][m/3]]]==0)
            var[arr[mat[0][m/3]]]=2;
        else
        {   cout<<"No";
            return 0;
        }
        for(int j=m/3; j<2*m/3; j++)
        {   for(int i=0; i<n; i++)
            {   if(var[arr[mat[i][j]]]!=2)
                {   cout<<"No";
                    return 0;
                }
            }
        }
        if(var[arr[mat[0][2*m/3]]]==0)
            var[arr[mat[0][2*m/3]]]=3;
        else
        {   cout<<"No";
            return 0;
        }
        for(int j=2*m/3; j<m; j++)
        {   for(int i=0; i<n; i++)
            {   if(var[arr[mat[i][j]]]!=3)
                {   cout<<"No";
                    return 0;
                }
            }
        }
        cout<<"Yes";
    }
    else
    {   int var[3]={0,0,0};
        var[arr[mat[0][0]]]=1;
        for(int j=0; j<m/3; j++)
        {   for(int i=0; i<n; i++)
            {   if(var[arr[mat[i][j]]]==0)
                {   cout<<"No";
                    return 0;
                }
            }
        }
        if(var[arr[mat[0][m/3]]]==0)
            var[arr[mat[0][m/3]]]=2;
        else
        {   cout<<"No";
            return 0;
        }
        for(int j=m/3; j<2*m/3; j++)
        {   for(int i=0; i<n; i++)
            {   if(var[arr[mat[i][j]]]!=2)
                {   cout<<"No";
                    return 0;
                }
            }
        }
        if(var[arr[mat[0][2*m/3]]]==0)
            var[arr[mat[0][2*m/3]]]=3;
        else
        {   cout<<"No";
            return 0;
        }
        for(int j=2*m/3; j<m; j++)
        {   for(int i=0; i<n; i++)
            {   if(var[arr[mat[i][j]]]!=3)
                {   cout<<"No";
                    return 0;
                }
            }
        }
        cout<<"Yes";
    }
    return 0;
}
