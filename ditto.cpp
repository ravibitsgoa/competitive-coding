#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{   int n;
	    cin>>n;
	    int sumd=0;
	    for(int i=0; i<n; i++)
	    {   int x;
	        cin>>x;
	        sumd+=x;
	    }
	    for(int i=0; i<n; i++)
	    {   int x;
	        cin>>x;
	        sumd-=x;
	    }
	    if(sumd)
	        cout<<"NO"<<'\n';
	    else
	        cout<<"YES"<<'\n';
	}
	return 0;
}
