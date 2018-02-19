#include<iostream>
using namespace std;
int main()
{   char s;
    int i=0, sum, fre[27]={0};
    while(s!=125)
    {   cin>>s;
        if(s>=97 && s<=97+25)
        {   fre[s-97]++;
        }
    }
    sum=0;
    for(i=0; i<26; i++)
    {   if(fre[i])
        sum++;
    }
    cout<<sum;
    return 0;
}
