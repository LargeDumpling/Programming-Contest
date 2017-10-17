import sys
import random
sys.stdout=open("code.in","w")
T=random.randint(1,3)
a=[[i for i in range(6)] for i in range(7)]
char=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
print(T)
for cAse in range(T):
    k=random.randint(1,700)
    print(k)
    for i in range(6):
        for j in range(5):
            t=random.randrange(j,26)
            char[t],char[j]=char[j],char[t]
            a[i][j]=char[j]
            print(a[i][j],end='')
        print()
    for i in range(6):
        for j in range(5):
            if(random.randint(1,2)==1):
                print(a[i][j],end='')
            else:
                t=random.randrange(j,26)
                char[t],char[j]=char[j],char[t]
                print(char[j],end='')
        print()
