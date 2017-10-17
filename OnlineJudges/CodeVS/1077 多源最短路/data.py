import sys
import random
sys.stdout=open("code.in","w")
n=random.randint(1,10)
print(n)
a=[[0 for i in range(11)] for j in range(11)]
for i in range(1,n+1):
    for j in range(1,n+1):
        if i==j:
            print(0,end=' ')
        elif i<j:
            a[i][j]=a[j][i]=random.randint(1,11)
            print(a[i][j],end=' ')
        else:
            print(a[i][j],end=' ')
    print()
q=random.randint(1,11)
print(q)
for i in range(q):
    print(random.randint(1,n),random.randint(1,n))
