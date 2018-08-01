/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long num[205][205],A[25];
int ord[205][205];
int L,n;
void pre_calc()
{
	n=(L&1)?L:L*2;
	num[0][0]=A[0];
	ord[0][0]=0;
	for(int i=1;i<n;i++)
	{
		ord[0][i]=(ord[0][i-1]+i)%L;
		num[0][i]=A[ord[0][i]];
	}
	for(int i=1;i<n;i++)
		for(int j=0;j<n;j++)
		{
			ord[i][j]=(ord[i-1][j]+i+j+1)%L;
			num[i][j]=A[ord[i][j]];
		}
	for(int i=1;i<n;i++)
	{
		num[0][i]+=num[0][i-1];
		num[i][0]+=num[i-1][0];
	}
	for(int i=1;i<n;i++)
		for(int j=1;j<n;j++)
			num[i][j]=num[i][j]-num[i-1][j-1]+num[i][j-1]+num[i-1][j];
	return;
}
long long calc(long long x,long long y)
{
	if(x<0||y<0) return 0;
	long long a,b,c,d,sum=0;
	a=(x+1)/n;
	b=(x+1)%n;
	c=(y+1)/n;
	d=(y+1)%n;
	sum=a*c*num[n-1][n-1];
	if(b) sum+=c*num[b-1][n-1];
	if(d) sum+=a*num[n-1][d-1];
	if(b&&d) sum+=num[b-1][d-1];
	return sum;
}
int main()
{
	int T_T,Q;
	long long x1,x2,y1,y2;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&L);
		for(int i=0;i<L;i++)
			scanf("%lld",&A[i]);
		pre_calc();
		scanf("%d",&Q);
		while(Q--)
		{
			scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
			printf("%lld\n",calc(x2,y2)+calc(x1-1,y1-1)-calc(x1-1,y2)-calc(x2,y1-1));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

