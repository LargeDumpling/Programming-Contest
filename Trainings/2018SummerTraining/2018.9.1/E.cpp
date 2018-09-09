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
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=25;
struct jz
{
	int u,S,cnt;
	jz(const int &U=0,const int &SS=0,const int &C=0):u(U),S(SS),cnt(C) { }
};
bool aa;
int n,pre[MAXN];
long long a[MAXN],b[MAXN],f[1100000],ans=0;
bool exist[1100000],vis[1100000];
bool bb;
void SPFA()
{
	int S=0;
	long long cnt=0;
	queue<jz> q;
	f[0]=0;
	for(int i=0;i<n;i++) if((pre[i]&S)==pre[i]
			&&(!vis[S|(1<<i)]||f[S|(1<<i)]<f[S]+a[i]*(cnt+1LL)+b[i]))
	{
		f[S|(1<<i)]=f[S]+a[i]*(cnt+1LL)+b[i];
		vis[S|(1<<i)]=true;
		q.push(jz(i,S|(1<<i),cnt+1));
		exist[S|(1<<i)]=true;
	}
	while(q.size())
	{
		S=q.front().S;
		cnt=q.front().cnt;
		q.pop();
		exist[S]=false;
		for(int i=0;i<n;i++) if((!((S>>i)&1))&&((pre[i]&S)==pre[i])
				&&(!vis[S|(1<<i)]||f[S|(1<<i)]<f[S]+a[i]*(cnt+1LL)+b[i]))
		{
			f[S|(1<<i)]=f[S]+a[i]*(cnt+1LL)+b[i];
			vis[S|(1<<i)]=true;
			ans=max(ans,f[S|(1<<i)]);
			if(!exist[S|(1<<i)])
			{
				exist[S|(1<<i)]=true;
				q.push(jz(i,S|(1<<i),cnt+1));
			}
		}
	}
	return;
}
int main()
{
	int pn,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld%d",&a[i],&b[i],&pn);
		while(pn--)
		{
			scanf("%d",&x); x--;
			pre[i]|=(1<<x);
		}
	}
	SPFA();
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

