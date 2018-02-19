#include<iostream>
using namespace std;
#define x first
#define y second

long long distSq(pair<long long, long long> p, pair<long long, long long>q)
{
	return (p.x - q.x)*(p.x-q.x) + (p.y - q.y)*(p.y - q.y);
}

int main()
{
	pair<long long, long long> a, b, c;
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
	if((2*b.x == a.x + c.x) && (2*b.y == a.y + c.y))
		cout<<"No";
	else if(distSq(a, b) == distSq(b, c))
		if(distSq(a, b)*distSq(a, b) == 
		(
		(b.x*b.x - b.y*b.y -a.x*b.x +a.y*b.y -b.x*c.x + b.y*c.y + a.x*c.x - a.y*c.y)*(b.x*b.x - b.y*b.y -a.x*b.x +a.y*b.y -b.x*c.x + b.y*c.y + a.x*c.x - a.y*c.y)
 +(2*b.x*b.y - a.y*b.x - a.x*b.y -b.y*c.x - b.x*c.y + a.y*c.x + a.x*c.y)*(2*b.x*b.y - a.y*b.x - a.x*b.y -b.y*c.x - b.x*c.y + a.y*c.x + a.x*c.y)) )
		cout<<"Yes";
		else
			cout<<"No";
	else
		cout<<"No";
	return 0;
}