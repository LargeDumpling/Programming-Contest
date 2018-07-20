//LargeDumpling
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef struct Poi vec;
struct Poi
{
	int x,y;
	Poi(const int &X=0,const int &Y=0):x(X),y(Y) { }
	bool operator<(const Poi &P)const
	{
		return x==P.x?y<P.y:x<P.x;
	}
	bool operator==(const Poi &P)const
	{
		return x==P.x&&y==P.y;
	}
	Poi operator-(const Poi &P)const
	{
		return Poi(x-P.x,y-P.y);
	}
}p[20],dp[20][20],h[400];
int m,hn,ans,cnt[400];
bool vis[20];
int gcd(int a,int b)
{
	int t;
	while(b)
	{
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
void DFS(int x,int num)
{
	while(vis[x]) x--;
	if(x==0)
	{
		ans=max(ans,num);
		return;
	}
	for(int i=x-1;i;i--) if(!vis[i])
	{
		vis[i]=true;
		int t=lower_bound(h+1,h+hn+1,dp[x][i])-h;
		cnt[t]++;
		DFS(x-1,num+cnt[t]-1);
		cnt[t]--;
		vis[i]=false;
	}
	return;
}
int main()
{
	memset(vis,false,sizeof(vis));
	hn=ans=0;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=p[j]-p[i];
			int t=gcd(abs(dp[i][j].x),abs(dp[i][j].y));
			if(t!=0) dp[i][j].x/=t,dp[i][j].y/=t;
			if(dp[i][j].x<0)
			{
				dp[i][j].x=-dp[i][j].x;
				dp[i][j].y=-dp[i][j].y;
			}
			else if(dp[i][j].x==0)
				dp[i][j].y=abs(dp[i][j].y);
			if(i!=j)
				h[++hn]=dp[i][j];
		}
	sort(h+1,h+hn+1);
	hn=unique(h+1,h+hn+1)-h-1;
	DFS(m,0);
	printf("%d",ans);
	return 0;
}


