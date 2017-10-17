import sys
import random
sys.stdout=open("code.in","w")
n=random.randint(1,100000)
print(n)
for i in range(n):
    print(random.randint(1,10000))
m=random.randint(1,100000)
print(m)
for i in range(m):
    a=random.randint(1,2)
    print(a, end=' ')
    if a==1:
        print(random.randint(1,n),random.randint(1,10000))
    else:
        b,c=random.randint(1,n),random.randint(1,n)
        if(b>c):
            b,c=c,b
        print(b,c)
