def main():
    T=int(raw_input())
    while(T):
        T-=1
        N, Q= raw_input().split()
        N= int(N)
        Q= int(Q)
        x=0
        MOD = 2**N
        seen= []
        count=0
        while(Q):
            Q-=1
            stri=raw_input();
            #print c
            if(stri[0]=='!'):
                print stri
                c,C=stri.split()
                C=int(C)
                #print C
                x = (x+ 2**C)%MOD
                index=1
                y="{0:2}".format(x)
                print y
                #print x
                i=0
                n=len(y)
                #print "n is "
                #print n;
                while(i<n):
                    print index
                    if(index not in seen):
                        count+=1
                        seen.insert(index, 1)
                    index*=2
                    if(y[i]=='1'):
                        index+=1
                    i+=1


            else:
                print(count)
    return 0;

main()
