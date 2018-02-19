/*#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	int n;
		int a[n];
		for(int i=0; i<n; i++)
			cin>>a[i];
		vector<int> numbers(1e6 + 5, 1);
		vector<int> b;
		b.push_back(1);
		int taken = 2;
		for(int a_i=0; a_i<n; a_i++)
		{
			for(int a_j=0; a_j<n; a_j++)
			{	if((a[a_i] - a[a_j] +1) > 0)
					numbers.at(a[a_i] - a[a_j] +b_num)=0;
			}
		}
		for(int i=1; i<n; i++)
		{	while(numbers.at(taken)==0)
				taken++;
			b.push_back(taken);
			for(int a_i=0; a_i<n; a_i++)
			{
				for(int a_j=0; a_j<n; a_j++)
				{	if((a[a_i] - a[a_j] +b_num) > 0)
						numbers.at(a[a_i] - a[a_j] +b_num)=0;
				}
			}
		}
		
	}
}*/