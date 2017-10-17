import sys
sys.stdin=open("code.in","r")
sys.stdout=open("py.out","w")
T=int(input())
for cAse in range(T):
    n=int(input())
    print(n*(n-1)*(n-2)*(n-3)/24)
    print(n*(n-1)/2)
    print(int(1+n*(n-1)*(n-2)*(n-3)/24+n*(n-1)/2))
