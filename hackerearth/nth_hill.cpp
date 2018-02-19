#include <iostream>
using namespace std;

int main()
{	int t, n, m;
	cin>>t;
	while(t--)
 	{	cin>>n>>m;
 		int x=0, i, j;
 		int last=0, first=0;
 		while(m--)
 		{	cin>>i>>j;
 			x+=j-i;
 			if(i==n || j==n){last++;}
 			else if(i==1 || j==1){first++;}
 		}
 		if(x==0 && last==2 && first==2)
 		{	cout<<"Possible!!"<<endl;
 		}
 		else{ cout<<"Danger!!"<<endl;

 		}
 	}
    return 0;
}
