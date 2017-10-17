#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,fir[50050],end[200050],next[200050],ed=0,cn=0;
bool vis[50050];
long long cir[100050],dis[50050],len[200050];
typedef long long LL;
inline LL gint() {
    char c=getchar();
    int f=1;
    while(c<'0'||c>'9') {
        if(c=='-')f=-1;
        c=getchar();
    }
    LL a=c-'0';
    while((c=getchar())>='0'&&c<='9') {
        a=a*10+c-'0';
    }
    return a*f;
}
void addedge(int u,int v,long long lenth)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=lenth;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	len[ed]=lenth;
	return;
}
void DFS(int u)
{
	vis[u]=true;
	for(int i=fir[u];i;i=next[i])
	{
		if(vis[end[i]])
			cir[++cn]=dis[u]^dis[end[i]]^len[i];
		else
		{
			dis[end[i]]=dis[u]^len[i];
			DFS(end[i]);
		}
	}
	return;
}
void gauss()
{
	long long i;
	int j,now=0;
	for(i=(1<<61);i;i>>=1)
	{
		for(j=now+1;j<=cn&&!(cir[j]&i);j++);
		if(j==cn+1)continue;
		swap(cir[++now],cir[j]);
		for(j=1;j<=cn;j++)if(now!=j&&(cir[j]&i))cir[j]^=cir[now];
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	long long ans=0,c;
	n=gint();m=gint();
	for(int i=1;i<=m;i++)
	{
		a=gint();
		b=gint();
		c=gint();
		addedge(a,b,c);
	}
	DFS(1);
	gauss();
	ans=dis[n];
	for(int i=1;i<=cn;i++)
		ans=max(ans,ans^cir[i]);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

