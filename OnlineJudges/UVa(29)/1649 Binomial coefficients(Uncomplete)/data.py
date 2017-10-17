import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,10)
print(T)
while (T!=0):
    print(random.randint(2,100))
    T-=1
