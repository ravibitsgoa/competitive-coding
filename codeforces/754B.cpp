#include<stdio.h>
int main()
{   char game[4][4];
    int flag=0;
    scanf("%s%s%s%s",game[0],game[1],game[2],game[3]);
    for(int i=0; i<4 && flag==0; i++)
    {   for(int j=0; j<4 && flag==0; j++)
        {   if(game[i][j]=='x')
            {   if(i<2 && game[i+1][j]!='o' && game[i+2][j]!='o' && (game[i+1][j]=='x' || game[i+2][j]=='x'))
                {   flag=1; break;}
                if(i>0 && i<3 && game[i+1][j]!='o' && game[i-1][j]!='o' && (game[i+1][j]=='x' || game[i-1][j]=='x'))
                {   flag=1; break;}

                if(j<2 && game[i][j+1]!='o' && game[i][j+2]!='o' && (game[i][j+1]=='x' || game[i][j+2]=='x'))
                {   flag=1; break;}
                if(j>0 && j<3 && game[i][j+1]!='o' && game[i][j-1]!='o' && (game[i][j+1]=='x' || game[i][j-1]=='x'))
                {   flag=1; break;}

                if(i<2 && j<2 && game[i+1][j+1]!='o' && game[i+2][j+2]!='o' && (game[i+1][j+1]=='x' || game[i+2][j+2]=='x'))
                {   flag=1; break;}
                if(i>0 && j>0 && i<3 && j<3 && game[i+1][j+1]!='o' && game[i-1][j-1]!='o' && (game[i+1][j+1]=='x' || game[i-1][j-1]=='x'))
                {   flag=1; break;}

            }
        }
    }
    if(flag)
        printf("YES");
    else
        printf("NO");
    return 0;
}
