//This makes frequency distribution of digits of string N, and works in two cases:
//1. frequency of some digit is > 1, so we can have char 66, 77, 88.
//2. frequency of two digits is > 0, so we can have all other 'A' to 'Z'.
#include <iostream>
using namespace std;
/*int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T;
	cin>>T;
	while(T--)
	{	string N;
		cin>>N;
		int arr[10]={0};
		for(char i : N)
		{	arr[i-'0']++;			
		}
		int ans[95]={0};
		for(int i=65; i<91; i++)
		{	int x=i%10, y=i/10;
			if(arr[x] && arr[y])
			{	if(x!=y || (arr[x]>1 && arr[y]>1))
					ans[i]=1;
			}
		}
		for(int i=65; i<91; i++)
			if(ans[i])
				cout<<(char)i;
		cout<<'\n';
	}
	return 0;
}*/
