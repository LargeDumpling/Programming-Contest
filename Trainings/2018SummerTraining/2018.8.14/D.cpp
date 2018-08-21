/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=505;
const int INF=2147483647;
int n,pre[MAXN][MAXN],cn[2];
long long f[MAXN][MAXN],x[MAXN],y[MAXN];
struct jz
{
	long long d[3];
	jz(const long long &d0=0,const long long &d1=0,const long long &d2=0)
	{
		d[0]=d0;
		d[1]=d1;
		d[2]=d2;
	}
	bool operator<(const jz &X)const
	{
		if(d[0]==X.d[0]) return d[1]==X.d[1]?d[2]<X.d[2]:d[1]<X.d[1];
		return d[0]<X.d[0];
	}
}seg[2][MAXN];
long long F(int l,int r)
{
	if(f[l][r]!=-1) return f[l][r];
	if(l==r) return f[l][r]=0;
	f[l][r]=INF;
	for(int i=l;i<r;i++) if(F(l,i)+F(i+1,r)+x[i+1]-x[l]+y[i]-y[r]<f[l][r])
	{
		f[l][r]=F(l,i)+F(i+1,r)+x[i+1]-x[l]+y[i]-y[r];
		pre[l][r]=i;
	}
	return f[l][r];
}
void print(int l,int r)
{
	if(l==r) return;
	int t=pre[l][r];
	if(x[l]<x[t+1]) seg[0][++cn[0]]=jz(y[r],x[l],x[t+1]);
	if(y[r]<y[t]) seg[1][++cn[1]]=jz(x[l],y[r],y[t]);
	print(l,t);
	print(t+1,r);
	return;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int m;
	memset(f,-1,sizeof(f));
	memset(cn,0,sizeof(cn));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&y[i]);
	F(1,n);
	f[1][n]+=x[1]+y[n];
	if(x[1]!=0) seg[0][++cn[0]]=jz(0,0,x[1]);
	if(y[n]!=0) seg[1][++cn[1]]=jz(x[1],0,y[n]);
	print(1,n);
	for(int i=0;i<2;i++)
	{
		sort(seg[i]+1,seg[i]+cn[i]+1);
		m=cn[i];
		cn[i]=0;
		for(int j=1,k;j<=m;j=k+1)
		{
			for(k=j;k<=m-1&&seg[i][k].d[0]==seg[i][k+1].d[0]&&seg[i][k].d[2]==seg[i][k+1].d[1];k++);
			seg[i][j].d[2]=seg[i][k].d[2];
			seg[i][++cn[i]]=seg[i][j];
		}
	}
	printf("%d %lld\n",cn[0]+cn[1],f[1][n]);
	for(int i=1;i<=cn[0];i++)
		printf("%lld %lld %lld %lld\n",seg[0][i].d[2],seg[0][i].d[0],seg[0][i].d[1],seg[0][i].d[0]);
	for(int i=1;i<=cn[1];i++)
		printf("%lld %lld %lld %lld\n",seg[1][i].d[0],seg[1][i].d[2],seg[1][i].d[0],seg[1][i].d[1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

