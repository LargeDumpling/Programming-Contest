import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,99)
for cAse in range(T):
    n=random.randint(2,99)
    print(n)
    for i in range(n):
        m=random.randint(1,n)
        #print(m)
        for j in range(m):
            a=random.randint(1,n)
            while(a==i+1):
                a=random.randint(1,n)
            print(a,random.randint(1,20),sep=' ',end=' ')
        print(0)
print(0)
