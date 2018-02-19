import sys
import random
def main():
     r=int(sys.argv[1])
     c=int(sys.argv[2])
     d=int(sys.argv[3])
     #r=4
     #c=4
     #d=2
     print "%d %d %d"%(r,c,d)
     for i in range(r):
         for j in range(c):
             print 1, #random.randint(0,1),
         print ""     

main()
