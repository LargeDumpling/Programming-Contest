/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,m,C[75],R[75];
int fir[75],cur[75],lev[75],end[5050],next[5050],c[5050],f[5050],ed=1;
int q[10050];
void addedge(int u,int v,int cap)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	c[ed]=cap;
	f[ed]=0;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	f[ed]=c[ed]=cap;
	return;
}
int inc(int &x){return ++x>10048?x-10048:x;}
#define head q[0]
#define tail q[10049]
bool BFS(int sta,int tar)
{
	int u;
	memset(lev,head=tail=0,sizeof(lev));
	lev[sta]=1;
	q[inc(tail)]=sta;
	while(head!=tail)
	{
		u=q[inc(head)];
		for(int i=fir[u];i;i=next[i])
		{
			if(lev[end[i]]||f[i]==c[i])continue;
			lev[end[i]]=lev[u]+1;
			q[inc(tail)]=end[i];
		}
	}
	for(int i=n+m+2;i;i--)cur[i]=fir[i];
	return lev[tar];
}
#undef head
#undef tail
int DFS(int u,int tar,int maxf)
{
	if(u==tar)return maxf;
	int totf=0,temf;
	for(int &i=cur[u];i;i=next[i])
	{
		if(lev[end[i]]!=lev[u]+1||c[i]==f[i])continue;
		totf+=(temf=DFS(end[i],tar,min(maxf,c[i]-f[i])));
		maxf-=temf;
		f[i^1]-=temf;
		f[i]+=temf;
	}
	if(!totf)lev[u]=0;
	return totf;
}
void Dinic()
{
	int sta,tar;
	memset(fir,0,sizeof(fir));
	ed=1;
	sta=n+m+1;
	tar=sta+1;
	for(int i=1;i<=n;i++)
		addedge(sta,i,C[i]);
	for(int i=1;i<=m;i++)
		addedge(i+n,tar,R[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			addedge(i,j+n,19);
	while(BFS(sta,tar))DFS(sta,tar,2147483647);
	return;
}
#undef head
#undef tail
void print(int cAse)
{
	printf("Matrix %d\n",cAse);
	int mat[35][35];
	for(int i=1;i<=n;i++)
		for(int j=fir[i];j;j=next[j])if(n<end[j]&&end[j]<=n+m)
			mat[i][end[j]-n]=f[j]+1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d ",mat[i][j]);
		putchar('\n');
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	for(int cAse=1;cAse<=T;cAse++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&C[i]);
		for(int i=1;i<=m;i++)scanf("%d",&R[i]);
		for(int i=n;i;i--)C[i]=C[i]-C[i-1]-m;
		for(int i=m;i;i--)R[i]=R[i]-R[i-1]-n;
		Dinic();
		print(cAse);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

