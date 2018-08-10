/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-09	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool aaa;
const int MAXN=1024;
const int M=1024;
int n,m;
short int f[2][MAXN][10][M<<1];
int last[52],Log[MAXN];
long long ans=0;
char str[MAXN][MAXN];
int idx(char ch)
{
	if('A'<=ch&&ch<='Z')
		return ch-'A';
	return ch-'a'+26;
}
void pre_calc()
{
	Log[0]=-1;
	for(int i=1;i<MAXN;i++)
		Log[i]=Log[i>>1]+1;
	for(int i=n;i;i--)
	{
		for(int j=0;j<52;j++)
			last[j]=m+1;
		for(int j=m;j;j--)
		{
			f[0][i][0][j+M]=last[idx(str[i][j])];
			last[idx(str[i][j])]=j;
		}
	}
	for(int j=m;j;j--)
	{
		for(int i=0;i<52;i++)
			last[i]=n+1;
		for(int i=n;i;i--)
		{
			f[1][i][0][j+M]=last[idx(str[i][j])];
			last[idx(str[i][j])]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int p=M-1;p;p--)
		{
			f[0][i][0][p]=min(f[0][i][0][p<<1],f[0][i][0][p<<1|1]);
			f[1][i][0][p]=min(f[1][i][0][p<<1],f[1][i][0][p<<1|1]);
		}
	}
	for(int i=n;i;i--)
	{
		for(int k=1;i+(1<<k)-1<=n;k++)
			for(int p=(M<<1)-1;p;p--)
			{
				f[0][i][k][p]=min(f[0][i][k-1][p],f[0][i+(1<<(k-1))][k-1][p]);
				f[1][i][k][p]=min(f[1][i][k-1][p],f[1][i+(1<<(k-1))][k-1][p]);
			}
	}
	return;
}
int min(short a,int b)
{
	return a<b?a:b;
}
int query(int x1,int x2,int L,int R,int k)
{
	short ans=32767,t=Log[x2-x1+1];
	for(L=L+M-1,R=R+M+1;L<R-1;L>>=1,R>>=1)
	{
		if(!(L&1)) ans=min(ans,min(f[k][x1][t][L^1],f[k][x2-(1<<t)+1][t][L^1]));
		if(R&1) ans=min(ans,min(f[k][x1][t][R^1],f[k][x2-(1<<t)+1][t][R^1]));
	}
	return ans;
}
bool bbb;
int main()
{
	//freopen("J.in","r",stdin);
	fprintf(stderr,"%lf\n",(double)(&bbb-&aaa)/1024./1024.);
	int h,w,limith,limitw;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	pre_calc();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			limitw=f[0][h=i][0][(w=j)+M];
			limith=f[1][h][0][w+M];
			while(w<limitw-1&&w<m)
			{
				limitw=min(limitw,f[0][h][0][(++w)+M]);
				limith=min(limith,f[1][h][0][w+M]);
			}
			ans=ans+(w-j+1);
			while(true)
			{
				while(h==limith-1&&j<w)
				{
					limitw=min(limitw,query(i,h,j,--w,0));
					limith=query(i,h,j,w,1);
				}
				if(h==limith-1&&w==j)
					break;
				limitw=min(limitw,query(i,++h,j,w,0));
				while(limitw<=w)
				{
					w=limitw-1;
					limitw=min(limitw,query(i,h,j,w,0));
				}
				ans=ans+(w-j+1);
				limith=query(i,h,j,w,1);
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

