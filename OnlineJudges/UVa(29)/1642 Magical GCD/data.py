import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,5)
print(T)
for cAse in range(T):
    n=random.randint(1,10)
    print(n)
    for i in range(n):
        print(random.randint(1,20),end=' ')
    print()
