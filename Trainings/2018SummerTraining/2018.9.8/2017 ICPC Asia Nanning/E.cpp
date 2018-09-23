/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-18	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,r,sz=0,ch[200000][2];
unsigned long long k,num[200000][3];
long double ans[200000][3],w;
template<typename Ty>
void read1n(Ty &x)
{
	char ch;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch==-1) return;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	return;
}
void clear(int u)
{
	ans[u][0]
		=ans[u][1]
		=ans[u][2]
		=num[u][0]
		=num[u][1]
		=num[u][2]
		=0;
	return;
}
void calc(int u,unsigned long long len)
{
	if(num[u][0]==len)
	{
		ans[u][0]=1;
		return;
	}
	else if(num[u][1]==len)
	{
		ans[u][1]=1;
		return;
	}
	else if(num[u][2]==len)
	{
		ans[u][2]=1;
		return;
	}
	unsigned long long mid=len>>1;
#define lch ch[u][0]
#define rch ch[u][1]
	clear(lch=++sz);
	clear(rch=++sz);
	if(mid<=num[u][0])
	{
		num[lch][0]=mid;
		num[rch][0]=num[u][0]-mid;
		num[rch][1]=num[u][1];
		num[rch][2]=num[u][2];
	}
	else if(num[u][0]<mid&&mid<=num[u][0]+num[u][1])
	{
		num[lch][0]=num[u][0];
		num[lch][1]=mid-num[u][0];
		num[rch][1]=num[u][1]+num[u][0]-mid;
		num[rch][2]=num[u][2];
	}
	else if(num[u][0]+num[u][1]<mid)
	{
		num[lch][0]=num[u][0];
		num[lch][1]=num[u][1];
		num[lch][2]=mid-num[u][0]-num[u][1];
		num[lch][2]=len-mid;
	}
	calc(lch,mid); calc(rch,mid);
	long double cl[3][3]={
		{w,w,w},
		{1-w,w,1-w},
		{1-w,w,w}},cr[3][3]={
		{1-w,w,w},
		{1-w,1-w,1-w},
		{1-w,w,1-w}};
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			ans[u][i]+=ans[lch][i]*ans[rch][j]*cl[i][j];
			ans[u][j]+=ans[lch][i]*ans[rch][j]*cr[j][i];
		}
#undef lch
#undef rch
	return;
}
int main()
{
	double p;
	scanf("%d",&T_T);
	while(T_T--)
	{
		clear(sz=1);
		read1n(r);
		read1n(k);
		scanf("%lf",&p); w=p;
		num[1][0]=k-1;
		num[1][1]=(1ULL<<r)-k;
		num[1][2]=1;
		calc(1,1ULL<<r);
		printf("%lf\n",(double)ans[1][2]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

