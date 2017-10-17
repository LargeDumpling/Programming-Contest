#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define min(a,b) (a<b?a:b)
using namespace std;
//N<=200000 K<=1000000
int fir[200050],end[400050],next[400050],len[400050];
int son[200050],d[200050],dis[200050],t[1000050];
int ed=0,size,root,n,k,ans;
bool vis[200050];
int readln(int &x)
{
	char ch=getchar();
	bool a=false;
	x=0;
	while(ch<'0'||'9'<ch)
	{
		if(ch=='-')
			a^=1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	if(a)
		x=-x;
	return x;
}
void addedge(int u,int v,int l)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	len[ed]=l;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	len[ed]=l;
	return;
}
void DFS(int u,int f,int all)
{
	int temp=0;
	son[u]=0;
	for(int i=fir[u];i;i=next[i])
	{
		if(vis[end[i]]||end[i]==f)
			continue;
		DFS(end[i],u,all);
		son[u]+=son[end[i]]+1;
		if(son[end[u]]+1>temp)
			temp=son[end[i]]+1;
	}
	if(all-son[u]-1>temp)
		temp=all-son[u]-1;
	if(temp<size)
	{
		root=u;
		size=temp;
	}
	return;
}
void cal(int u,int f)
{
	if(dis[u]<=k&&d[u]+t[k-dis[u]]<ans)
		ans=d[u]+t[k-dis[u]];
	for(int i=fir[u];i;i=next[i])
	{
		if(vis[end[i]]||end[i]==f)
			continue;
		d[end[i]]=d[u]+1;
		dis[end[i]]=dis[u]+len[i];
		cal(end[i],u);
	}
	return;
}
void add(int u,int f,bool flag)
{
	if(dis[u]<=k)
	{
		if(flag)
			t[dis[u]]=min(t[dis[u]],d[u]);
		else
			t[dis[u]]=1000000000;
	}
	for(int i=fir[u];i;i=next[i])
		if(!vis[end[i]]&&end[i]!=f)
			add(end[i],u,flag);
	return;
}
void work(int u,int all)
{
	size=2147483647;
	DFS(u,u,all);
	u=root;
	d[u]=0;
	dis[u]=0;
	vis[u]=true;
	t[0]=0;
	for(int i=fir[u];i;i=next[i])
		if(!vis[end[i]])
		{
			d[end[i]]=d[u]+1;
			dis[end[i]]=dis[u]+len[i];
			cal(end[i],u);
			add(end[i],u,true);
		}
	for(int i=fir[u];i;i=next[i])
		if(!vis[end[i]])
			add(end[i],u,false);
	for(int i=fir[u];i;i=next[i])
		if(!vis[end[i]])
			work(end[i],son[end[i]]+1);
	return;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("code.txt","w",stdout);
	int a,b,c;
	readln(n);
	readln(k);
	for(int i=1;i<=k;i++)
		t[i]=1000000000;
	for(int i=1;i<n;i++)
	{
		readln(a);
		readln(b);
		readln(c);
		a++;
		b++;
		addedge(a,b,c);
	}
	ans=n;
	t[0]=0;
	work(1,n);
	if(ans<n)
		printf("%d",ans);
	else
		printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

