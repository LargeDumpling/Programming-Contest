import sys
import random
sys.stdout=open("A.in","w")
n=random.randint(1,10)
print(n)
for i in range(n):
	print(random.randint(0,n-1),end=' ')
