/*#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstring>
using namespace std;
bool ends_with(std::string const & value, std::string const & suffix)
{
    size_t valueSize = value.size();
    size_t suffixSize = suffix.size();

    if (suffixSize > valueSize)
    {
        return false;
    }

    const char * valuePtr = value.data() + valueSize - suffixSize;

    return memcmp(valuePtr, suffix.data(), suffixSize) == 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	string names[n];
	map<string, vector<string> > cont;
	for(int i=0; i<n; i++)
	{	cin>>names[i];
		int x;
		cin>>x;
		while(x--)
		{	string t;
			cin>>t;
			cont[names[i]].push_back(t);
		}
	}
	cout << cont.size()<<'\n';
	for(auto iter: cont)
	{	cout << iter.first << ' ';
		for(int a=0; a<iter.second.size(); a++)
		{	for(int j=0; j<iter.second.size(); j++)
			{	string s= iter.second[a];
				string x= iter.second[j];
				/*if(s!=x && s.length()>x.length())
				{	bool hmm=0;
					for(int xiter=x.length()-1, siter=s.length()-1; siter>=0 && xiter>=0; xiter--, siter--)
					{
						if(x[xiter]!=s[siter])
						{	hmm=1;
							break;
						}
					}
					if(!hmm)
					{	cont[names[i]].erase(cont[names[i]].begin() + j);					
					}
				}*/
				/*if(s!=x && ends_with(s, x))
				{	iter.second.erase(iter.second.begin()+j);
					a=-1;j=-1;
					break;
				}
			}
		}
		set<string> temp(iter.second.begin(), iter.second.end());
		vector<string> newvec(temp.begin(), temp.end());
		iter.second= newvec;
		
		cout << iter.second.size()<<' ';
		for(auto x: iter.second)
			cout << x<<' ';
		cout <<'\n';
	}
}*/