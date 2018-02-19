/*#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

typedef unsigned long long ull;
ull next_num_with_same_bit_count(ull x)
{
	//int bits = __builtin_popcountll(x);
	ull flag=1;
	int pos1= -1, pos0= -1;
	for(int i=0; i<=64; i++, flag<<=1)
	{	if((flag&x) && (pos0==-1))
		{	pos1 = i;
		}
		if(!(flag&x) && (pos0==-1) && (pos1!=-1))
		{	pos0 = i;
			x|= flag;	//set this bit on.
			x^= (1ll)<<pos1;	//set the bit with 1, (pos1) off.
			return x;
		}
	}
	assert(0);
}

ull largest_power(ull N)
{
    //changing all right side bits to 1.
	N |= (N>>1);
	N |= (N>>2);
	N |= (N>>4);
	N |= (N>>8);
	//N |= (N>>16);
	//N |= (N>>32);
	
	return (N+1)>>1;
}

ull before(ull power2, int bits)
{	if(bits==1)
		return power2;
	power2--;
	ull flag = 1;
	int extra_bits = __builtin_popcountll(power2) - bits;
	if(extra_bits<=0)
		return power2;
	while(extra_bits--)
	{	power2^= flag;
		flag<<=1;
	}
	return power2;
}

int main()
{
	vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23,
	29, 31, 37, 41, 43, 47, 53, 59, 61};
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{	ull a, b, flag=1;
		cin >> a >> b;
		ull pow2= largest_power(a);
		//cout << pow2 << endl;
		ull ans = 0;
		for(int prime: primes)
		{	ull opt = before(pow2, prime);
			while(opt<a)
			{	opt = next_num_with_same_bit_count(opt);
			}
			while(opt<=b)
			{	ans++;
				opt = next_num_with_same_bit_count(opt);
			}
		}
		cout << ans << '\n';
	}
}*/