/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-10	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,f[205][205][205],num[205];
int F(int l,int r,int rem)
{
	if(f[l][r][rem]!=-1) return f[l][r][rem];
	if(r<l) return f[l][r][rem]=0;
	int rr=r,&ans=f[l][r][rem];
	while(l<rr&&num[rr-1]==num[rr]) rr--;
	ans=F(l,rr-1,0)+(r-rr+rem+1)*(r-rr+rem+1);
	for(int ll=l;ll<rr;ll++) if(num[ll]==num[r]&&num[ll]!=num[ll+1])
		ans=max(ans,F(ll+1,rr-1,0)+F(l,ll,r-rr+1+rem));
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		printf("Case %d: ",cAse);
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&num[i]);
		memset(f,-1,sizeof(f));
		printf("%d\n",F(1,n,0));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

