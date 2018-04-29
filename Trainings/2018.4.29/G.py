x=[0,0,0,0];
y=[0,0,0,0];
def dOt(x0,y0,x1,y1):
    return x0*x1+y0*y1;

def cRoss(x0,y0,x1,y1):
    return x0*y1-x1*y0;

def lEnth2(x,y):
    return x*x+y*y;

def check0():
    n=[0,0,0];
    for i in range(3):
        n[i]=cRoss(x[(i+1)%3]-x[i],y[(i+1)%3]-y[i],x[3]-x[i],y[3]-y[i]);
    if (n[0]<0 and n[1]<0 and n[2]<0) or (0<n[0] and 0<n[1] and 0<n[2]):
        return 1;
    else:
        return 0;

def check1():
    for i in range(3):
        if dOt(x[i]-x[3],y[i]-y[3],x[(i+2)%3]-x[(i+1)%3],y[(i+2)%3]-y[(i+1)%3])!=0:
            return 0;
    return 1

def check2():
    n=[0,0];
    for i in range(3):
        n[0]=abs(cRoss(x[(i+1)%3]-x[i],y[(i+1)%3]-y[i],x[3]-x[i],y[3]-y[i]));
        n[1]=abs(cRoss(x[(i+2)%3]-x[i],y[(i+2)%3]-y[i],x[3]-x[i],y[3]-y[i]));
        if n[0]!=n[1]:
            return 0;
    if check0()==1:
        return 1;
    else:
        return 0;

def check3():
    s=[0,0,0];
    l=[0,0,0];
    for i in range(3):
        s[i]=abs(cRoss(x[i]-x[3],y[i]-y[3],x[(i+1)%3]-x[3],y[(i+1)%3]-y[3]));
        l[i]=lEnth2(x[(i+1)%3]-x[i],y[(i+1)%3]-y[i]);
    for i in range(3):
        if s[i]*s[i]*l[(i+1)%3]!=s[(i+1)%3]*s[(i+1)%3]*l[i]:
            return 0;
    if check0()==1:
        return 1;
    else:
        return 0;

def check4():
    d=[0,0,0];
    for i in range(3):
        d[i]=lEnth2(x[i]-x[3],y[i]-y[3]);
    if d[0]!=d[1] or d[1]!=d[2] or d[2]!=d[0]:
        return 0;
    return 1

for i in range(4):
    x[i],y[i]=map(int,input().split());
if check1()==1 or check2()==1 or check3()==1 or check4()==1:
    print("Yes");
else:
    print("No");
