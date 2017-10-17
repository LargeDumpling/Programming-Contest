import sys
import random
sys.stdout=open("code.in","w")
t=random.randint(1,5)
print(t)
for i in range(t):
    n=random.randint(5,8)
    print(n,random.randint(1,n))
    for j in range(n):
        print(random.randint(0,1),end='')
    print()
