import sys
import random
sys.stdout=open("code.in","w")
for i in range(10):
    a=random.randint(1,50)
    b=random.randint(1,50)
    if a>b:
        a, b = b, a
    print(a,b)
print(0,0)
