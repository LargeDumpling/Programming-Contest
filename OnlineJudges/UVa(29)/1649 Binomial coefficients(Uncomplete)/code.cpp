/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct jp
{
	int fir,sec;
	jp(int A=0,int B=0):fir(A),sec(B){}
	bool operator<(jp X)const
	{
		return fir==X.fir?sec<X.sec:fir<X.fir;
	}
	bool operator==(jp X)const{return !(*this<X)&&!(X<*this);}
}ans[10050];
long long C[51][51];
int an;
void pre_calc()
{
	C[0][0]=1;
	for(int i=1;i<=50;i++)
		for(int j=0;j<=i;j++)
			C[i][j]=j?C[i-1][j-1]+C[i-1][j]:1;
	return;
}
void insert(int n,int m)
{
	ans[an++]=jp(n,m);
	if(n!=(m<<1));
	ans[an++]=jp(n,n-m);
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T,l,r,mid;
	long long n;
	pre_calc();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		an=0;
		for(int k=1;k<=25;k++)
		{
			l=k;r=k<<1;
			while(l<r-1)
			{
				mid=(l+r)>>1;
				if(C[mid][k]>n)
					r=mid;
				else
					l=mid;
			}
			if(C[l][k]==n)
				insert(l,k);
			if(C[r][k]==n)
				insert(r,k);
		}
		sort(ans,ans+an);
		an=unique(ans,ans+an)-ans;
		printf("%d\n",an);
		for(int i=0;i<an;i++)
			printf("(%d,%d)%c",ans[i].fir,ans[i].sec,i==an-1?'\n':' ');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

