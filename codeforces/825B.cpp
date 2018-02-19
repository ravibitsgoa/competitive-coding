#include<bits/stdc++.h>
using namespace std;
int main()
{ char mat[10][10];
  for(int i=0; i<10; i++)
  { for(int j=0; j<10; j++)
      cin>>mat[i][j];
  }
  int a=0;
  for(int i=0; i<10 && a==0; i++)
  { for(int j=0; j<10 && a==0; j++)
    { if(mat[i][j]=='X' || mat[i][j]=='.')
      { int os=0, c=mat[i][j]=='X', count=c, dot=!c;
        for(int k=1; k<5 && (i+k)<10; k++)
        { if(mat[i+k][j]=='X')
            count++;
          else if(mat[i+k][j]=='.')
            dot++;
          else
            os++;
        }
        if((count==4 && dot==1) || (count==4 && dot==0 && os==0 && i>0 && mat[i-1][j]=='.'))
        { cout<<"YES";
          //cout<<i<<j<<'a';
          a=1;
          break;
        }

        count=c;
        dot=!c;
        os=0;
        for(int k=1; k<5 && (j+k)<10; k++)
        { if(mat[i][j+k]=='X')
            count++;
          else if(mat[i][j+k]=='.')
            dot++;
          else
            os++;
        }
        if((count==4 && dot==1) || (count==4 && dot==0 && os==0 && j>0 && mat[i][j-1]=='.'))
        { cout<<"YES";
          //cout<<i<<j<<'b';
          a=1;
          break;
        }

        count=c;
        dot=!c;
        os=0;
        for(int k=1; k<5 && (i+k)<10 && (j+k)<10; k++)
        { if(mat[i+k][j+k]=='X')
            count++;
          else if(mat[i+k][j+k]=='.')
            dot++;
          else
            os++;
        }
        if((count==4 && dot==1) || (count==4 && dot==0 && os==0 && i>0 && j>0 && mat[i-1][j-1]=='.'))
        { cout<<"YES";
          //cout<<i<<j<<'c';
          a=1;
          break;
        }

        count=c;
        dot=!c;
        os=0;
        for(int k=1; k<5 && (i-k)>=0 && (j+k)<10; k++)
        { if(mat[i-k][j+k]=='X')
            count++;
          else if(mat[i-k][j+k]=='.')
            dot++;
          else
            os++;
        }
        if((count==4 && dot==1) || (count==4 && dot==0 && os==0 && i<9 && j>0 && mat[i+1][j-1]=='.'))
        { cout<<"YES";
          //cout<<i<<j<<'d';
          a=1;
          break;
        }
        count=c;
        dot=!c;
        os=0;
        for(int k=1; k<5 && (i+k)<10 && (j-k)>=0; k++)
        { if(mat[i+k][j-k]=='X')
            count++;
          else if(mat[i+k][j-k]=='.')
            dot++;
          else
            os++;
        }
        if((count==4 && dot==1) || (count==4 && dot==0 && os==0 && i>0 && j<9 && mat[i-1][j+1]=='.'))
        { cout<<"YES";
          //cout<<i<<j<<'e';
          a=1;
          break;
        }
      }
    }
  }
  if(!a)
    cout<<"NO";
  return 0;
}
