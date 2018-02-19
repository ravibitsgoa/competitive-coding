#include<iostream>
using namespace std;
int mat[10][10], n;
int pow(int i, int x)
{ int ans=1;
  while(x--)
    ans*=i;
  return ans;
}
int det(int rstart, int cstart, int rsize)
{ if(rsize==1)
  { //cout<<'h';
    return mat[rstart][cstart];
  }
  if(rsize==2)
  { //cout<<'j';
    //cout<<mat[rstart][cstart]<<mat[(rstart+1)%n][(cstart+1)%n]<<mat[(rstart+1)%n][cstart]<<mat[rstart][(cstart+1)%n];
    return ((mat[rstart][cstart]*mat[(rstart+1)%n][(cstart+1)%n])-(mat[(rstart+1)%n][cstart]*mat[rstart][(cstart+1)%n]));
  }
  //cout<<'a';
  int ans=0;
  for(int j=0; j<rsize; j++)//This program is circularized.
  { ans+=pow(-1,rstart+(j+cstart)%n)*mat[rstart][(j+cstart)%n]*det((rstart+1)%n, (cstart+j+1)%n, rsize-1);
    if(rsize>3)
      cout<<ans<<' ';
  }
  //cout<<ans<<endl;
  return ans;
}
int main()
{ cout<<"Enter the number (<10) of rows of a square matrix.";
  cin>>n;
  if(n<1 || n>10)
  { cout<<"Invalid.";
    return 1;
  }
  for(int i=0; i<n; i++)
  { for(int j=0; j<n; j++)
      cin>>mat[i][j];
  }
  cout<<det(0,0,n);

}
