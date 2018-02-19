#include<string.h>
#include<stdio.h>
void fastscan(int *number)
{
    //variable to indicate sign of input number
    register int c;

    *number = 0;

    // extract current character from buffer
    c = getchar_unlocked();
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        *number = (*number)*10 + c - 48;
}
int main()
{ int t;
  fastscan(&t);
  while(t--)
  { int N, K;
    fastscan(&N);
    fastscan(&K);
    int got[100005]={0}, gotingred=0;
    int x=0; //jaldi patyu ke nahi eno bullion.
    while(N--)
    { if(gotingred==K)
        x=1;
      int numofingred;
      fastscan(&numofingred);
      int i;
      while(numofingred--)
      { fastscan(&i);
        if(got[i-1]==0)
        { got[i-1]=1;
          gotingred++;
        }
      }
    }
    if(x==1 && gotingred==K)
      printf("some\n");
    else if(x==0 && gotingred==K)
      printf("all\n");
    else if(gotingred<K)
      printf("sad\n");
  }
return 0;
}
