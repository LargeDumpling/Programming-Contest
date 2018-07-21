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
#include<set>
#include<algorithm>
using namespace std;
const int MAXN=400050;
struct jz
{
	int id;
	long long x;
	jz(const int &ID=0,const long long &X=0):id(ID),x(X) { }
	bool operator<(const jz &X)const { return x==X.x?id<X.id:x<X.x; }
	bool operator==(const jz &X)const { return x==X.x&&id==X.id; }
};
int n,fir[MAXN],end[MAXN<<1],next[MAXN<<1],ed=0;
long long w[MAXN],f[MAXN],g[MAXN][3][2];
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
template<typename Ty>
void read1n(Ty &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void init()
{
	memset(w,0,sizeof(w));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	return;
}
void DFS1(int u,int fa)
{
	f[u]=w[u];
	for(int i=fir[u];i;i=next[i]) if(end[i]!=fa)
	{
		DFS1(end[i],u);
		f[u]=max(f[u],f[end[i]]+w[u]);
	}
	return;
}
set<jz> Sf,Sg;
void DFS2(int u,int fa)
{
	int v;
	g[u][0][0]=g[u][0][1]=f[u];
	for(int i=fir[u];i;i=next[i]) if((v=end[i])!=fa)
	{
		DFS2(v,u);
		g[u][0][0]=max(g[u][0][0],g[v][0][0]);
		g[u][0][1]=max(g[u][0][1],g[v][0][1]+w[u]);
		g[u][1][0]=max(g[u][1][0],g[v][1][0]);
		g[u][1][1]=max(g[u][1][1],g[v][1][1]+w[u]);
		g[u][2][0]=max(g[u][2][0],g[v][2][0]);
		g[u][2][1]=max(g[u][2][1],g[v][2][1]+w[u]);
	}
	Sf.clear();
	Sg.clear();
	for(int i=fir[u];i;i=next[i]) if((v=end[i])!=fa)
	{
		Sf.insert(jz(v,f[v]));
		Sg.insert(jz(v,g[v][0][0]));
	}
	for(int i=fir[u];i;i=next[i]) if((v=end[i])!=fa)
	{
		set<jz>::iterator itf,itg;
		itf=Sf.find(jz(v,f[v]));
		itg=Sg.find(jz(v,g[v][0][0]));
		Sf.erase(itf);
		Sg.erase(itg);

		if(Sf.size()!=0)
		{
			itf=Sf.end(); itf--;
			g[u][0][0]=max(g[u][0][0],f[v]+itf->x+w[u]);
			if(itf!=Sf.begin())
			{
				int temid=itf->id,temx=itf->x;
				itf--;
				g[u][1][0]=max(g[u][1][0],g[v][0][0]+temx+itf->x+w[u]);
				g[u][2][0]=max(g[u][2][0],g[v][1][0]+temx+itf->x+w[u]);
				if(Sg.size()!=0)
				{
					itg=Sg.end(); itg--;
					if((itg->id==temid||itg->id==itf->id)&&itg!=Sg.begin())
					{
						itg--;
						if((itg->id==temid||itg->id==itf->id)&&itg!=Sg.begin())
						{
							itg--;
							g[u][2][0]=max(g[u][2][0],g[v][0][0]+itg->x+temx+itf->x+w[u]);
							itg++;
						}
						else if(itg->id!=temid&&itg->id!=itf->id)
							g[u][2][0]=max(g[u][2][0],g[v][0][0]+itg->x+temx+itf->x+w[u]);
						itg++;
					}
					else if(itg->id!=temid&&itg->id!=itg->id)
						g[u][2][0]=max(g[u][2][0],g[v][0][0]+itg->x+temx+itf->x+w[u]);
					itg++;
				}
			}
		}

		if(Sg.size()!=0)
		{
			itg=Sg.end(); itg--;
			g[u][1][0]=max(g[u][1][0],g[v][0][0]+itg->x);
			g[u][2][0]=max(g[u][2][0],g[v][1][0]+itg->x);
			g[u][1][1]=max(g[u][1][1],g[v][0][1]+w[u]+itg->x);
			if(itg!=Sg.begin())
			{
				int temx=itg->x;
				itg--;
				g[u][2][0]=max(g[u][2][0],g[v][0][0]+temx+itg->x);
				g[u][2][1]=max(g[u][2][1],g[v][0][1]+temx+itg->x);
			}
		}

		Sf.insert(jz(v,f[v]));
		Sg.insert(jz(v,g[v][0][0]));
	}
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
	DFS1(1,1);
	DFS2(1,1);
	printf("%lld",max(g[1][2][0],g[1][2][1]));
	fclose(stdin);
	fclose(stdout);
	return 0;
}

