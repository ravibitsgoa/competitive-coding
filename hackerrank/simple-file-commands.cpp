#include <bits/stdc++.h>

using namespace std;

int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  map<string, int> files;
  int q;
  cin >> q;
  // Process each command
  for(int a0 = 0; a0 < q; a0++)
  { // Read the first string denoting the command type
    string command;
    cin >> command;
    // Write additional code to read the command's file name(s) and process the command
    if(command=="crt")
    { string name;
      cin>>name;
      if(files[name]==0)
      { files[name]=1;
        cout<<"+ "<<name<<'\n';
      }
      else
      { int i;
        for(i=1; 1; i++)// a forever indexed loop!
        { if(files[name+"("+to_string(i)+")"] == 0)
          { files[name+"("+to_string(i)+")"]=1;
            break;
          }
        }
        cout<<"+ "<<name+"("<<to_string(i)<<")"<<'\n';
      }
    }
    else if (command=="del")
    { string name;
      cin>>name;
      if(files[name]==1)
        files[name]=0;
      cout<<"- "<<name<<'\n';
    }
    else//command == "rnm"
    { string name1, name;
      cin>>name1>>name;
      files[name1]=0;
      if(files[name]==0)
      { files[name]=1;
        cout<<"+ "<<name<<'\n';
      }
      else
      { int i;
        for(i=1; 1; i++)// a forever indexed loop!
        { if(files[name+"("+to_string(i)+")"] == 0)
          { files[name+"("+to_string(i)+")"]=1;
            break;
          }
        }
        name+="("<<to_string(i)<<")";
      }
      cout<<"r "<<name1<<" -> "<<name<<'\n';
    }
    // Print the output string appropriate to the command

  }
return 0;
}
