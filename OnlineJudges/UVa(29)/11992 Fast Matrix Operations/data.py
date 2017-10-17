import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,1)
for cAse in range(T):
	n=random.randint(1,20)
	m=random.randint(1,1000)
	q=random.randint(1,10000)
	print(n,m,q)
	for i in range(q):
		order=random.randint(1,3)
		a=random.randint(1,n)
		b=random.randint(1,m)
		c=random.randint(1,n)
		d=random.randint(1,m)
		e=random.randint(1,10000)
		if(a>c):
			a,c=c,a
		if(b>d):
			b,d=d,b
		if(order==1):
			print(order,a,b,c,d,e)
		elif(order==2):
			print(order,a,b,c,d,e)
		elif(order==3):
			print(order,a,b,c,d)
