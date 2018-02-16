/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=400050;
int Q,lastans=0,sz=1;
int fa[MAXN][20],fa2[MAXN][20],num[MAXN];
long long mAx[MAXN][20],sum[MAXN][20];
template<typename Ty>
void read1n(Ty &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
long long query(int u,long long x)
{
	long long ans=1;
	int i;
	x-=num[u];
	if(x<0) return 0;
	while(1<u)
	{
		for(i=19;0<=i&&(x<sum[u][i]||fa2[u][i]==0);i--);
		if(0<=i&&sum[u][i]<=x)
		{
			x-=sum[u][i];
			u=fa2[u][i];
			ans+=(1<<i);
		}
	}
	return ans;
}
int fInd(int u,long long k)
{
	int i;
	while(true)
	{
		for(i=19;0<=i&&(k<=mAx[u][i]||fa[u][i]==0);i--);
		if(i==-1) return fa[u][0];
		u=fa[u][i];
	}
	return u;
}
int main()
{
	int op;
	long long R,X;
	read1n(Q);
	fa[1][0]=0;
	fa2[1][0]=0;
	mAx[1][0]=0;
	while(Q--)
	{
		read1n(op);
		read1n(R); R^=lastans;
		read1n(X); X^=lastans;
		if(op==1)
		{
			num[++sz]=X;
			fa[sz][0]=R;
			mAx[sz][0]=num[R];
			for(int i=1;i<20;i++)
			{
				fa[sz][i]=fa[fa[sz][i-1]][i-1];
				mAx[sz][i]=max(mAx[sz][i-1],mAx[fa[sz][i-1]][i-1]);
			}
			fa2[sz][0]=fInd(sz,num[sz]);
			sum[sz][0]=num[fa2[sz][0]];
			for(int i=1;i<20;i++)
			{
				fa2[sz][i]=fa2[fa2[sz][i-1]][i-1];
				sum[sz][i]=sum[sz][i-1]+sum[fa2[sz][i-1]][i-1];
			}
		}
		else cout<<(lastans=query(R,X))<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

