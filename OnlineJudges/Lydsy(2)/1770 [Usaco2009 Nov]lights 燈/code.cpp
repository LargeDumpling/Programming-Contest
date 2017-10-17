#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool f[40][40];
int n,m,ans=2147483647,tot;
bool fInal[40];
void gauss()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=i;!f[j][i]&&j<=n;j++);
		if(j>n)continue;
		for(k=i;i!=j&&k<=n+1;k++)swap(f[i][k],f[j][k]);
		for(j=1;j<=n;j++)if(i!=j&&f[j][i])for(k=i;k<=n+1;k++)f[j][k]^=f[i][k];
	}
}
void DFS(int u)
{
	if(tot>=ans)return;
	if(!u)
	{
		ans=tot;
		return;
	}
	if(f[u][u])
	{
		bool t=f[u][n+1];
		for(int i=u+1;i<=n;i++)t^=(f[u][i]&fInal[i]);
		fInal[u]=t;
		if(t)tot++;
		DFS(u-1);
		if(t)tot--;
	}
	else
	{
		fInal[u]=0;DFS(u-1);
		fInal[u]=1;tot++;DFS(u-1);tot--;
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i][i]=f[i][n+1]=true;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		f[a][b]=f[b][a]=1;
	}
	gauss();
	DFS(n);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

