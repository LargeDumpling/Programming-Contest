import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,20)
print(T)
for case in range(T):
	n=random.randint(1,200)
	print(n,end=' ')
	for i in range(n):
		print(random.randint(1,100000),end=' ')
	print()
