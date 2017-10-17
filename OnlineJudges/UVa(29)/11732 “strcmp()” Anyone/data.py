import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,100)
leter="abcdefghijklmnopqrstuvwxyz"
for cAse in range(T):
	n=random.randint(1,100)
	print(n)
	for i in range(n):
		lenth=random.randint(1,100)
		for j in range(lenth):
			print(random.choice(leter),end='')
		print()
print(0)
