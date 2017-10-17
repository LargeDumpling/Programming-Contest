import sys
import random
sys.stdout=open("code.in","w")
t=random.randint(1,3)
print(t)
for T in range(1,t + 1):
    print()
    lenth=random.randint(1,10)
    for l in range(1,lenth+1):
        k=random.randint(1,4)
        if k==1:
            print('[',end='')
        elif k==2:
            print(']',end='')
        elif k==3:
            print('(',end='')
        elif k==4:
            print(')',end='')
