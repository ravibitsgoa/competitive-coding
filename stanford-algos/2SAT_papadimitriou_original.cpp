#include <cstdio>
#include <bitset>
#include <utility>
#include <random>
#include <iostream>

using namespace std;

int main()
{   long long n;
    scanf("%Ld",&n);
    int vars[n];
    //or int vars[n];
    pair<int, int> inp[n];
    for(int i=0; i<n; i++)
    {   scanf("%d %d", &inp[i].first, &inp[i].second);
    }

    int satisfied=0;            //Number of satisfied constraints.
    for(int i=1; i<=n; i<<=1)       //repeat log(2)N times.
    {   //Randomly initialize variables.
        random_device rd;
        mt19937 gen( rd());
        bernoulli_distribution d( 0.5);

        for( int j = 0; j < n; j++)
        {   vars[j] = d(gen);
        }

        for(long long j=0; j<2*n*n; j++)    //long long used to avoid overflow of N^2.
        {   for(int k=0; k<n; k++)
            {   if((inp[k].first>=0) == (vars[inp[k].first]==1))
                    satisfied++;    //first variable satisfies the constraint.
                else if((inp[k].second>=0) == (vars[inp[k].second]==1))
                    satisfied++;    //second variable satisfies the constraint.
                else
                {   //Now, we can say that kth clause is unsatisfied.
                    //Flipping one of the variables randomly.
                    int var_index= d(gen);
                    if(var_index==0)
                        vars[inp[k].first] = !vars[inp[k].first];
                    else
                        vars[inp[k].second] = !vars[inp[k].second];
                    break;
                }
            }
            if(satisfied==n)
                break;
        }
        if(satisfied==n)
            break;
    }
    if(satisfied==n)
    {   //for(int j=0; j<n; j++)
            //printf("%d", vars[j]);
        //These constraints are satisfied.
        printf("satisfied");
    }
    else
        printf("unsatisfiable");
    return 0;
}
