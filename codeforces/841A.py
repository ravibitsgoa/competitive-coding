n,k =raw_input().split()
n=int(n)
k=int(k)
s = raw_input()
print s
print len(set(s))
if(len(set(s)) <k):
    print "NO"
else:
    print "YES"
