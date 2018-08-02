a=[2,12];
an=2;
c=[]
cn=0
flag=1;
while flag:
    a.append(6*a[an-1]-a[an-2]);
    c.append(a[an-1]);
    if 1000<len(str(a[an-1])):
        flag=0;

b=[6,84]
bn=2
flag=1;
while flag:
    b.append(14*b[bn-1]-b[bn-2]);
    c.append(b[bn-1]);
    if 1000<len(str(b[bn-1])):
        flag=0;

c.sort();
