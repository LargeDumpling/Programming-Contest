#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,ans=-1;
bool f[2050][1050];
bool gauss()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=m&&!f[j][i];j++);
		if(j==m+1)return false;
		ans=max(ans,j);
		for(k=i;i!=j&&k<=n+1;k++)swap(f[i][k],f[j][k]);
		for(j=i+1;j<=m;j++)for(k=n+1;f[j][i]&&k;k--)f[j][k]^=f[i][k];
	}
	for(i=n;i;i--)
		for(j=n;j>i;j--)
			f[i][n+1]^=(f[i][j]&f[j][n+1]);
	return true;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	char tex[1050];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",tex);
		for(int j=1;j<=n;j++)f[i][j]=tex[j-1]=='1';
		scanf("%s",tex);
		f[i][n+1]=tex[0]=='1';
	}
	if(!gauss())
		printf("Cannot Determine");
	else
	{
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			if(f[i][n+1])
				printf("?y7M#\n");
			else
				printf("Earth\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

