/*#include <iostream>
#include <map>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	map<string, int> toint = {{"mon",0}, {"tues",1}, {"wed",2}, {"thurs",3}, {"fri",4}, {"sat",5}, {"sun",6}};
	while(t--)
	{	int days;
		cin>>days;
		string first;
		cin>>first;
		int arr[7]={0};
		for(int i=0; i<days; i++)
		{	arr[(i+toint[first])%7]++;			
		}
		for(int i=0; i<7; i++)
			cout << arr[i]<<' ';
		cout << '\n';
	}
}*/