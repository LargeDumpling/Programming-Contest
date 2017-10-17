import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,5)
print(T)
for cAse in range(T):
    lenth=random.randint(1,10)
    for i in range(lenth):
        if(random.randint(0,2)==0):
            print("?",end='')
        else:
            print(random.randint(0,1),end='')
    print()
    for i in range(lenth):
        print(random.randint(0,1),end='')
    print()
