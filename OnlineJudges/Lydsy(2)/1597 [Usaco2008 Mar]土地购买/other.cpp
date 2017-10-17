#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,tot;
ll x[50005],y[50005],f[50005];;
int q[50005];
struct data{ll x,y;}a[50005];
inline bool cmp(data a,data b)
{return a.x==b.x?a.y<b.y:a.x<b.x;}
inline double slop(int a,int b)
{return (double)(f[b]-f[a])/(y[a+1]-y[b+1]);}
int main()
{
	freopen("code.in","r",stdin);
	freopen("other.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
       a[i].x=read(),a[i].y=read();
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        while(tot&&a[i].y>=y[tot])tot--;
        x[++tot]=a[i].x;y[tot]=a[i].y;
    }
    int l=0,r=0;
    for(int i=1;i<=tot;i++)
    {
        while(l<r&&slop(q[l],q[l+1])<x[i])l++;
        int t=q[l];
        f[i]=f[t]+y[t+1]*x[i];
        while(l<r&&slop(q[r],i)<slop(q[r-1],q[r]))r--;
        q[++r]=i;
    }
    printf("%lld",f[tot]);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
