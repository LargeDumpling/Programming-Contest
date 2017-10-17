import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,4)
print(T,end='\n\n')
n=random.randint(3,100)
i=0
num=[i for i in range(0,n+1)]
for j in range(T):
    if(j!=0):
        print()
    print(n)
    for i in range(n):
        rn=random.randint(1,n-1)
        for i in range(rn,0,-1):
        	t=random.randint(1,i)
        	num[t],num[i]=num[i],num[t]
        	print(num[i],end=' ')
        print(0,end=' ')
        if(i!=n-1):
            print()
    if(j!=T-1):
        print()
