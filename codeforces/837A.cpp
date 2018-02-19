#include<iostream>
#include<vector>
using namespace std;
int main()
{   int n;
    cin>>n;
    n++;
    char text[n];
    cin.ignore();
    cin.getline(text, n);
    int temp=0, ans=0;
    for(int i=0; i<n; i++)
    {   if(text[i]<='Z' && text[i]>='A')
            temp++;
        else if(text[i]==' ')
        {   ans=max(ans, temp);
            temp=0;
        }
    }
    ans=max(ans, temp);
    cout<<ans;
    return 0;
}
