import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,3)
print(T)
for cAse in range(T):
    n,m=random.randint(1,5),random.randint(1,5)
    print(n,m)
    for i in range(n):
        for j in range(m):
            if random.randint(1,2)==1:
                print('#',end='')
            else:
                print('.',end='')
        print()
