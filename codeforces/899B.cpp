/*#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int d[50];
	d[0]=31;
	d[1]=28;
	d[2]=31;
	d[3]=30;
	d[4]=31;
	d[5]=30;
	d[6]=d[7]=31;
	d[8]=30;
	d[9]=31;
	d[10]=30;
	d[11]=31;
	for(int j=1; j<4; j++)
	{	for(int i=0; i<12; i++)
		{	if(i!=1)
				d[i+j*12] = d[i];
			else if(i==1 && j!=3)
				d[i+j*12] = d[i];
			else
				d[i+j*12] = 29;
		}
	}
	
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
		cin>>a[i];
	for(int i=0, j=0; i<48; i++)
	{	int icopy= i;
		while(j!=n && a[j]==d[i])
		{	i++; j++;
			i%=48;
		}
		if(j==n)
		{	cout << "YES";
			return 0;
		}
		j=0;
		i=icopy;
	}
	cout << "NO";
}*/