#include <iostream>
using namespace std;
int main()
{	
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{	string s;
		cin>>s;
		int a=0, b=0;
		for(char c: s)
		{	if(c=='a')
				a++;
			else
				b++;
		}
		int x, y;
		cin>>x>>y;
		int ag= a/x, bg= b/y;
		//cout<<ag<<' '<<bg<<endl;
		string ans1, ans2;
		int c1=0, c2=0;
		int acopy= a, bcopy= b;
		string bgroup(y, 'b'), agroup(x, 'a');
		{	int acont=0, bcont=0;
			while(a>b && b>0)
			{	ans1 += "b" + agroup;
				ag--;
				a-=x;
				b--;
				acont=x;
			}
			bg=b/y;
			while(a>bg && ag<=bg && ag>0)
			{	ans1+=bgroup+agroup;
				ag--;
				bg--;
				a-=x;
				b-=y;
				acont=x;
			}
			while(a>0 && bg>0 && b>0)
			{	//ans1+='B';
				ans1+=bgroup+'a';
				a--;
				bg--;
				b-=y;
				acont=1;
			}
			while(b>0)
			{	if(bcont>=y)
				{	ans1+='*';
					c1++;
					bcont=0;
					acont=0;
				}
				ans1+= "b";
				b--;
				bcont++;
				acont=0;
			}
			while(a>0)
			{	if(acont>=x)
				{	ans1+='*';
					c1++;
					bcont=0;
					acont=0;
				}
				ans1+= "a";
				a--;
				acont++;
				bcont=0;
			}
		}
		a = acopy;
		b = bcopy;
		ag=a/x;
		bg=b/y;
		{	int acont=0, bcont=0;
			while(b>a && a>0)
			{	ans2 += "a" + bgroup;
				bg--;
				b-=y;
				a--;
				bcont=y;
				//cout<<1;
			}
			ag=a/x;
			while(b>ag && bg<=ag && bg>0)
			{	ans2 += agroup + bgroup;
				ag--;
				bg--;
				b-=y;
				a-=x;
				bcont=y;
				acont=0;
			}
			while(b>0 && ag>0 && a>0)
			{	ans2 +=agroup+'b';
				b--;
				ag--;
				a-=x;
				bcont=1;
				acont=0;
			}
			while(a>0)
			{	if(acont>=x)
				{	ans2+='*';
					c2++;
					bcont=0;
					acont=0;
				}
				ans2+= "a";
				a--;
				acont++;
				bcont=0;
			}
			while(b>0)
			{	if(bcont>=y)
				{	ans2+='*';
					c2++;
					bcont=0;
					acont=0;					
				}
				ans2+='b';
				b--;
				bcont++;
				acont=0;
			}
		}
		if(c1<=c2)
			cout<<ans1<<'\n';
		else
			cout<<ans2<<'\n';
	}
}