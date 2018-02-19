/*#include <iostream>
using namespace std;
const int MOD = 1e9 +7;
long long Comb[300][300];
int main()
{
	Comb[1][0] = Comb[1][1]=1;
	for(int i=2; i<10; i++)
	{	Comb[i][0]=1;
		//cout << Comb[i][0] << ' '; 
		for(int j=1; j<=i; j++)
		{	Comb[i][j] = (Comb[i-1][j]+Comb[i-1][j-1]) %MOD;
			//cout << Comb[i][j] << ' ';
		}
		//cout << '\n';
	}
	//cout << Comb[3][0]<<Comb[3][1]<<Comb[3][2]<<' '<<Comb[3][3]<<endl;
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int p, q, n;
		cin >> p >> q >> n;
		int b1, b2;
		cin >> b1 >> b2;
		int s1, s2;
		cin >> s1 >> s2;
		
		long long ycoeff[q+1]={0};
		for(long long y=0; y<=q && y<=n; y++)
		{	for(long long power=0; power<=b2 && power<=y; power++)
			{	long long k= y - (s2+1)*power;
				if(k<0)
					continue;
				long long hmm = (Comb[b2][power]*Comb[b2+k-1][k])%MOD;
				if(power&1)
					hmm *= -1;
				ycoeff[y] += hmm;
			}
		}
		
		long long xcoeff[q+1]={0};
		for(long long x=0; x<=p && x<=n; x++)
		{	for(long long power=0; power<=b1 && power<=x; power++)
			{	long long k= x - (s1+1)*power;
				//cout <<x<<' '<<power <<' '<<k<<' ';
				if(k<0)
				{	//cout << endl;
					continue;
				}
				long long hmm = (Comb[b1][power]*Comb[b1+k-1][k]) % MOD;
				if(power&1)
					hmm *= -1;
				xcoeff[x] += hmm;
				//cout << hmm<<endl;
			}
		}
		
		long long ans=0;
		for(int x=0; x<=p && x<=n; x++)
		{	//cout << xcoeff[x]<<endl;
			if((n-x)>=0 && (n-x)<=q)
				ans= (ans+ (xcoeff[x]*ycoeff[n-x])%MOD) % MOD;			
		}
		cout << ans%MOD<<'\n';
	}
}*/