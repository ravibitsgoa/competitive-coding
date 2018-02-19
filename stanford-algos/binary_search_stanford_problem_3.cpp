//Binary search.
#include<iostream>
using namespace std;
int src(int *p, int i, int e)
{   if(*(p+(i+e)/2)==(i+e)/2)
        return *(p+(i+e)/2);
    else if(e==i+1)
        return -1;
    else if(*(p+(i+e)/2)<(i+e)/2)
        return src(p, 1+(i+e)/2, e);
    else
        return src(p, i, (i+e)/2);
}
int main()
{   int arr[10]={-3,-2,-1,0,1,4,6,7}, *p=&arr[0];
    cout<<src(p, 0 ,8);//-1 will denote that such number is not found.
    return 0;
}
