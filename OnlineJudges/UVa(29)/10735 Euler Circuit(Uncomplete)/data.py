import sys
import random
sys.stdout=open("code.in","w")
T=20#random.randint(1,20)
print(T)
for cAse in range(T):
    n=20#random.randint(2,100)
    m=500#random.randint(1,500)
    exist=[0 for i in range(105)]
    print(n,m)
    for i in range(m):
        a,b=0,0
        for j in range(n):
            if(a==0 and exist[j]==1):
                a=j
            elif(a!=0 and exist[j]==1 and b==0):
                b=j
            elif(a!=0 and b!=0):
                break
        if(a==0 or b==0):
            a=random.randint(1,n)
            b=random.randint(1,n)
            while(a==b):
                a=random.randint(1,n)
                b=random.randint(1,n)
        print(a,b,end=' ')
        if(exist[a]==1):
            exist[a]=0
        else:
            exist[a]=1
        if(exist[b]==1):
            exist[b]=0
        else:
            exist[b]=1
        if(random.randint(1,2)==1):
            print("U")
        else:
            print("D")
