import random
import itertools

def randomString(mxlen):
    n = random.randint(mxlen-1, mxlen+1)
    #n = mxlen
    randomString="";
    for i in range(n):
        x= chr(random.randint(97, 122))
        randomString += x
    return randomString


def permuations(string_output, number):
    for perm in itertools.permutations(string_output):
        temp = "".join(perm)
        print (temp)
        number-=1
        if(number==0):
            break


def main():
    #t = random.randint(1, 100)
    t = 100
    print (t)
    #t-x random tests and x permutations' test.
    x = random.randint(1, t)
    for i in range(t-x) :
        output = randomString(1000)
        print (output)
        q = random.randint(1, 1000)
        print (q)
        for j in range(q):
            print randomString(1000)

    for i in range(x):
        output = randomString(1000);
        print (output)
        q = random.randint(1, 1000)
        print (q)
        permuations(output, q)


main()
