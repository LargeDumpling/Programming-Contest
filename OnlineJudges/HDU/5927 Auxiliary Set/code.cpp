/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-10-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int T_T,n,q;
int fir[MAXN],eNd[MAXN<<1],nExt[MAXN<<1],ed;
int sonn[MAXN],fa[MAXN],dfn[MAXN],dfs_clock;
int sEt[MAXN],alu[MAXN],m;
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
bool cmp(int u,int v) { return dfn[u]>dfn[v]; }
void addedge(int u,int v)
{
	eNd[++ed]=v;
	nExt[ed]=fir[u];
	fir[u]=ed;
	eNd[++ed]=u;
	nExt[ed]=fir[v];
	fir[v]=ed;
	return;
}
void DFS(int u)
{
	dfn[u]=++dfs_clock;
	sonn[u]=0;
	for(int i=fir[u];i;i=nExt[i]) if(eNd[i]!=fa[u])
	{
		fa[eNd[i]]=u;
		sonn[u]++;
		DFS(eNd[i]);
	}
	return;
}
int main()
{
	int u,v,cnt;
	read1n(T_T);
	for(int T=1;T<=T_T;T++)
	{
		memset(fir,ed=dfs_clock=0,sizeof(fir));
		read1n(n); read1n(q);
		for(int i=1;i<n;i++)
		{
			read1n(u);
			read1n(v);3
			addedge(u,v);
		}
		fa[1]=0;
		DFS(1);
		printf("Case #%d:\n",T);
		for(int i=1;i<=q;i++)
		{
			cnt=0;
			read1n(m);
			for(int j=1;j<=m;j++)
				read1n(sEt[j]);
			sort(sEt+1,sEt+m+1,cmp);
			for(int j=1;j<=m;j++)
			{
				cnt++;
				if(alu[sEt[j]]+2<=sonn[sEt[j]])
					cnt--;
				if(alu[sEt[j]]==sonn[sEt[j]])
					alu[fa[sEt[j]]]++;
			}
			printf("%d\n",n-cnt);
			for(int j=1;j<=m;j++)
				alu[sEt[j]]=alu[fa[sEt[j]]]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

