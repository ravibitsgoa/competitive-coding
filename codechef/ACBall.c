#include<stdlib.h>
#include<stdio.h>
int main()
{ int t;
  scanf("%d",&t);
  while(t--)
  { //char *a=malloc(sizeof(char)*100000);
    char a[100000],b[100000];
    scanf("%s",a);
    //char *b=(char*)malloc(sizeof(char)*100000);
    scanf("%s",b);
    for(int i=0; a[i]!='\0'; i++)//or i<strlen(a)
    { if(a[i]==b[i])
      { if(a[i]=='W')
          printf("B");
        else
          printf("W");
      }
      else
        printf("B");
    }
    printf("\n");
  }
return 0;
}
