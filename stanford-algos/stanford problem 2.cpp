//Binary search.
#include<iostream>
using namespace std;
int binsearch(int *p, int i,int e)
{   if(e==i+1) return *(p+i);
    else if((*(p-1+(i+e)/2) < *(p+ (i+e)/2))&&(*(p+(i+e)/2) > *(p + 1+ (i+e)/2)))
        return *(p+(i+e)/2);
    else if(*(p-1+(i+e)/2) < *(p+ (i+e)/2))
        return binsearch(p, (i+e)/2, e);
    else return binsearch(p, i, (i+e)/2);
}
int main()
{   int arr[10]={0,1,2,3,4,5,3,2,1}, *p=&arr[0];
    cout<<binsearch(p, 0, 9);
    return 0;
}
