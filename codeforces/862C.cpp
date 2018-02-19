/*#include<iostream>
using namespace std;
int main()
{
	string inp;
	cin>>inp;
	int conso=0;
	bool same=1;
	for(size_t i=0; i<inp.length(); i++)
	{	char c= inp[i];
		if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u')
		{	conso++;
		}
		else
		{	conso=0;
			same =1;
		}
		if(conso<3)
			cout<<c;
		else
		{	if(conso >= 3 && (inp[i]!=inp[i-1] || inp[i]!=inp[i-2] || inp[i-1]!=inp[i-2]))
				same=0;
			if(!same)
			{	cout<<' '<<c;
				same=1;
			}
			else
				cout<<c;
			//conso=1;
		}
	}
}*/