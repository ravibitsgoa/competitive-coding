#include<stdio.h>
#include<string.h>
int main()
{ char inp[11]="";
  scanf("%s",inp);
  int flag=0;
  for(int i=0; i<strlen(inp) && !flag; )
  { //printf("%d",i);
    if(inp[i]=='1' && inp[i+1]=='4' && inp[i+2]=='4')
    {i+=3;}
    else if(inp[i]=='1' && inp[i+1]=='4')
    {i+=2;}
    else if(inp[i]=='1')
    {i++;}
    else
    {flag=1; break;}
  }
  if(flag)
    printf("NO");
  else
    printf("YES");
return 0;
}
