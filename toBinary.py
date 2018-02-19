def main():
    x = 1.0/7.0
    ans = ""
    for i in range(64):
        if(int(x) &1):
            #print "%d"%1,
            ans += "1"
        else:
            #print "%d"%0,
            ans += "0"
        x*=2
    print ans
    
    
main()
