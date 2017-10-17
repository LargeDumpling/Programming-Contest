import sys
import random
a=[0 for i in range(1000000)]
for k in range(1,11):
    sys.stdout=open("code"+str(k)+".in","w")
    print(1000000)
    for i in range(1000000):
        a[i]=random.randint(1,1000001)
        print(a[i],end=' ')
    sys.stdout=open("code"+str(k)+".out","w")
    for i in sorted(a):
        print(i,end=' ')
