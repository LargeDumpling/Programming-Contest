import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,100)
for i in range(T):
    n=random.randint(2,100)
    m=random.randint(1,100)
    s=random.randint(1,n)
    t=random.randint(1,n)
    while(s==t):
        s=random.randint(1,n)
        t=random.randint(1,n)
    print(n,m,s,t)
    for i in range(m):
        u=random.randint(1,n)
        v=random.randint(1,n)
        while u==v:
            u=random.randint(1,n)
            v=random.randint(1,n)
        a=random.randint(1,100)
        b=random.randint(1,100)
        t=random.randint(1,a)
        print(u,v,a,b,t)
