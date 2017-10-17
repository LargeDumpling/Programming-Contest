import sys
import random
sys.stdout=open("code.in","w")
n,m=5,5
print(n,m)
for i in range(m):
    a,b=random.randint(1,n),random.randint(1,n)
    print(a-1,b-1)
