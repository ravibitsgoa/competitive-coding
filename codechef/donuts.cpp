#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
char _str[10];

#define READ_INT(_x)					\
{							\
  int _tmp = 0;					\
  register int _ch = getchar_unlocked();		\
  while (_ch < 48 || _ch > 57)			\
    _ch = getchar_unlocked();				\
  while (48 <= _ch && _ch <= 57)			\
  {							\
	   _tmp = (_tmp << 3) + (_tmp << 1) + _ch - 48;	\
	   _ch = getchar_unlocked();			\
  }							\
  (_x) = _tmp;					\
}							\

#define WRITE_INT(_x)				\
{ register int _i = 0;			\
  int _tmp = (_x);				\
  do						\
  { *(_str + _i++) = _tmp % 10 + 48;	\
    _tmp /= 10;				\
  } while (_tmp != 0);			\
  for (_i--; _i >= 0; _i--)			\
    putchar_unlocked(*(_str + _i));		\
}
int main()
{ int t;
  //cin>>t;
  READ_INT(t);
  while(t--)
  { int N, M;
    //cin>>N>>M;
    READ_INT(N);
    READ_INT(M);
    int A[M];
    for(int i=0; i<M; i++)
    { READ_INT(A[i]);
    }
    sort(A, A+M);
    int ans=0, link=M-1;//link is number of links, remaining.
    for(int i=0; i<M && link>0; i++)
    { if(A[i]<link)       //Take any small actual example to check this out.
      { link-=A[i]+1;
        ans+=A[i];
      }
      else
      { ans+=link;
        link=0;
      }
    }
    WRITE_INT(ans);
    putchar_unlocked('\n');

  }
  return 0;
}
