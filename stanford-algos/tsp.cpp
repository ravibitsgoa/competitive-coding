/*=============================================================================
#     FileName: GT-TSP-DP.cpp
#         Desc: Traveling Salesman Problem - DP solution
#       Author: KuoE0
#        Email: kuoe0.tw@gmail.com
#     HomePage: http://kuoe0.ch/
#      Version: 0.0.1
#   LastChange: 2012-10-11 20:59:01
#      History:
=============================================================================*/
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int NMAX = 25;
int n, src;
vector< vector< double > > graph, dp;
pair<double, double> cities[NMAX+1];

// initial status
void init()
{	for ( int i = 0; i < n; ++i )
		dp[ 1ll << i ][ i ] = graph[ src ][ i ];
}
// TSP recursive
double TSP( int status, int x )
{	if ( dp[ status ][ x ] != -1 )
		return dp[ status ][ x ];

	long long mask = 1ll << x;
	dp[ status ][ x ] = 1e9;
	for ( int i = 0; i < n; ++i )
		if ( i != x && ( status & ( 1 << i ) ) )
			dp[ status ][ x ] = min( dp[ status ][ x ], TSP( status - mask, i ) + graph[ i ][ x ] );
	return dp[ status ][ x ];
}

double dist(int i, int j)
{   double x = (cities[i].first-cities[j].first)*(cities[i].first-cities[j].first);
    x += (cities[i].second-cities[j].second)*(cities[i].second-cities[j].second);
    return sqrt(x);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
        scanf("%lf %lf", &cities[i].first, &cities[i].second);
	//printf("%lld",1ll<<n);
	src=1;
	graph = vector< vector< double > >( n, vector< double >( n ) );
	dp = vector< vector< double > >( 1ll << n, vector< double >( n, -1 ) );
	for ( int i = 0; i < n; ++i )
	{	for ( int j = 0; j < n; ++j )
		{	graph[ i ][ j ] = dist(i, j);
		}
	}
	init();
	printf( "%d\n", (int)TSP( ( 1ll << n ) - 1, src ) );
	return 0;
}
