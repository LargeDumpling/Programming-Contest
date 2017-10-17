import sys
import random
sys.stdout=open("code.in","w")
a=random.randint(1,2000000000)
b=random.randint(1,2000000000)
if a>b:
    a=a+b
    b=a-b
    a=a-b
print(a,b)
