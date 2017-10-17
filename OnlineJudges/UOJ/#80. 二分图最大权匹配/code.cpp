/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-29	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int nl,nr,n,m,G[405][405],l[405],r[405],par[405];
bool L[405],R[405];
void updata()
{
	int a=1<<30;
	for(int i=1;i<=n;i++) if(L[i])
		for(int j=1;j<=n;j++) if(!R[i])
			a=min(a,l[i]+r[j]-G[i][j]);
	for(int i=1;i<=n;i++)
	{
		if(L[i]) l[i]-=a;
		if(R[i]) r[i]+=a;
	}
}
bool match(int u)
{
	L[u]=true;
	for(int i=1;i<=n;i++) if(l[u]+r[i]==G[u][i]&&!R[i])
	{
		R[i]=true;
		if(!par[i]||match(par[i]))
		{
			par[i]=u;
			return true;
		}
	}
	return false;
}
void KM()
{
	memset(par,0,sizeof(par));
	memset(r,0,sizeof(r));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			l[i]=max(l[i],G[i][j]);
	for(int i=1;i<=n;i++)
	{
		while(true)
		{
			memset(L,false,sizeof(L));
			memset(R,false,sizeof(R));
			if(match(i)) break;
			else updata();
		}
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b,c,ans;
	scanf("%d%d%d",&nl,&nr,&m);
	n=max(nl,nr);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		G[a][b]=G[b][a]=max(G[a][b],c);
	}
	KM();
	ans=0;
	for(int i=1;i<=nl;i++) if(par[i])
	{
		if(par[i]>nr) par[i]=0;
		else
		{
			ans+=l[i]+r[par[i]];
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=nl;i++)
		printf("%d ",par[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

