a,b,c = map(int, input().split())
done = 0
for i in range(1, 1000000):
    if(c == ((10*(a %b)/b) %10)):
        print (i)
        done =1
        break
    a = (10*a)%b
if(done == 0):
    print (-1)
