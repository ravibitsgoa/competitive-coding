#include<iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
  int a[n], b[n];
  for(int i=0; i<n; i++)
    cin>>a[i];
  int sim=0;
  for(int i=0; i<n; i++)
  { cin>>b[i];
    if(b[i]==a[i])
      sim++;
  }
  int per[n+1]={0}, seq[n]={0};
  if(sim == n-2)
  { for(int i=0; i<n; i++)
    { if(a[i]==b[i])
      { per[a[i]]=1;
        seq[i]=a[i];
      }
    }
    int x=-1, y;
    for(int i=0; i<n; i++)
    { if(a[i]!=b[i] && x==-1)
      { //per[a[i]]=1;
        //seq[i]=a[i];
        x=i;
      }
      else if(a[i]!=b[i])
        y=i;
    }
    if(per[a[x]]==0 && per[b[y]]==0 && a[x]!=b[y])
    { seq[x]=a[x];
      seq[y]=b[y];
    }
    else if(per[b[x]]==0 && per[b[y]]==0 && b[x]!=b[y])
    { seq[x]=b[x];
      seq[y]=b[y];
    }
    else if(per[a[x]]==0 && per[a[y]]==0 && a[x]!=a[y])
    { seq[x]=a[x];
      seq[y]=a[y];
    }
    else //if(per[a[x]]==0 && per[a[y]]==0 && a[x]!=a[y])
    { seq[x]=b[x];
      seq[y]=a[y];
    }
  }
  else if(sim == n-1)
  { for(int i=0; i<n; i++)
    { if(a[i]==b[i])
      { seq[i]=a[i];
        per[a[i]]=1;
      }
    }
    for(int i=0; i<n; i++)
    { if(a[i]!=b[i])
      { int k=1;
        for(;k<=n; k++)
        { if(per[k]==0)
            break;
        }
        per[k]=1;
        seq[i]=k;
        break;
      }
    }
  }
  else
  { for(int i=0; i<n; i++)
    { if(per[a[i]]==0)
      { seq[i]=a[i];
        per[a[i]]=1;
      }
    }
    for(int i=0; i<n; i++)
    { if(seq[i]==0)
      { int k=1;
        for(;k<=n; k++)
        { if(per[k]==0)
            break;
        }
        per[k]=1;
        seq[i]=k;
        break;
      }
    }
  }
  for(int i=0; i<n; i++)
    cout<<seq[i]<<' ';
return 0;
}
