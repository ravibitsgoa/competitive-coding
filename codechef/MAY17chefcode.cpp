#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(auto i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define inf (1<<30)
#define eps 1e-9
typedef long long i64;
typedef unsigned long long ui64;
static struct IO
{
	char tmp[1 << 10];

	// fast input routines
	char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }

	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }

	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)

	// fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

defineOutFor(int)
defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
int main()
{ int n, k;
	cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	int product[n], number[n];
	product[0]=a[0];
	number[0]=1;
	for(int j=1; j<n; j++)
	{	int m=-1, n=0, pro=1;x
		for(int i=0; i<j; i++)
		{	if((m<0 || number[i]>number[m]) && product[i]*a[j]<=k)
				m=i;
			else if(number[i]==number[m] && product[i]*a[j]<=k)
			{	n+=number[m]+number[i];
				pro*=max(product[m], product[i]);
			}
		}
		cout<<m<<n<<endl;
		if(m!=-1 && (n<number[m]))
		{	number[j]=number[m]+1;
			product[j]=product[m]*a[j];
		}
		else if(n!=0 && pro*a[j]<=k)
		{	number[j]=n+1;
			product[j]=pro*a[j];
		}
		else if(a[j]<=k)
		{	number[j]=1;
			product[j]=a[j];
		}
		else if(a[j]>k)
		{	number[j]=0;
			product[j]=1;
		}
	}
	int ans=0;
	for(int i=0; i<n; i++)
	{	cout<<number[i]<<' '<<product[i]<<endl;
		ans+=number[i];
	}*/
	cout<<ans;
	return 0;
}
