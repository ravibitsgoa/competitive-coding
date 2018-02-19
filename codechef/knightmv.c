#include<iostream>
#include<cmath>
#include<algorithm>
#include<limits>
#include<vector>
#include<bitset>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<time.h>
#include<map>
using namespace std;
#define MOD 1000000007LL
#define LL long long
#define ULL unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x)   ((x)<0?-(x):(x))
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%ld",&n)
#define sll(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")//print new line
#define REP(i,n) for(int i=0;i<(n);i++)//repeat n times
#define FOR(i,a,b) for(int i=(a);i<(b);i++)//end not included
#define FORR(i,n) for(int i=(n);i>=0;i--)//reverse for
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";//debugging
#define CL(a,b) memset(a,b,sizeof(a))
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int *a,int *b){int temp;temp=*a;*a=*b;*b=temp;}
ULL gcd(ULL a,ULL b){if(a==0)return b;if(b==0)return a;if(a==1||b==1)return 1;if(a==b)return a;if(a>b)return gcd(b,a%b);else return gcd(a,b%a);}

void precompute(){}//end precompute
void refresh(){}//end refresh

void doThis(){
    char line[15];
	int diffx,diffy;
		gets(line);
		if(((line[0]>='a') && (line[0]<='h')) && ((line[1]>='1') && (line[1]<='8')) && (line[2]=='-') && ((line[3]>='a') && (line[3]<='h')) && ((line[4]>='1') && (line[4]<='8')) && (line[5]=='\0'))
		{
			diffx=line[3]-line[0];
			diffy=line[4]-line[1];
			if(diffx<0)
				diffx*=-1;
			if(diffy<0)
				diffy*=-1;
			if(((diffx==2) && (diffy==1)) || ((diffx==1) && (diffy==2)))
				puts("Yes");
			else
				puts("No");
		}
		else
			puts("Error");
}

int main(){
#ifdef amy
freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("log.txt", "w", stderr);
#endif
int t;precompute();
t=1;
scanf("%d",&t);getchar ();
while(t--){doThis();}//end while
#ifdef amy
fprintf(stdout,"\nTIME: %.3lf sec\n", (double)clock()/(CLOCKS_PER_SEC));
#endif
return 0;
}//end main
 
