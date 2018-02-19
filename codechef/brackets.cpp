#include<iostream>
using namespace std;
int main()
{ int t;
  cin>>t;
  while(t--)
  { string x;
    cin>>x;
    int balance = 0;
		int max_balance = 0, len=x.length();
		for (int index=0;  index<len; index++)
		{	if (x[index] == '(')
        balance ++;
			else
        balance --;
			max_balance = max( max_balance, balance );
		}
    string y(max_balance, '(');
    cout<<y;
    string z(max_balance, ')');
    cout<<z<<'\n';
  }

return 0;
}
