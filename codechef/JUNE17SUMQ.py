MOD=1000000007
import sys
def main ():
  num_case=0
  num_case=input()
  while(num_case>0):
    num_case-=1;
    #p, q, r, ix, iy, iz;
    (p,q,r)=map(int,raw_input().strip().split(" "));
    x=map(int,raw_input().strip().split(" "));
    y=map(int,raw_input().strip().split(" "));
    z=map(int,raw_input().strip().split(" "));
    x.sort();
    y.sort();
    z.sort();
    ans=0;
    sumx=0; sumz=0;
    ix=0; iz=0;
    for iy in range(0,q):
      while(ix<p):
        if(x[ix]>y[iy]):
          break;
        sumx+=x[ix];
        ix+=1;
      while(iz<r):
        if(z[iz]>y[iy]):
          break;
        sumz+=z[iz];
        iz+=1;
      ans += (sumx + ix*y[iy])*(iz*y[iy] + sumz);
      if(ans<0):
        return 1;
    print(ans%MOD);
  return 0;
main()
