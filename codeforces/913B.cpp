/*#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int p[n+1];
	vector<int> children[n+1];
	for(int i=1; i<n; i++)
	{	cin >> p[i];
		children[p[i]].push_back(i+1);
	}
	bool is_spruce=true;
	for(int i=1; i<=n; i++)
	{	int count =0;
		//cout << i << ' ';
		for(int child : children[i])
		{	//cout << child << ' ';
			if(children[child].size()==0)
				count++;
		}
		//cout << endl;
		if(count == 1 || count == 2 || (count == 0 && children[i].size()))
			is_spruce = false;
	}
	if(is_spruce)
		cout << "Yes";
	else
		cout << "No";
}*/