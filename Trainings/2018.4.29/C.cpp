/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-04-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int T_T,n,q;
int f[MAXN],size[MAXN],w[MAXN],sz;
void init()
{
	memset(w,-1,sizeof(w));
	for(int i=0;i<MAXN;i++)
	{
		f[i]=i;
		size[i]=1;
		w[i]=i;
	}
	return;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int fInd(int x)
{
	while(f[x]!=f[f[x]]) f[x]=fInd(f[x]);
	return f[x];
}
void merge(int u,int v)
{
	u=fInd(u); v=fInd(v);
	if(u==v) return;
	f[v]=u;
	size[u]+=size[v];
	return;
}
int main()
{
	int op,u,v;
	read1n(T_T);
	for(int T=1;T<=T_T;T++)
	{
		printf("Case #%d:\n",T);
		init();
		read1n(n); read1n(q);
		sz=n;
		while(q--)
		{
			read1n(op);
			switch(op)
			{
				case 1:
					read1n(u);
					read1n(v);
					merge(w[u],w[v]);
					break;
				case 2:
					read1n(u);
					v=fInd(w[u]);
					size[v]--;
					w[u]=++sz;
					break;
				case 3:
					read1n(u);
					v=fInd(w[u]);
					printf("%d\n",size[v]);
					break;
				case 4:
					read1n(u);
					read1n(v);
					puts(fInd(w[u])==fInd(w[v])?"YES":"NO");
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

