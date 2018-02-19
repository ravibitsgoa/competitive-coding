#include<algorithm>
#include<iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
  int ans=0;
  int stack[n], stacksize=0, popped_Upto=0;
  for(int i=0; i<2*n; i++)
  { string x;
    cin>>x;
    if(x=="add")
    { int y;
      cin>>y;
      stack[stacksize++]=y;
    }
    else
    { if(stack[stacksize-1]!=popped_Upto+1)
      { sort(stack, stack+stacksize);
        reverse(stack, stack+stacksize);
        ans++;
      }
      popped_Upto++;
      stacksize--;
    }
    cout<<ans<<endl;
  }
  cout<<ans;
return 0;
}
