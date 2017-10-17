import sys
import random
sys.stdout=open("code.in","w")
name=["Slime","Abdullah","Owl","Megistias","Alchemy","cdsmdy","znnfrom","kzzw","KUMA","AgentOrtize","DaiDaidetulong","Li","NMBGWBDZ","GCD","XJP","BXL","HLS","HJT","XXHH","JZM","JT","@@@@@@","Hugegun","Lesphere","Showson","2333"]
T=random.randint(1,5)
print(T)
while(T):
    T-=1
    n=random.randint(1,20)
    print(n)
    for i in range(n):
        print(random.choice(name))
    n=random.randint(1,20)
    print(n)
    for i in range(n):
        print(random.choice(name),random.choice(name))
    n=random.randint(1,20)
    print(n)
    for i in range(n):
        print(random.choice(name),random.choice(name))
