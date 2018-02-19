t= int(raw_input())
for i in range(t):
    n, p, q = map(int, raw_input().split())
    arr = map(int, raw_input().split())
    b = map(int, raw_input().split())
    prod = [0]*n
    for i in range(n):
        if( i>0 ):
            prod[i]= prod[i-1]*arr[i]
        else:
            prod[i] = arr[i]
        
    x = 0
    for j in range(q):
        if(j%64 ==0):
            l= (b[j/64] + x)%n
            r= (b[(j/64) +1]+ x)%n
        else:
            l= (l + x)%n
            r= (r + x)%n
        if(l > r):
            l,r = r,l
        if(l==0):
            x= (prod[r]+1)%p
        else:
            x= (prod[r]/prod[l-1] +1)%p
    
    print x%p
