import sys
import random
sys.stdout=open("code.in","w")
t=random.randint(1,5)
print(t)
for i in range(t):
    n=random.randint(1,5)
    print(n)
    for j in range(n):
        print(random.randint(1,5),end=' ')
    print()
