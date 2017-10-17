import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,100)
print(T)
for cAse in range(T):
    n=random.randint(1,50)
    m=random.randint(1,50)
    print(n,m)
    D=random.randint(1,10000)
    F=random.randint(1,10000)
    B=random.randint(1,10000)
    print(D,F,B)
    for i in range(m):
        for j in range(n):
            if(random.randint(1,2)==1):
                print('#',end='')
            else:
                print('.',end='')
        print()
    
