/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXNM=2000000;
const int MAXT=1000050;
int d[MAXNM][2],ori[MAXNM],n,m,T;
int x[2][MAXT],y[2][MAXT],typ[MAXT];
bool die[MAXNM];
inline int idx(int x,int y) { return (x-1)*(m+1)+y; }
void read1n(int &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void setp(int t)
{
	for(int i=1;i<=T;i++)
	{
		d[idx(x[1][i],y[1][i])][(typ[i]>>t)&1]++;
		d[idx(x[1][i],y[0][i]-1)][(typ[i]>>t)&1]--;
		d[idx(x[0][i]-1,y[1][i])][(typ[i]>>t)&1]--;
		d[idx(x[0][i]-1,y[0][i]-1)][(typ[i]>>t)&1]++;
	}
	return;
}
void count()
{
	for(int k=0;k<2;k++)
	{
		for(int i=1;i<=n;i++)
			d[idx(i,0)][k]+=d[idx(i-1,0)][k];
		for(int i=1;i<=m;i++)
			d[idx(0,i)][k]+=d[idx(0,i-1)][k];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				d[idx(i,j)][k]=d[idx(i,j)][k]+d[idx(i-1,j-1)][k]-d[idx(i,j-1)][k]-d[idx(i-1,j)][k];
	}
	return;
}
int main()
{
	memset(die,false,sizeof(die));
	read1n(n);
	read1n(m);
	read1n(T);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			read1n(ori[idx(i,j)]);
	for(int i=1;i<=T;i++)
	{
		read1n(x[0][i]);
		read1n(x[1][i]);
		read1n(y[0][i]);
		read1n(y[1][i]);
		read1n(typ[i]);
	}
	for(int t=0;t<20;t++)
	{
		memset(d,0,sizeof(d));
		setp(t);
		count();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

