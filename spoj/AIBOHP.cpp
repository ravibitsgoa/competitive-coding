#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {   string x;
        cin>>x;
        int left=0, right= x.length()-1, count=0;
        while(left <= right)
        {   if(x[left]!=x[right] && x[left]==x[right-1])
            {   right--;
                count++;
            }
            else if(x[left]!=x[right])
            {   left++;
                count++;
            }
            else
            {   left++;
                right--;
            }
        }
        cout<<count<<'\n';
    }
    return 0;
}
