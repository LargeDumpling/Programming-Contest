/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-11-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int L,n,num[55],f[55][55];
int min(int a,int b)
{
	return ((a)<(b)?(a):(b));
}
int dp(int l,int r)
{
	if(f[l][r]!=-1)return f[l][r];
	if(l==r)return (f[l][r]=0);
	f[l][r]=2147483647;
	for(int i=l;i<r;i++)
		f[l][r]=min(f[l][r],dp(l,i)+dp(i+1,r)+num[r]-num[l-1]);
	return f[l][r];
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%d",&L)==1&&L)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		num[n+1]=L;
		memset(f,-1,sizeof(f));
		printf("The minimum cutting is %d.\n",dp(1,n+1));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

