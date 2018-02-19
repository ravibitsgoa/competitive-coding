#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {   char jew[100], sto[100];
        int i, c, l1, l2, k;
        cin>>jew>>sto;
        l1=strlen(jew);
        l2=strlen(sto);
        sort(jew, jew+l1);
        sort(sto, sto+l2);
        c=0;
        for(i=0, k=0; k<l1 && i<l2;)
        {   if(jew[k]==sto[i])
            {   c++;
                i++;
            }
            else
            {   if(jew[k]>sto[i])
                {   i++;
                }
                else{k++;}
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
