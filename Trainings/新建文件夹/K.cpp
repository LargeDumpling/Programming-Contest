/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
const int MAXM=10050;
const int MAXA=1050;
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int T_T,n,m,a[MAXN],b[MAXN];
long long an[MAXA],w[MAXA][MAXA],r[MAXN];
void change_a(int i,int x)
{
	for(int j=0;j<b[i];j++)
		w[a[i]][j]++;
	r[0]-=r[i];
	b[i]+=r[i]*a[i];
	an[a[i]]--;
	a[i]=x;
	an[a[i]]++;
	r[0]+=(r[i]=b[i]/a[i]);
	b[i]%=a[i];
	for(int j=0;j<b[i];j++)
		w[a[i]][j]--;
	return;
}
void change_b(int i,int x)
{
	for(int j=0;j<b[i];j++)
		w[a[i]][j]++;
	r[0]-=r[i];
	b[i]=x;
	r[0]+=(r[i]=b[i]/a[i]);
	b[i]%=a[i];
	for(int j=0;j<b[i];j++)
		w[a[i]][j]--;
	return;
}
long long check(long long x)
{
	long long ans=0;
	for(int i=1;i<=1000;i++)
		ans+=x/i*an[i]+w[i][x%i];
	ans-=r[0];
	return ans;
}
long long query(int k)
{
	long long l=0,r=2LL*1e12,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(k<=check(mid)) r=mid;
		else l=mid;
	}
	return r;
}
void init()
{
	memset(w,0,sizeof(w));
	memset(an,0,sizeof(an));
	memset(r,0,sizeof(r));
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int op,x,y;
	read1n(T_T);
	while(T_T--)
	{
		init();
		read1n(n); read1n(m);
		for(int i=1;i<=n;i++)
			read1n(a[i]);
		for(int i=1;i<=n;i++)
		{
			read1n(b[i]);
			r[0]+=(r[i]=b[i]/a[i]);
			b[i]%=a[i];
			an[a[i]]++;
			for(int j=0;j<b[i];j++)
				w[a[i]][j]--;
		}
		while(m--)
		{
			read1n(op);
			switch(op)
			{
				case 1:
					read1n(x);
					read1n(y);
					change_a(x,y);
					break;
				case 2:
					read1n(x);
					read1n(y);
					change_b(x,y);
					break;
				case 3:
					read1n(y);
					printf("%lld\n",query(y));
					break;
				default:
					break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

