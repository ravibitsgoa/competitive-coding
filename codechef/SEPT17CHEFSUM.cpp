//This was a pretty trivial implementation question.
#include <iostream>
using namespace std;
const long long INFINITY = 1e15;
/*int main()
{
	int T;
	cin>>T;
	while(T--)
	{	int N;
		cin>>N;
		long long arr[N];
		for(int i=0; i<N; i++)
			cin>>arr[i];
		long long prefix[N]={0}, suffix[N]={0};
		prefix[0] = arr[0];
		for(int i=1; i<N; i++)
			prefix[i] = prefix[i-1] + arr[i];
		suffix[N-1] = arr[N-1];
		for(int i=N-2; i>=0; i--)
			suffix[i] = suffix[i+1] + arr[i];
		long long mn=INFINITY, ans=0;
		for(int i=0; i<N; i++)
		{	if(suffix[i] + prefix[i] < mn)
			{	ans=i;
				mn= suffix[i] + prefix[i];
			}
		}
		cout<<ans+1<<'\n';
	}
	return 0;
}*/