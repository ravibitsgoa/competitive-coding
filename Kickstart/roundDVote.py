import sys

t=int(raw_input())
for i in range(t):
    i+=1
    print "Case #%d: "%i,
    N,M=map(int,raw_input().split())
    ans=1.0
    for i in range(M+1, M+N+1) :
        ans/=i
    i=N*(N-1)/2
    while(i > (N*(N-1)/2 - M)):
        ans*=i
        i+=1
    print ans
    if(ans>1):
        exit(0)
