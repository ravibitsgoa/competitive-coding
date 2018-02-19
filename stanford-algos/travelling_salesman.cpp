#include <algorithm>    //for std::next_permutation
#include <cmath>        //for std::sqrt
#include <iostream>     //for std::cin, std::cout
#include <utility>      //for std::pair<,>
#include <vector>       //for std::vector<>
using namespace std;

const int INF = 1e9;    //max distance between any two cities.

//returns distance between city i and j.
double dist(const pair<double, double> &i, const pair<double, double> & j)
{   double x = (i.first-j.first)*(i.first-j.first);
    x += (i.second-j.second)*(i.second-j.second);
    return sqrt(x);
}

int main()
{   int n;
    cin>>n;

    const long long SIZE=1<<(n-1);                          //SIZE = number of subsets possible.
    vector<vector<double> > A(SIZE, vector<double>(n-1));   //A[subset bitmasked][city index].

    vector<pair<double, double> > cities(n-1);  //Coordinates of cities.
    pair<double, double> initial;               //Coordinates of the first city. (can be any one of them)

    cin>>initial.first>>initial.second;
    for(int i=0; i<n-1; i++)
        cin>>cities[i].first>>cities[i].second;
    //Input complete.

    for(int m=2; m<=n; m++) //m= number of cities taken in the subset.
    {   cout<<m<<endl;      //Whenever subset-size changes, print it. Just to keep track.
        char arr[n-1];      //Declare a string of n-1 character with 1 if that city is included.
        for(int i=0; i<n-m; i++)    arr[i]='0';
        for(int i=0; i<m-1; i++)    arr[n-m+i]='1';
        arr[n-1]=0;
        //city 1 is always taken, and other m-1 cities are taken, out of n cities.
        //We're just generating an initial permutation of selected cities.

        //Iterate through all possible subsets of size m:
        do
        {
            int s=0;    //Find integer corresponding to current subset-bitmask.
            for(int i=0; i<n-1; i++)
            {   s<<=1;
                s+=arr[i]-'0';
            }
            //cout<<s<<' '<<arr<<'\n';
            for(int j=0; j<n-1; j++)
            {   A.at(s).at(j)=INF;
                if(s & (1<<j))    //If (j+1)th city has been taken.
                {   //cout<<j<<endl;
                    for(int k=0; k<n-1; k++)
                    {   if((s & (1<<k)) && k!=j)    //If (k+1)th city is also taken, apart from (j+1)
                        {   A.at(s).at(j)= min(A.at(s).at(j), A.at(s-(1<<j)).at(k) + dist(cities[k], cities[j]) );
                            //If we have a shorter path 1->..->k with exactly 1 less hop, we can go 1->..->k->j.
                        }
                    }
                    if(m==2)
                        A.at(s).at(j)= min(A.at(s).at(j), dist(cities[j], initial) );
                    //cout<<endl;
                }
            }
        }
        while(next_permutation(arr, arr+n-1));  //To generate all permutations of size m.
    }
    double ans=INF;
    for(int j=0; j<n-1; j++)
    {   ans=min (ans, A[SIZE-1][j] + dist(cities[j], initial) );
    }
    cout<<ans<<endl;
    return 0;
}
