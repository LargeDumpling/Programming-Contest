/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,k,T,a[10000050],b,c,p,ans=0,l,r;
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int cnt=0;
	scanf("%lld%lld%lld%lld%lld%lld%lld",&n,&k,&T,&a[0],&b,&c,&p);
	for(int i=1;i<=n;i++)a[i]=(long long)(a[i-1]*b+c)%p;
	r=0;l=1;
	for(int i=1;i<=n;i++)
	{
		r++;
		if(a[r]>=T)cnt++;
		while(k<r-l+1&&((cnt>k&&a[l]>=T)||(cnt>=k&&a[l]<T)))
			if(a[l++]>=T)cnt--;
		if(cnt>=k&&r-l+1>=k)
			ans+=l;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

