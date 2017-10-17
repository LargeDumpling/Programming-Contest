import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,6)
while T!=0:
    T=T-1
    n=random.randint(1,25)
    m=random.randint(1,50)
    q=random.randint(1,10)
    print(n,m,q)
    for i in range(m):
        a=random.randint(1,n)
        b=random.randint(1,n)
        while(a==b):
            a=random.randint(1,n)
            b=random.randint(1,n)
        print(a,b,random.randint(1,100))
    for i in range(q):
        a=random.randint(1,n)
        b=random.randint(1,n)
        while(a==b):
            a=random.randint(1,n)
            b=random.randint(1,n)
        print(a,b)
print(0,0,0)
