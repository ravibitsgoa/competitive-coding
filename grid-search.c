#include<stdio.h>
int main()
{   int t;
    scanf("%d",&t);
    while(t--)
    {   int R, C;
        scanf("%d %d",&R,&C);
        char grid[R][C];
        for(int i=0; i<R; i++)
        {   scanf("%s",grid[i]);
        }
        int r, c;
        scanf("%d %d",&r,&c);
        char pat[r][c];
        for(int i=0; i<r; i++)
        {   scanf("%s",pat[i]);
        }
        int a=0, b=0, i0, j0, flag=0;
        for(int i=0; i<R && flag!=1; i++)
        {   for(int j=0; j<C && flag!=1; j++)
            {   a=b=0;
                if(grid[i][j]==pat[0][0])
                {   i0=i; j0=j;
                    //printf("%d %d",i0,j0);
                }
                while(grid[i][j]==pat[a][b] && j<C && b<c && i<R && a<r)
                {   //printf("%d %d a\n",i,j);
                    j++;
                    b++;
                    if(b==c && grid[i+1][j0]==pat[a+1][0])
                    {   i++;    a++;
                        j=j0;   b=0;
                    }
                    else if(b==c) break;
                    flag=-1;
                }
                if(b==c && a==r-1)
                {   printf("YES\n");
                    flag=1;
                }
                else if(i>i0 && flag==-1)
                {   i=i0;
                    j=j0;
                    flag=0;
                }
                //printf("%d %d\n",i,j);
            }
        }
        if(flag!=1)
            printf("NO\n");
    }
return 0;
}
