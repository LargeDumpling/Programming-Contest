#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<bitset>
#include<algorithm>
using namespace std;
int n,m,ans=-1;
bitset<1050>f[2050];
bool gauss()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=m&&!f[j][i];j++);
		if(j==m+1)return false;
		ans=max(ans,j);
		if(i!=j)swap(f[i],f[j]);
		for(j=1;j<=m;j++)if(i!=j&&f[j][i])f[j]^=f[i];
	}
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

