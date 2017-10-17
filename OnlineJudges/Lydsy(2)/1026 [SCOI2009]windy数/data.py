import sys
import random
sys.stdout=open("code.in","w");
a=random.randint(1,20);
b=random.randint(1,20);
if(a>b):
    a,b=b,a
print(a,b)
