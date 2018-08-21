/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=998244353;
const int MAXN=505;
int T_T,n;
int d[MAXN][MAXN],e[MAXN][MAXN];
int st[124780][2];
inline int min(int a,int b) { return a<b?a:b; }
inline int multi(int x,int m)
{
	int ans;
	for(ans=0;m;m>>=1)
	{
		if(m&1)
		{
			ans+=x;
			if(mod<=ans)
				ans-=mod;
		}
		x+=x;
		if(mod<=x)
			x-=mod;
	}
	return ans;
}
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
int main()
{
	int limit;
	register int x,ans;
	//scanf("%d",&T_T);
	read1n(T_T);
	while(T_T--)
	{
		limit=ans=0;
		//scanf("%d",&n);
		read1n(n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				//scanf("%d",&d[i][j]);
				read1n(d[i][j]);
				e[i][j]=d[i][j];
			}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				st[limit][0]=i;
				st[limit++][1]=j;
			}
		for(int i=0;i<limit-1;i++)
			for(int j=i+1;j<limit;j++)
			{
				x=d[st[i][0]][st[j][0]];
				x=min(x,d[st[i][0]][st[j][1]]);
				x=min(x,d[st[i][1]][st[j][0]]);
				x=min(x,d[st[i][1]][st[j][1]]);
				x=(x<<1);
				if(mod<=x) x-=mod;
				//x=((x+e[st[i][0]][st[i][1]])%mod+e[st[j][0]][st[j][1]])%mod;
				ans+=x;
				if(mod<=ans) ans-=mod;
				/*x+=e[st[i][0]][st[i][1]];
				if(mod<=x) x-=mod;
				x+=e[st[j][0]][st[j][1]];
				if(mod<=x) x-=mod;*/
			}
		for(int i=0;i<limit;i++)
		{
			ans+=multi(e[st[i][0]][st[i][1]],limit-1);
			if(mod<=ans) ans-=mod;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

