import sys
import random
sys.stdout=open("code.in","w");
t=random.randint(1,10);
while t:
	t=t-1
	print(random.randint(1,100),random.randint(1,3000));
print(0)
