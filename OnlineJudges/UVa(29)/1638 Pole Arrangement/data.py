import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,4)
print(T)
for cAse in range(T):
    n=random.randint(1,10)
    l=random.randint(1,n+1)
    r=random.randint(1,n+1)
    print(n,l,r)
