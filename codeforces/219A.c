#include<string.h>
#include<stdio.h>
int main()
{ int k;
  scanf("%d",&k);
  char inp[1005]="", rep[1005]="";
  scanf("%s",inp);
  int l=strlen(inp), f[26]={0};
  for(int i=0; i<l; i++)
    f[inp[i]-'a']++;
  int j=0;
  for(int i=0; i<26; i++)
  { if(f[i]>0)
    { if(f[i]%k==0)
        rep[j++]=i+'a';
      else
      { printf("-1");
        return 0;
      }
    }
  }
  while(k--)
    printf("%s",rep);
return 0;
}
