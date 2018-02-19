#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
char to_Upper(char x)
{ if(x>='A' && x<='Z')  return x;
  else
    return x+'A'-'a';
}
char to_Lower(char x)
{ if(x>='a' && x<='z')  return x;
  else
    return x-'A'+'a';
}

int main()
{ int t;
  cin>>t;
  cin.ignore();
  while(t--)
  { string line;
    string part;
    vector<string> name;
    getline(cin, line);
    istringstream iss(line);
    while ( iss >> part)
    { name.push_back(part);
    }
    for(int i=0; i<name.size()-1; i++)
    { cout<<to_Upper(name[i][0])<<". ";
    }
    cout<<to_Upper(name[name.size()-1][0]);
    for(int i=1; i<name[name.size()-1].length(); i++)
      cout<<to_Lower(name[name.size()-1][i]);
    cout<<'\n';
  }
return 0;
}
