#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	string dir = "udlr";
	sort(dir.begin(), dir.end());
	int n, m;
	cin>>n>>m;
	string mat[n];
	for(int i=0; i<n; i++)
		cin>> mat[i];
	int ans=0;
	string instr;
	cin>>instr;
	do
	{   int i=0, j=0;
		for(int ia=0; ia<n; ia++)
		{	for(int ja=0; ja<m; ja++)
			{	if(mat[ia][ja]=='S')
				{	i=ia;
					j=ja;
					break;
				}
			}
		}
		int pass=1;
		for(char dig: instr)
		{	switch(dir[dig-'0'])
			{	case 'u':	i--; break;
				case 'd':	i++; break;
				case 'l':	j--; break;
				case 'r':	j++; break;		
			}
			if(i<0 || i>=n || j<0 || j>=m || mat[i][j]=='#')
			{	pass=0;
				break;
			}	
			if(mat[i][j]=='E')
			    break;
			
		}
		if(pass && mat[i][j]=='E')
		{	ans++;
			//cout << dir<<endl;
		}
	}
	while(next_permutation(dir.begin(), dir.end()));
	cout << ans;
}
