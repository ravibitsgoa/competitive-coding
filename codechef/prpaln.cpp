#include <iostream>
#include <string>
using namespace std;

bool isPalin(string x)
{   int left=0, right=x.length()-1;
    while(left<=right)
    {   if(x[left]!=x[right])
        {   return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{   int n;
    cin>>n;
    while(n--)
    {   string x;
        cin>>x;
        int ans=0;
        if(isPalin(x))
            ans=1;
        else
        {
            int l=x.length();
            for(int i=0; i<l; i++)
            {   if(x[i]!=x[l-i-1])
                {   string y= x.substr(0, i)+ x.substr(i+1, l-i);
                    string z= x.substr(0, l-i-1)+ x.substr(l-i, i);
                    if( isPalin(y) || isPalin(z) )
                        ans=1;
                    break;
                }
            }
        }
        if(ans)
            cout<<"YES"<<'\n';
        else
            cout<<"NO\n";
    }
    return 0;
}
