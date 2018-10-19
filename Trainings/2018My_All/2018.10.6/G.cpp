/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1050;
int n,m,k,w[3][MAXN][MAXN];
double ans=1e10,s[3][MAXN][MAXN],left[3][MAXN][MAXN],right[3][MAXN][MAXN];
void read1n(int &x)
{
	char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void pre_calc()
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int t=0;t<3;t++)
				s[t][i][j]=left[t][i][j]=right[t][i][j]=0;
	for(int t=0;t<3;t++)
		for(int j=1;j<=m;j++)
		{
			s[t][1][j]=s[t][1][j-1]+w[t][1][j];
			if(k<=j) for(int d=0;d<k;d++)
				left[t][1][j]+=w[t][1+d][j-d];
			if(j+k-1<=m) for(int d=0;d<k;d++)
				right[t][1][j]+=w[t][1+d][j+d];
		}
	for(int t=0;t<3;t++)
	{
		for(int i=2;i<=n-k+1;i++)
			for(int j=1;j<=m;j++)
			{
				if(k<=j&&j<m)
			}
	}
}
int main()
{
	read1n(n); read1n(m); read1n(k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			read1n(w[2][i][j]);
			w[0][i][j]=i*w[2][i][j];
			w[1][i][j]=j*w[2][i][j];
		}
	pre_calc();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

