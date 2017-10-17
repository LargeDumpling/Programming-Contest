import sys #调用文件所需
import random #随机数所需

sys.stdout=open("code.in","w")

n=random.randint(1,5)
print(n)
for i in range(n):
    print(random.randint(1,5),end=' ')
print()
m=random.randint(1,5)
print(m)
for i in range(m):
    print(random.randint(1,n),random.randint(1,n))
