from decimal import *
import sys;
from sys import *
#A solution to Euler sum published in June long challenge 2017.
getcontext().prec = 400;
e =Decimal(1);
nforexp=1;
i = Decimal(1);
for i in range(1, 1500):
  nforexp*=i;
  e+=Decimal(1)/nforexp;
#print e;
def sume(n):
  ans=(n*(n+1)/2);
  x=Decimal(e-1);
  sgn=1;
  #count=0;
  while(1):
    #count+=1;
    if(n==0):
      break;
    if(n==1):
      ans += sgn;
      break;
    m = int(n*(x-1));
    a = (n+m)*(n+m+1)/2;
    n = m;
    ans += int(sgn*a);
    sgn*=-1;
    x = 1/(1-1/x);
    while(x>2):
      ans += sgn*n*(n+1)/2;
      x -= 1;

  #print count;

  stdout.write(str(ans));
def main():
  n=int(sys.stdin.readline());
  sume(n);
  return 0;

main();
