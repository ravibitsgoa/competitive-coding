#include <iostream>
#include <vector>
using namespace std;
#define INF 100000000
#define foreach(v,i) for(i=0;v[i]!='\0';i++)
#define io(v) cin>>v
#define toStr(Result =) "Result ="
//#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
//#error Missing preprocessor definitions
//#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n, i; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}
