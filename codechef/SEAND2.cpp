/*#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
using namespace std;

int mod(string num, const int &a)
{
	if(num.length()<18)
	{	long long temp;
		istringstream(num) >> temp;
		return temp%a;
	}
	int start=0;//545645312156456454564456
    while((num.length()- start)>17)
	{	int efflen = num.length()-start, c=17;
		string startpart= num.substr(start, min(efflen, c));
		int rem = mod(startpart, a);
		string r= to_string(rem);
		//cout <<num.substr(start, min(efflen, c)) << ' ' << rem;
		unsigned int i;
		for(i=start+16; i>start+16-r.length(); i--)
		{	num[i] = rem%10 +'0';
			rem/=10;
		}
		start = i+1;
		/*cout <<endl;
		for(int i=0; i<start; i++)
			cout<<' ';
		cout << '^';
		cout<<endl<<num<<endl;*/
	}
	int efflen = num.length()-start, c=17;
	string ini=	num.substr(start, min(efflen, c));
    return mod(ini, a);
}

int compute(string A, const int B[], int n)
{
	int temp=0;
	for(int i=0; i<n; i++)
		temp+= mod(A, B[i]);
	return temp;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	std::random_device rd;
    std::mt19937 g(rd());
 
	int t;
	cin>>t;
	while(t--)
	{	string A;
		cin>>A;
		int n;
		cin>>n;
		int B[n];
		for(int i=0; i<n; i++)
			cin>>B[i];
		/*sort(B, B+n);
		int C[(int)((2*n)/3.0)], size=0;
		for(int i=n/3.0, size=0; i<n; i++, size++)
			C[size]=B[i];
		*/
		string bestA = A;
		string Acopy = A;
		int baseans = compute(A, B, n);
		//set<pair<int, string> > someA;
		for(int i=0; i<20; i++)
		{	shuffle(Acopy.begin(), Acopy.end(), g);
			int t = compute(Acopy, B, n);
			if(t < baseans)
			{	baseans = t;
				bestA = Acopy;
			}
			//someA.insert({t, Acopy});
		}
		/*vector<pair<int, string> >someAs(someA.begin(), someA.end());
		//std::default_random_engine generator;
		//std::uniform_int_distribution<int> distribution(0, A.length()-1);
		for(int i=0; i<someAs.size(); i++)
		{	//int pos1=distribution(generator), pos2=distribution(generator);
			for(int pos1=0; pos1<A.length(); pos1++)
			{	int pos2=A.length()-pos1-1;
				{	swap(someAs[i].second[pos1], someAs[i].second[pos2]);
					int t = compute(someAs[i].second, B, n);
					if(t < baseans)
					{	baseans = t;
						bestA = someAs[i].second;
					}
				}
			}
		}*/
		cout << bestA <<'\n';
	}
}*/