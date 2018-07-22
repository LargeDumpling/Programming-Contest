/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=400050;
int n,fir[MAXN],eNd[MAXN<<1],nExt[MAXN<<1],ed=0;
long long w[MAXN],f[MAXN][4][3];
template<typename Ty>
void read1n(Ty &x)
{
	char ch;
	for(ch=0;ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
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
void DFS(int u,int fa)
{
	long long g[4][3],new_g[4][3];
	memset(g,0,sizeof(g));
	for(int i=fir[u],v;i;i=nExt[i]) if((v=eNd[i])!=fa)
	{
		DFS(v,u);
		memset(new_g,0,sizeof(new_g));
		for(int i=0;i<=3;i++)
			for(int j=0;i+j<=3;j++)
				for(int k=0;k<=2;k++)
					for(int l=0;k+l<=2;l++)
						new_g[i+j][k+l]=max(new_g[i+j][k+l],g[i][k]+f[v][j][l]);
		memcpy(g,new_g,sizeof(new_g));
	}
	for(int i=0;i<=3;i++) f[u][i][0]=max(f[u][i][0],g[i][0]);
	for(int i=1;i<=3;i++)
		for(int j=0;j<=2;j++)
			f[u][i][0]=max(f[u][i][0],g[i-1][j]+w[u]);
	for(int i=0;i<=3;i++)
		for(int k=0;k<=1;k++)
			f[u][i][1]=max(f[u][i][1],g[i][k]+w[u]);
	return;
}
int main()
{
	int u,v;
	read1n(n);
	for(int i=1;i<=n;i++)
		read1n(w[i]);
	for(int i=1;i<n;i++)
	{
		read1n(u); read1n(v);
		addedge(u,v);
	}
	DFS(1,1);
	printf("%lld\n",f[1][3][0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

