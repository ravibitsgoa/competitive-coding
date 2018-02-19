#include<map>
#include<iostream>
using namespace std;
int main()
{ char key1[26], key2[26];
  map<char, char> trans;
  for(int i=0; i<26; i++)
    cin>>key1[i];
  for(int i=0; i<26; i++)
  { cin>>key2[i];
    trans[key1[i]]=key2[i];
    trans[key1[i]+'A'-'a']=(key2[i]+'A'-'a');
  }
  string x;
  cin>>x;
  for(int i=0; i<x.length(); i++)
  { if((x[i]>='A' && x[i]<='Z')||(x[i]>='a' && x[i]<='z'))
    { cout<<trans[x[i]];
    }
    else
      cout<<x[i];
  }
  return 0;
}
