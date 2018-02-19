#include<set>
#include<vector>
#include<map>
#include<iostream>
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
inline void write(int a)
{
	char snum[20];
	int i=0;
	do
	{
		snum[i++]=a%10+48;
		a=a/10;
	}while(a!=0);
	i=i-1;
	while(i>=0)
	putchar_unlocked(snum[i--]);putchar_unlocked(' ');

}
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    fastscan(t);
    while(t--)
    {   int n;
        fastscan(n);
        map<int, int> pl, rev;
        int x;
        for(int i=1; i<=n; i++)
        {   fastscan(x);
            pl[x]=i;
            rev[i]=x;
        }
        int y;
        map<int, vector<int> > adj;
        set<int> S;
        for(int i=1; i<n; i++)
        {   fastscan(x);
            fastscan(y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(map<int, int>::iterator j=pl.begin(); j!=pl.end(); j++)
            S.insert(j->first);
        for(int i=1; i<=n; i++)
        {   int l=adj[i].size();
            for(int k=0; k<l; k++)
            {   S.erase(rev[adj[i][k]]);
            }
            S.erase(rev[i]);
            if(!S.empty())
                write(pl[*S.rbegin()]);
            else
                write(0);
            S.insert(rev[i]);
            for(int k=0; k<l; k++)
                S.insert(rev[adj[i][k]]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}
