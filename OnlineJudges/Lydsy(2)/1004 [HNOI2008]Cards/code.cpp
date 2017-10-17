#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int sr,sb,sg,m,mod,n;
int a[65][65],ans=0,d[65],dn,dp[25][25][25];
bool exist[65];
int f(int x)
{
	int p;
	memset(d,dn=0,sizeof(d));
	memset(exist,true,sizeof(exist));
	for(int i=1;i<=n;i++)
	{
		if(!exist[a[x][i]])
			continue;
		d[++dn]=1;
		p=i;
		exist[i]=false;
		while(exist[a[x][p]])
		{
			d[dn]++;
			p=a[x][p];
			exist[a[x][p]]=false;
		}
	}
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(p=1;p<=dn;p++)
		for(int i=sr;i>=0;i--)
			for(int j=sb;j>=0;j--)
				for(int k=sg;k>=0;k--)
				{
					if(i>=d[p])dp[i][j][k]=(dp[i][j][k]+dp[i-d[p]][j][k])%mod;
					if(j>=d[p])dp[i][j][k]=(dp[i][j][k]+dp[i][j-d[p]][k])%mod;
					if(k>=d[p])dp[i][j][k]=(dp[i][j][k]+dp[i][j][k-d[p]])%mod;
				}
	return dp[sr][sb][sg];
}
void exgcd(int a,int b,int &x,int &y)
{
     if(b==0){x=1;y=0;return;}
     exgcd(b,a%b,x,y);
     int t=x;x=y;y=t-a/b*y;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d%d%d%d%d",&sr,&sb,&sg,&m,&mod);
	n=sr+sb+sg;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	m++;
	for(int i=1;i<=n;i++)a[m][i]=i;
	for(int i=1;i<=m;i++)
		ans=(ans+f(i))%mod;
	int x,y;
	exgcd(m,mod,x,y);
	while(x<=0)x+=mod;
	printf("%d",ans*x%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

