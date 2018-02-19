#include<cstdio>
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
void fastscan(int &number)
{
    //variable to indicate sign of input number
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
}
int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int sumtill[100][100]={};
  int inp[100][100]={};

  int t;
  fastscan(t);
  while(t--)
  {
    int n;
    fastscan(n);
    for(int i=0; i<n; i++)
    { for(int j=0; j<=i; j++)
        fastscan(inp[i][j]);
    }
    int sum=0;
    sumtill[0][0]=inp[0][0];
    for(int i=1; i<n; i++)
    { sumtill[i][0]=inp[i][0]+sumtill[i-1][0];
      for(int j=1; j<i; j++)
      { sumtill[i][j]=inp[i][j]+max(sumtill[i-1][j], sumtill[i-1][j-1]);
      }
      sumtill[i][i]=inp[i][i]+sumtill[i-1][i-1];
    }
    for(int i=0; i<n; i++)
      sum=max(sum, sumtill[n-1][i]);
    cout<<sum<<'\n';
  }
return 0;
}
