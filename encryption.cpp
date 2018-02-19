#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int rowcol(int &r, int &c, int l)
{   double len=sqrt((double)l);
    c=r=len;
    if(r*c>=l)
    {}
    else if(r*(c+1)>=l)
    {   c++;
    }
    else
    {   r++;
        c++;
    }
    return 0;
}
int main()
{   char inp[90];
    scanf("%s",inp);
    int l=strlen(inp),Row,Col;
    rowcol(Row,Col,l);
    for(int i=0; i<Col; i++)
    {   for(int j=0; (i+j)<l; j+=Col)
            printf("%c",inp[i+j]);
        printf(" ");
    }
return 0;
}
