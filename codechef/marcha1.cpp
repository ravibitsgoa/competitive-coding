#include<iostream>
using namespace std;
int main()
{	int t;
	cin>>t;
	while(t--)
	{ 	int n, mugger;
		cin>>n>>mugger;
		int notes[n];
		for(int i=0; i<n; i++)
			cin>>notes[i];
		const int maxindex= 1<<n;
		int index;
		for(index=1; index<=maxindex; index++)
		{ 	int sum=0;
			for(int i=0, mul=1; mul<=index; mul*=2, i++)
				sum+=((index&mul) >> i)*notes[i];
			//cout<<sum<<endl;
			if(sum==mugger)
			{	cout<<"Yes";
				break;
			}
		}
		if(index==maxindex+1)
			cout<<"No";
		cout<<'\n';
	}
  return 0;
}