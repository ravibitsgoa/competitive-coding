#include <cstdio>
void foo()
{   char c='+', x[2000]="";
    int i=0, flag=0;
    c=getchar();
    while(c!='\n' && c!=EOF)
    {   x[i]=c;
        if(x[i]=='(' || x[i]=='[' || x[i]=='{')
            i++;
        else if(i>0)
        {   if(x[i]==')' && x[i-1]=='(')
                i--;
            else if(x[i]==']' && x[i-1]=='[')
                i--;            
            else if(x[i]=='}' && x[i-1]=='{')
                i--;
            else
                flag=1;
        }	
        else 
            flag=1;
        c=getchar();
    }
    if(i==0 && flag==0)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{   int t;
    scanf("%d",&t);
    char c=getchar();
    while(t--)
    {   foo();
    }    
    return 0;
}//This implements stack.
