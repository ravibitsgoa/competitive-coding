//This implements naive union-find data structure.
//Merging two nodes is O(N).
#include <iostream>
#include <set>
using namespace std;
int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//num_emp = number of employees
	//num_lang = number of languages.
	int num_emp, num_lang;
	cin>> num_emp >> num_lang;
	
	set<int> lang[num_emp];
	int count[num_lang+1]={0};
	int zeros=0;
	for(int emp=0; emp<num_emp; emp++)
	{	int l;
		cin>>l;
		if(l==0)
			zeros++;
		while(l--)
		{	int name;
			cin>>name;
			lang[emp].insert(name);
			count[name]++;
		}
	}
	
	set<int> node_of_lang[num_lang+1];
	int index[num_lang+1];
	int sections=0;
	for(int i=1; i<=num_lang; i++)
	{	
		if(count[i]==0)
			continue;
		sections++;
		node_of_lang[i] = {i};
		index[i]= i;
	}
	if(sections==0)
	{	cout << num_emp;
		return 0;
	}	
	for(int i=1; i<=num_lang; i++)
	{	
		if(count[i]==0)
			continue;
		for(int emp=0; emp<num_emp; emp++)
		{	if(lang[emp].size()==0)
				continue;
			if(lang[emp].find(i) != lang[emp].end())
			{
				for(int l: lang[emp])
				{
					if(index[l] == index[i])
						continue;
					int smallerOne, biggerOne;
					if(node_of_lang[index[i]].find(l) == node_of_lang[index[i]].end())
					{	if(node_of_lang[index[i]].size()>=node_of_lang[index[l]].size())
						{	smallerOne = index[l];
							biggerOne = index[i];
						}
						else
						{	smallerOne = index[i];
							biggerOne = index[l];
						}
					}
					node_of_lang[biggerOne].insert(node_of_lang[smallerOne].begin(), node_of_lang[smallerOne].end());
					for(int k: node_of_lang[smallerOne])
						index[k] = biggerOne;
					sections--;
				}
			}
		}
	}
	
	cout << sections+ zeros-1;
}