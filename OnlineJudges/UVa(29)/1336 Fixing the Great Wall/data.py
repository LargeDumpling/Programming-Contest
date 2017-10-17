import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,3)
for cAse in range(T):
	pos=[i for i in range(10)]
	n=random.randint(1,5)
	v=random.randint(1,5)
	x=random.randint(1,20)
	print(n,v,x)
	for i in range(n,0,-1):
		t=random.randint(1,i)
		pos[t],pos[i]=pos[i],pos[t]
		c=random.randint(1,2)
		t=random.randint(1,5)
		print(pos[i],c,t)
print(0,0,0)
