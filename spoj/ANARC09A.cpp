#include <iostream>
using namespace std;
int main()
{
	int testCaseNumber = 1;
	while(!cin.eof())
	{	string str;
		cin>>str;
		if(str[0]=='-')
			break;
		int braces=0, ans=0;
		for(char bracket: str)
		{
			if(bracket == '}')
			{
				if(braces == 0)
				{	braces++;
					ans++;
				}
				else
				{
					braces--;
				}
			}
			else
			{
				braces++;
			}
		}
		ans+= braces/2;
		if(braces % 2 == 1)
			return 1;
		cout << testCaseNumber <<". "<<ans<<'\n';
		testCaseNumber++;
	}
}