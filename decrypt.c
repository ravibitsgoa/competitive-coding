#include<stdio.h>
int main()
{   char arr[150]="ITRSB NMRHC DQSGD SNOLN RSZMC ANSSN LLNRS ONHMS ENQDZ BGWZM CHFMN QDONH MSRHM ADSVD DM";
    for(int i=0; arr[i]>0; i++)
    {   if(arr[i]==' ')printf(" ");
        else printf("%c",64+ (arr[i]-64+1)%64);
    }
    return 0;
}
