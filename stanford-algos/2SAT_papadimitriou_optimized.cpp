/* optimization: If a variable appears only as 1 or only as a 0 for all clauses,
we can stop dealing with it.
e.g. If there is no clause with +230, but there are many with -230, we can conclude
that variable230 must be 0.
*/
#include <cstdio>
#include <utility>
#include <random>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;

int abs(int x)
{   if(x<0) return -x;
    return x;
}

int main()
{   long long n;
    scanf("%Ld",&n);
    vector<int> vars(n+1);
    pair<int, int> inp[n];  //Set of all constraints
    set<pair<int, int> > ambiguous;     //set of ambiguous constraints.
    for(int i=0; i<n; i++)
        vars[i]=-1;

    for(int i=0; i<n; i++)
    {   scanf("%d %d", &inp[i].first, &inp[i].second);
        if(vars.at(abs(inp[i].first)) == -1)     //Set the first variable to the required value, if seen for the first time.
        {   if(inp[i].first>=0)
                vars.at(inp[i].first) = 1;
            else
                vars.at(-inp[i].first) = 0;
        }
        else
        {   if((inp[i].first<0) && vars.at(-inp[i].first) ==1)
                vars.at(abs(inp[i].first)) = 2;     //If this constraint is creating a conflict with a previous value.
            else if ((inp[i].first>=0) && vars.at(inp[i].first) ==0)
                vars.at(abs(inp[i].first)) = 2;     //If this constraint is creating a conflict with a previous value.
        }
        if(vars.at(abs(inp[i].second)) == -1)    //Set the second variable to the required value, if seen for the first time.
        {   if(inp[i].second>=0)
                vars.at(inp[i].second) = 1;
            else
                vars.at(-inp[i].second) = 0;
        }
        else
        {   if( (inp[i].second<0) && vars.at(-inp[i].second) ==1 )
                vars.at(abs(inp[i].second)) = 2;     //If this constraint is creating a conflict with a previous value.
            else if( (inp[i].second>=0) && vars.at(inp[i].second) ==0 )
                vars.at(abs(inp[i].second)) = 2;     //If this constraint is creating a conflict with a previous value.
        }
    }
    for(int i=0; i<n; i++)
    {   if(vars.at(abs(inp[i].first))==2 && vars.at(abs(inp[i].second))==2)
        {   ambiguous.insert(inp[i]);
        }
        //If both variables of this constraint are ambiguous, add this to the array.
        //If at least one of them is already satisfied, then we need not worry (because it's OR operation.)
    }
    //cout<<ambiguous.size()<<'\n';
    //for(auto i=ambiguous.begin(); i!=ambiguous.end(); i++)
        //cout<<(i->first)<<' '<<(i->second)<<'\n';
    //for(int i=0; i<n; i++)
        //cout<<i<<' '<<vars[i]<<'\n';

    int satisfied=0;            //Number of satisfied constraints.
    long long sz= ambiguous.size();
    //cout<<sz;
    for(int i=1; i<=sz; i<<=1)       //repeat log(2)N times.
    {   //Randomly initialize variables.
        random_device rd;
        mt19937 gen( rd());
        bernoulli_distribution d( 0.5);

        for( auto j = ambiguous.begin(); j != ambiguous.end(); j++)
        {   vars.at(abs(j->first)) = d(gen);
            vars.at(abs(j->second)) = d(gen);
        }

        for(long long j=0; j<2*sz*sz; j++)    //long long used to avoid overflow of N^2.
        {   int checked[n]={0};
            for(auto k=ambiguous.begin(); k != ambiguous.end(); k++)
            {   if( k->first < INF && !checked[abs(k->first)] && ((k->first>=0) == (vars.at(abs(k->first))==1)))
                {   satisfied++;    //first variable satisfies the constraint.
                    checked[abs(k->first)]=1;
                }
                else if( k->second < INF && !checked[abs(k->second)] && ((k->second>=0) == (vars.at(abs(k->second))==1)))
                {   satisfied++;    //second variable satisfies the constraint.
                    checked[abs(k->second)]=1;
                }
                else
                {   //Now, we can say that kth clause is unsatisfied.
                    //Flipping one of the variables randomly.
                    int var_index= d(gen);
                    if(var_index==0)
                        vars.at(abs(k->first)) = !vars.at(abs(k->first));
                    else
                        vars.at(abs(k->second)) = !vars.at(abs(k->second));
                    break;
                }
            }
            if(satisfied==sz)
                break;
        }
        if(satisfied==sz)
            break;
    }
    if(satisfied==sz)
    {   //These constraints are satisfied.
        printf("satisfied");
    }
    else
        printf("unsatisfiable");
    return 0;
}
