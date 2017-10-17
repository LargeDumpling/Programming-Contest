import sys
import random
sys.stdout=open("code.in","w")
num=[[0 for i in range(30)] for i in range(30)]
C=[0 for i in range(30)]
R=[0 for i in range(30)]
T=random.randint(1,100)
print(T)
for i in range(T):
    n=random.randint(1,20)
    m=random.randint(1,20)
    for i in range(1,m+1):
        R[i]=0
    for i in range(1,n+1):
        C[i]=0
        for j in range(1,m+1):
            num[i][j]=random.randint(1,20)
            C[i]+=num[i][j]
            R[j]+=num[i][j]
    for i in range(1,n+1):
        C[i]+=C[i-1]
    for i in range(1,m+1):
        R[i]+=R[i-1]
    print(n,m)
    for i in range(1,n+1):
        print(C[i],end=' ')
    print()
    for i in range(1,m+1):
        print(R[i],end=' ')
    print()
