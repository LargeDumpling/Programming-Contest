import sys
import random
sys.stdout=open("code.in","w")
t=random.randint(1,3)
print(t)
for i in range(t):
    n=random.randint(2,10)
    k=random.randint(1,n-1)
    print(n,k)
    for j in range(n):
        print(random.randint(1,10),end=' ')
    print() 
