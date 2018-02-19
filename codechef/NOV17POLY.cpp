#include <iostream>
using namespace std;
/*int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long poly[n][4];
		for(int i=0; i<n; i++)
			cin >> poly[i][0] >> poly[i][1] >> poly[i][2] >> poly[i][3];
		int q;
		cin>>q;
		while(q--)
		{
			long long x;
			cin>>x;
			//int ans=0;
			long long minval = poly[0][0]+ poly[0][1]*x+ poly[0][2]*x*x + poly[0][3]*x*x*x;
			for(int i=1; i<n; i++)
			{
				long long temp = poly[i][0]+ poly[i][1]*x+ poly[i][2]*x*x + poly[i][3]*x*x*x;
				//cout<<minval <<' '<<temp<<endl;
				if(minval > temp)
				{	minval = temp;
					//ans= i;
				}
			}
			cout<<minval<<'\n';
		}
	}
}*/