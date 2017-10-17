import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,5)
for cAse in range(T):
    n=random.randint(2,9)
    d=random.randint(1,n-1)
    print(n,d)
    print(random.randint(1,9),end='')
    for i in range(n-1):
        print(random.randint(0,9),end='')
    print()
print(0,0)
