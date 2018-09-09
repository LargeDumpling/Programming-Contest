/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-01	File created.
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
const int INF=2147483647;
int n,m;
int mbl[MAXN],d[M<<1];
int ans[MAXN][2];
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void build()
{
	for(int i=1;i<=n;i++)
		d[i+M]=mbl[i];
	for(int i=M-1;i;i--)
		d[i]=min(d[i<<1],d[i<<1|1]);
	return;
}
void del(int x)
{
	mbl[x]=d[x+M]=INF;
	for(int i=(x+M)>>1;i;i>>=1)
		d[i]=min(d[i<<1],d[i<<1|1]);
	return;
}
int query(int L,int R)
{
	int ans=INF;
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) ans=min(ans,d[L^1]);
		if(R&1) ans=min(ans,d[R^1]);
	}
	return ans;
}
void calc()
{
	int nex,cnt,now,l,mid,r,left=0;
	ans[0][0]=ans[0][1]=0;
	build();
	cnt=0;
	for(int i=1;i<MAXN;i++)
	{
		if(cnt==n)
		{
			ans[i][0]=ans[i-1][0];
			ans[i][1]=ans[i-1][1];
			continue;
		}
		left+=m;
		now=1;
		while(true)
		{
			if(mbl[now]<=left) nex=now;
			else if(left<query(now,n)) nex=n+1;
			else
			{
				l=now; r=n;
				while(l<r-1)
				{
					mid=(l+r)>>1;
					if(query(now,mid)<=left) r=mid;
					else l=mid;
				}
				nex=r;
			}
			if(nex==n+1) break;
			left-=mbl[nex];
			cnt++;
			del(nex);
			now=nex;
		}
		ans[i][0]=cnt;
		ans[i][1]=left;
	}
}
int main()
{
	int Q,x;
	read1n(n); read1n(m);
	for(int i=1;i<=n;i++)
		scanf("%d",&mbl[i]);
	calc();
	read1n(Q);
	while(Q--)
	{
		read1n(x);
		printf("%d %d\n",ans[x][0],ans[x][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

