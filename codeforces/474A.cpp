#include<iostream>
#include<string>
using namespace std;
int main()
{   char x[35]={'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/'};
    char shift;
    cin>>shift;
    string inp;
    cin>>inp;
    for(int j=0; j<inp.length(); j++)
    {   int k;
        for(k=0; k<30; k++)
        {   if(x[k]==inp[j])
                break;
        }
        if(shift=='R')
            cout<<x[k-1];
        else
            cout<<x[k+1];
    }
return 0;
}
