/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=50050;
int fir[MAXN],end[MAXN<<1],next[MAXN<<1],ed=0,n;
int f[MAXN][2];
void addedge(int u,int v)
{
	end[++ed]=v;
	next[ed]=fir[u];
	fir[u]=ed;
	end[++ed]=u;
	next[ed]=fir[v];
	fir[v]=ed;
	return;
}
int F(int u,int fa)
{
	f[u][0]=0; f[u][1]=1;
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa)
	{
		F(end[i],u);
		f[u][0]+=max(f[end[i]][0],f[end[i]][1]);
		f[u][1]+=f[end[i]][0];
	}
	return max(f[u][0],f[u][1]);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		addedge(a,b);
	}
	memset(f,0,sizeof(f));
	printf("%d",F(1,1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

