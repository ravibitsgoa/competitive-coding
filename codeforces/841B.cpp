#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int arr[n];
	long long count=0;
    for(int i=0; i<n; i++)
    {   cin>>arr[i];
		if(arr[i]%2)
			count++;
	}
	if(count>0)
		cout<<"First";
	else
		cout<<"Second";
    return 0;
}
