#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    char d;
    cin >> d;
    int x;
    int y;
    cin >> x >> y;
    int dir;
    if(d=='n')
        dir =0;
    else if(dir=='e')
        dir =1;
    else if(dir=='s')
        dir =2;
    else
        dir =3;
    vector<vector<int> > arr(n, vector<int>(n,0));
    int i=x, j=y, c=0;
    while(c<=n*n)
    {
        if(dir == 0)
        {   if(i>0 && arr[i-1][j]==0)
            {   i--;
            }  
            if(j<n-1 && arr[i][j+1]==0)
            {   j++;
            }
            else if(j>0 && arr[i][j-1]==0)
            {   j--;
            }
            else
            {   i++;
            }
        }
        else if(dir ==1)
        {   if(j<n-1 && arr[i][j+1]==0)
            {   j++;
            }
            else if(i<n-1 && arr[i+1][j]==0)
            {   i++;
            }
            else if(i>0 && arr[i-1][j]==0)
            {   i--;
            }
            else //if(j>0 && arr[i][j-1]==0)
            {   j--;
            }
        }
        else if(dir == 2)
        {   if(i<n-1 && arr[i+1][j]==0)
            {   i++;
            }
            else if(j<n-1 && arr[i][j+1]==0)
            {   j++;
            }
            else if(j>0 && arr[i][j-1]==0)
            {   j--;
            }
            else //if(i>0 && arr[i-1][j]==0)
            {   i--;
            }
        }
        else if(dir ==3)
        {   if(j>0 && arr[i][j-1]==0)
            {   j--;
            }
            else if(i<n-1 && arr[i+1][j]==0)
            {   i++;
            }
            else if(i>0 && arr[i-1][j]==0)
            {   i--;
            }
            else //if(j<n-1 && arr[i][j+1]==0)
            {   j++;
            }
        }
        arr[i][j]=c;
        c++;
    }
    for(int i=0; i<n; i++)
    {   for(int j=0; j<n; j++)
            cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}

