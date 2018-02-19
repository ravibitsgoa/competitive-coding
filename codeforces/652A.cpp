#include <iostream>
using namespace std;
int main()
{
	int h1, h2;
	cin >> h1 >> h2;
	int a, b;
	cin >> a >> b;
	h1 += a*8;
	if(h1>=h2)
		cout << 0;
	else
	{	if(a<=b)
		{	cout << -1;
			return 0;
		}
		for(int i=1; 1; i++)
		{	//cout << i;
			h1 -= 12*b;
			h1 += a*12;
			if(h1 >= h2)
			{	cout << i;
				return 0;
			}
		}
	}
}