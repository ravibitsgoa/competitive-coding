def main():
    T = int(raw_input())
    while(T):
        T-=1
        N, K= map(int, raw_input().split())
        ans=0
        for i in range(64) :
            if K & (1<<i) :
                ans+=1<<(N-i-1);
        print ans

main()
