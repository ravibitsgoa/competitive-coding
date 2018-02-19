#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string s;
    cin >> s;
    //cout<<s;
    int n;
    cin >> n;
    long long int freq[26]={0};
    for(int i=0; i<s.length(); i++)
        freq[s[i]-'a']++;
    for(int a0 = 0; a0 < n; a0++){
        long long int x;
        int i;
        cin >> x;
        for(i=0; i<26; i++)
        {   //if(a0==0)
              //cout<<freq[i];
            if((freq[i]*(i+1))>=x && x%(i+1)==0)
            {   cout<<"Yes";
                break;
            }
        }
        if(i==26)
            cout<<"No";
        cout<<endl;
    }
    return 0;
}
