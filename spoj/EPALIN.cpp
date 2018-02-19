#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> build_automaton(const string& pattern)
{   
    int m= pattern.length();
    vector<int> automaton(m+1, 0);
    automaton[0] = automaton[1] = 0;    //always true
    
    for(int i = 2; i <= m; i++) 
    {
        // j is the index of the largest next partial match 
        // (the largest suffix/prefix) of the string under  
        // index i - 1
        int j = automaton[i - 1];
        do
        {   
            // check to see if the last character of string i - pattern[i - 1]
            // "expands" the current "candidate"
            // best partial match -> the prefix under index j
            if(pattern[j] == pattern[i - 1]) 
            {   automaton[i] = j + 1; 
                break; 
            }
            // else go to the next best "candidate" partial match
            j = automaton[j];
        } while(j>0);
        // if we cannot "expand" even the empty string, 
        // automaton[i] is by default 0.
    }
    return automaton;
}

int main()
{
	//cin.tie(nullptr);
	//ios_base::sync_with_stdio(false);
	
	string s;
	cin>>s;
		
	while(!cin.eof())
	{
		//s = a.b, we need to find longest palindromic suffix b.
		string s1 = s;
		reverse(s1.begin(), s1.end());
		s1+= "#"+s;
		vector<int> autom = build_automaton(s1);
		int start;
		if(autom[autom.size()-1] != 0)
		{	start = autom[autom.size()-1];
		}
		else
		{
			start = 1;
		}
		for(int i= start; s1[i]!='#'; i++)
		{
			s+= s1[i];
		}
		
		cout << s << '\n';
		
		cin>>s;
	}
}