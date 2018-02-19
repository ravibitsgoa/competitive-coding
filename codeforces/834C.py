def third(num, i, j):
    if(i>j or j>num):
        exit(1);
    if(j==i):
        return i;
    if(i==j-1 and i*i*i==num):
        return i;
    else:
        if(i==j-1 ):
            return j;
    mid=(i+j)/2;
    if(mid*mid*mid == num):
        return mid;
    if(mid*mid*mid < num):
        return third(num, mid, j);
    else:
        return third(num, i, mid);

def main():
    n=int(raw_input());
    while(n>0):
        n-=1
        (a,b)=map(int, raw_input().split());
        pro=a*b;
        x=third(pro, 1, pro);
        a/=x;
        b/=x;
        if(a*b == x and x*x*x==pro):
            print("Yes")
        else:
            print("No");
main()
