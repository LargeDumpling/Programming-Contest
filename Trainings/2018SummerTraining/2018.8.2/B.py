m=int(input());
a=[0,2,3];
b=[0,6,7];
while 1:
    if m<=a[1]:
        break;
    t=2*a[2]*a[1]-a[0];
    a[0]=a[1];
    a[1]=t;

while 1:
    if m<=b[1]:
        break;
    t=2*b[2]*b[1]-b[0];
    b[0]=b[1];
    b[1]=t;

if b[1]<a[1]:
    a[1]=b[1];
print(a[1]);
