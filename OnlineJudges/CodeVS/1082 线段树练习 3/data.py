import sys
import random
#sys.stdout=open("code.in","w")
n=random.randint(1,10)
print(n)
for i in range(n-1):
    print(random.randint(1,5),end=' ')
q=random.randint(1,5)
print(q)
for i in range(q-1):
    if random.randint(0,1)==0:
        a,b=random.randint(1,n),random.randint(1,n)
        if a>b:
            a,b=b,a
        print(1,a,b,random.randint(1,5))
    else:
        a,b=random.randint(1,n),random.randint(1,n)
        if a>b:
            a,b=b,a
        print(2,a,b)
