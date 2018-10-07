/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
const double INF=1e10;
int n,m,k,w[3][MAXN][MAXN],sw[3][MAXN][MAXN];
double f[MAXN][MAXN],xm[MAXN][MAXN],ym[MAXN][MAXN],num;
double slope[2][3][MAXN][MAXN];
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
double dis(double x,double y) { return sqrt(x*x+y*y); }
double sum(int t,int x,int y)
{
	double ans=0;
	for(int i=0;i<k;i++)
		for(int j=-i;j<=i;j++)
			ans+=w[t][x+i][y+j];
	return ans;
}
double pre[3][MAXN][MAXN];
void pre_calc()
{
	for(int i=0;i<k;i++)
		for(int j=-i;j<=i;j++)
			for(int t=0;t<3;t++)
				sw[t][1][k]+=w[t][1+i][j+k];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int t=0;t<3;t++)
				pre[t][i][j]=j?pre[t][i][j-1]+w[t][i][j]:0;
	for(int j=1;j<=m;j++)
	{
		if(j+k-1<=m)
		{
			for(int t=0;t<3;t++)
			{
				slope[0][t][1][j]=w[t][1][j];
				for(int i=1;i<k;i++)
					slope[0][t][1][j]+=w[t][1+i][j+i];
			}
		}
		if(k<=j)
		{
			for(int t=0;t<3;t++)
			{
				slope[1][t][1][j]=w[t][1][j];
				for(int i=1;i<k;i++)
					slope[1][t][1][j]+=w[t][1+i][j-i];
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j+k-1<=m)
				for(int t=0;t<3;t++)
					slope[0][t][i][j]=slope[0][t][i-1][j-1]+w[t][i+k-1][j+k-1]-w[t][i-1][j-1];
			if(k<=j)
				for(int t=0;t<3;t++)
					slope[1][t][i][j]=slope[0][t][i-1][j+1]+w[t][i+k-1][j-k+1]-w[t][i-1][j+1];
		}
	}
	for(int i=1;i<=n-k+1;i++)
	{
		if(i+k-1<n) for(int t=0;t<3;t++)
			sw[t][i+1][k]=sw[t][i][k]+w[t][i][k]
				+pre[t][i+k][k+k-1]
				-slope[0][t][i][k]-slope[1][t][i][k];
		for(int j=k;j+k-1<n;k++) if(j+k-1<n)
			for(int t=0;t<3;t++)
				sw[t][i][j+1]=sw[t][i][j]+slope[0][t][i][j+1]-slope[1][t][i][j];
	}
	return;
}
double calc(int x,int y)
{
	double weight=sum(2,x,y),wx=sum(0,x,y),wy=sum(1,x,y);
	return dis(wx/weight-x,wy/weight-y);
}
int main()
{
	double ans=INF;
	read1n(n); read1n(m);
	read1n(k); num=k*k; // input & calculate the number of X in the triangle.
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			read1n(w[2][i][j]); // w[2][i][j] is the weight of the X located @(x,y)
			w[0][i][j]=w[2][i][j]*i;
			w[1][i][j]=w[2][i][j]*j;
		}
	pre_calc();
	for(int i=1;i<=n-k+1;i++)
		for(int j=k;j<=m-k+1;j++)
			ans=min(ans,calc(i,j));
	printf("%lf",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

