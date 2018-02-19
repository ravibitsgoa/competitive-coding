#include <bits/stdc++.h>
using namespace std;
int main()
{ 	int n, k;
	cin>>n>>k;
	string x;
	cin>>x;
	int freq[26]={0};
	for(int i=0; i<x.length(); i++)
		freq[x[i]-'a']++;
	int ans=0;
	for(int i=0; i<26; i++)
		if(freq[i]>k)
			ans=1;
	if(ans)
		cout<<"NO";
	else
		cout<<"YES";
	return 0;
}
