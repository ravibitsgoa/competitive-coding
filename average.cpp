#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{   int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
    {   scanf("%d",&a[i]);
    }
    sort(a, a+n);
    long long ans=0;
    for(int i=0; i<n; i++)
    {   if(i>0 && a[i]==a[i-1])
            ans++;
        else if(i<n-1 && a[i]==a[i+1])
            ans++;
        else
        {   int left=i, right=i;
            while(left>=0 && right<n)
            {   if(a[left]+a[right]==2*a[i] && (left!=i || right!=i))
                {   ans++;
                    break;
                }
                if(a[left]+a[right]>2*a[i])
                    left--;
                else if(a[left] + a[right]<2*a[i])
                    right++;
                else
                    left--;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
