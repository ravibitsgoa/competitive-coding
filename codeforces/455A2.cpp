#include<iostream>
#include<map>
#define MAXN 100000
using namespace std;
int main()
{ long long n;
  cin>>n;
  long long inp[n];
  long long freq[MAXN + 5]={0}, maxsum[MAXN +5]={0};
  long long maximum=0, minimum=MAXN +5;
  //map<int,int>freq;
  for(int i=0; i<n; i++)
  { cin>>inp[i];
    freq[inp[i]]++;
    maximum=max(maximum, inp[i]);
    minimum=min(minimum, inp[i]);
  }
  long long i=maximum, sum=0;//std::map<int, int>::iterator
  for(;i>=minimum; i--)
  { freq[i]*=i;
    if(freq[i]>0)
      maxsum[i]=freq[i]+max(maxsum[i+2], maxsum[i+3]);
    else
      maxsum[i]=max(maxsum[i+1], maxsum[i+2]);
  }
  cout<<max(maxsum[i+1], maxsum[i+2]);
return 0;
}
