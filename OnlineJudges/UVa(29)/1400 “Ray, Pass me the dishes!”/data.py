import sys
import random
T=random.randint(1,3)
sys.stdout=open("code.in","w")
for cAse in range(T):
	n=random.randint(1,500000)
	m=random.randint(1,500000)
	print(n,m)
	for i in range(n):
		print(random.randint(-1000000000,1000000000),end=' ')
	print()
	for i in range(m):
		l=random.randint(1,n)
		r=random.randint(l,n)
		print(l,r)
