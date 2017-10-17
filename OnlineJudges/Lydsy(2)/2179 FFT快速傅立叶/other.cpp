/**************************************************************
    Problem: 2179
    User: DCOI
    Language: C++
    Result: Accepted
    Time:2320 ms
    Memory:5604 kb
****************************************************************/
 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define TQ template<class Q>
#define cQ const complex<Q>
using namespace std;
/* 
TQ class complex{
    public:
    Q r,i;
    complex(){}
    complex(const Q&r,const Q&i):r(r),i(i){}
    inline complex&operator+=(cQ&o){r+=o.r;i+=o.i;return *this;}
    inline complex&operator-=(cQ&o){r-=o.r;i-=o.i;return *this;}
    friend complex operator+(cQ&x,cQ&y){complex res=x;return res+=y;}
    friend complex operator-(cQ&x,cQ&y){complex res=x;return res-=y;}
    friend complex operator*(cQ&x,cQ&y){
        return complex(x.r*y.r-x.i*y.i,x.r*y.i+y.r*x.i);
    }
    inline complex&operator*=(cQ&o){return *this=(*this)*o;}
};
*/
TQ class complex{
    public:
        Q r,i;
        complex(){}
        complex(const Q&r,const Q&i):r(r),i(i){}
        inline complex operator+(cQ&o){return complex(r+o.r,i+o.i);}
        inline complex operator-(cQ&o){return complex(r-o.r,i-o.i);}
        inline complex&operator+=(cQ&o){return *this=(*this)+o;}
        inline complex&operator-=(cQ&o){return *this=(*this)-o;}
        inline complex operator*(cQ&o){
            return complex(r*o.r-i*o.i,r*o.i+i*o.r);
        }
        inline complex&operator*=(cQ&o){return *this=(*this)*o;}
};
 
const int MAXN=131072+5;
 
int bitrev[MAXN];
 
inline void brc(int d,int n){
    for(int i=1;i<n;++i){
        bitrev[i]=(bitrev[i>>1]>>1)|((i&1)<<d-1); 
    }
}
 
typedef double db;
typedef complex<db>cp;
const db PI=acos(-1.);
 
inline void fft(cp* c,int n,int type){
    for(int i=1;i<n;++i)
        if(i<bitrev[i])swap(c[i],c[bitrev[i]]);
    db pi=PI*type;
    for(int step=1;step<n;step<<=1)
	{
        db alpha=pi/step;
        cp w(cos(alpha),sin(alpha)),cur(1,0);
        for(int i=0;i<step;i++)
		{
            for(int j=i;j<n;j+=step<<1)
			{
                cp t=c[j+step]*cur;
                c[j+step]=c[j]-t; c[j]+=t;
            }
            cur*=w;
        }
    }
    if(type==-1){
        for(int i=0;i<n;i++)c[i].r/=n;
    }
}
 
cp a[MAXN],b[MAXN];
 
int n;
 
char str[MAXN>>1];
 
char ans[MAXN];
 
int main(){
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=0;i<n;++i)
        a[i].r=str[n-i-1]-48;
    scanf("%s",str);
    for(int i=0;i<n;++i)
        b[i].r=str[n-i-1]-48;
    n<<=1;
    int d=0;
    for(;(1<<d)<n;++d);
    brc(d,n=1<<d);
    fft(a,n,1); fft(b,n,1);
    for(int i=0;i<n;++i)a[i]*=b[i];
    fft(a,n,-1);
    int x=0;
    for(int i=0;i<n;++i){
        x+=int(a[i].r+0.5);
        ans[i]=x%10; x/=10; 
    }
    while(x)ans[n++]=x%10,x/=10;
    while(n&&!ans[n-1])--n;
    for(int i=n-1;~i;--i)
        putchar(ans[i]+48);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
 
