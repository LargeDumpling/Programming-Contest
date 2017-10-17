import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,600)
print(T)
for cAse in range(T):
    R=random.randint(1,1000000000000)
    L=random.randint(1,R)
    print(L,R)
