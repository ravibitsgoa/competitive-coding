def main():
    n = int(raw_input())
    x = raw_input().split()
    print x
    for i in range(len(x)):
        print x[i]+"*x^"+str(i)+" +",
main()
