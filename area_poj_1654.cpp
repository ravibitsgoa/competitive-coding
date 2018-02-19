#include<iostream>
using namespace std;
int main()
{   int n;
    cin>>n;
    while(n--)
    {   string s;
        cin>>s;
        float area=0;
        int i=0, x=0, y=0;
        while(s[i]!='5')
        {   int rx, ry;
            switch(s[i]-'0')
            {   case 1: {rx=-1; ry=-1; break;}
                case 2: {rx=0;  ry=-1; break;}
                case 3: {rx=1;  ry=-1; break;}
                case 4: {rx=-1; ry=0;  break;}
                case 5: {rx=0;  ry=0;  break;}
                case 6: {rx=1;  ry=0;  break;}
                case 7: {rx=-1; ry=1;  break;}
                case 8: {rx=0;  ry=1;  break;}
                case 9: {rx=1;  ry=1;  break;}
            }
            area+=0.5*(rx*y - x*ry);
            x+=rx; y+=ry;
            i++;
        }
        if(area<0) area=-area;
        cout<<area<<endl;
    }
    return 0;
}
