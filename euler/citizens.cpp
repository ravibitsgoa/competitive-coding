#include <iostream>
using namespace std;
const int MAX = 100000000;
int phi[MAX];
int main()
{   
    for(int i=1; i<MAX; i++)
		phi[i]=i;

	for(int i=2; i<MAX; i++)
	{	if(phi[i]==i)
		{	// This condition guarantees that i is prime since it was not modified by any number <i.
			for(int j=i; j<MAX; j+=i)
				phi[j]-=(phi[j]/i);		// In this step we multiply (1-1/i) to each multiple of i, since it would be a prime factor in factorisation of all its multiples.
		}
	}
	
    long long mx=0, count=0;
    long long sum=0, n=0;
    for(int i=1; i<MAX; i++)
    {   
        if(mx < phi[i])
        {   
            count++;
            mx = phi[i];
            n=i;
            //if(count<10)
            //    cout << i<< ' '<< phi[i]<<endl;
            //if(count == 100000)
            //    cout << "ans: "<<i<<endl;
        }
    }
    cout << count << ' ' << n <<endl;
}
