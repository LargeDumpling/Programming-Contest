import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,8)
for cAse in range(T):
	num=[0 for i in range(100000)]
	sz=random.randint(1,10)
	alll=0
	for i in range(sz):
		num[i]=random.randint(1,10)
		alll+=num[i]
	q=random.randint(1,10)
	print(alll,q)
	low=random.randint(-100000,100000)
	for i in range(sz):
		x=random.randint(low,100000)
		low=x
		for j in range(num[i]):
			print(x,end=' ')
	print()
	for i in range(q):
		l=random.randint(1,alll)
		r=random.randint(l,alll)
		print(l,r)
print(0)
