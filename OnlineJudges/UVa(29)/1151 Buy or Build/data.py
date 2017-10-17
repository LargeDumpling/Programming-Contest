import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,100)
print(T)
for cAse in range(T):
    print()
    n=random.randint(1,1000)
    q=random.randint(1,8)
    print(n,q)
    for i in range(q):
        num=random.randint(1,n)
        print(num,random.randint(1,3000),end=' ')
        f=[j for j in range(1050)]
        for j in range(num,0,-1):
            k=random.randint(1,j)
            f[k],f[j]=f[j],f[k]
            print(f[j],end=' ')
        print()
    for i in range(n):
        print(random.randint(1,3000),random.randint(1,3000))
    print()
