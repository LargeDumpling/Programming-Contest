/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-02	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int M=131072;
const long long mod=998244353;
struct jz
{
	int x,y;
	bool operator<(const jz &X)const { return x==X.x?y<X.y:x<X.x; }
}p[MAXN];
int n,hx[MAXN],hy[MAXN],d[M<<1];
long long ycnt[MAXN];
long long pOw(long long a,long long m)
{
	long long ans;
	for(ans=1;m;m>>=1,a=a*a%mod)
		if(m&1)
			ans=ans*a%mod;
	return ans;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
long long calc2()
{
	long long sum=0,m=n;
	memset(ycnt,0,sizeof(ycnt));
	for(int i=1;i<=n;i++)
		ycnt[p[i].y]++;
	for(int i=1;i<=hy[0];i++)
		sum=(sum+(m-ycnt[i])*ycnt[i]%mod)%mod;
	sum=sum*pOw(2,mod-2)%mod;
	return sum;
}
void change(int p,int x)
{
	for(p+=M;p;p>>=1)
		d[p]+=x;
	return;
}
long long query(int L,int R)
{
	long long sum=0;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) sum+=d[L^1];
		if(R&1) sum+=d[R^1];
	}
	return sum;
}
long long calc3()
{
	long long sum=0;
	memset(d,0,sizeof(d));
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
		change(p[i].y,1);
	for(int i=1,j;i<=n;i=j)
	{
		for(j=i;p[i].x==p[j].x;j++)
			change(p[j].y,-1);
		for(j=i;p[i].x==p[j].x;j++)
			sum=(sum+query(1,p[j].y-1)*query(p[j].y+1,hy[0])%mod)%mod;
	}
	return sum;
}
int main()
{
	long long ans;
	read1n(n);
	for(int i=1;i<=n;i++)
	{
		read1n(p[i].x);
		hx[++hx[0]]=p[i].x;
		read1n(p[i].y);
		hy[++hy[0]]=p[i].y;
	}
	sort(hx+1,hx+hx[0]+1);
	hx[0]=unique(hx+1,hx+hx[0]+1)-hx-1;
	sort(hy+1,hy+hy[0]+1);
	hy[0]=unique(hy+1,hy+hy[0]+1)-hy-1;
	for(int i=1;i<=n;i++)
	{
		p[i].x=lower_bound(hx+1,hx+hx[0]+1,p[i].x)-hx;
		p[i].y=lower_bound(hy+1,hy+hy[0]+1,p[i].y)-hy;
	}
	ans=n;
	ans=(ans+calc2())%mod;
	ans=(ans+calc3())%mod;
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

