#this is incomplete.
def main():
{ primes=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]
  good={}
  good[1]=1
  for(i in range(1005)):
    if(i<2) continue
    x=0
    for(j in primes):
      if(i % (j*j) ==0):
        good[i]=0;
        x=1;
        break;
    if(x==0):
      good[i]=1;

  T=int(raw_input());
  while(T--)
  { int N;
    cin>>N;
    int A[N];
    for(int i=0; i<N; i++)
      cin>>A[i];
    vector<int>chunks;
    int sz=0;
    for(int i=0; i<N; i++)
    { if(good[A[i]])
        sz++;
      else
      { chunks.push_back(sz);
        sz=0;
      }
    }

  }
  return 0;
}
main()
