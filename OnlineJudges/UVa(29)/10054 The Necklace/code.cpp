#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n,end[2200],next[2200],fir[1100],ed=1,now[1100],ans[2200],du[1100];
bool vis[2200];
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
int i;
void DFS(int u)
{
	for(i=fir[u];i&&ans[0]!=n+n+1;i=next[i])
	{
		if(vis[i]||vis[i^1])
			continue;
		vis[i]=true;
		DFS(end[i]);
		ans[++ans[0]]=u;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int c1,c2,pri=0,st;
	scanf("%d",&T);
//	printf("%d\n",T);
	for(int t=1;t<=T;t++)
	{
		memset(fir,0,sizeof(fir));
		memset(ans,0,sizeof(ans));
		memset(du,0,sizeof(du));
		memset(vis,false,sizeof(vis));
		pri=0;
		ed=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&c1,&c2);
			if(i==1)
				st=c1;
			addedge(c1+1000,i);
			du[c1+1000]++;
			if(du[c1+1000]&1)
				pri++;
			else
				pri--;
			du[c2+1000]++;
			if(du[c2+1000]&1)
				pri++;
			else
				pri--;
			addedge(c2+1000,i);
		}
//		printf("Case #%d %d\n",t,n);
		printf("%d\n",n);
		DFS(1000+st);
		if(pri||ans[0]!=n+n+1)
			printf("some beads may be lost\n");
		else
		{
			printf("%d",ans[1]-1000);
			for(int i=1;i<(ans[0]/2);i++)
				printf(" %d\n%d",ans[i*2+1]-1000,ans[i*2+1]-1000);
			printf(" %d\n",ans[ans[0]]-1000);
		}
		if(t!=T)
			printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

