#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int s[4], i, c=0;
    cin>>s[0]>>s[1]>>s[2]>>s[3];
    sort(s, s+4);
    c=1;
    for(i=1; i<4; i++)
    {   if(s[i]!=s[i-1])
        c++;
    }
    cout<< 4-c;
return 0;
}
