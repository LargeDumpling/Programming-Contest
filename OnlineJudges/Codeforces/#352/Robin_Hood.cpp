/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-05-18	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=500050;
int n,k;
long long num[MAXN],p[MAXN],s[MAXN],low,upp;
int main()
{
	freopen("code.in","r",stdin);
	long long l,mid,r;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++) p[i]=p[i-1]+num[i];
	for(int i=n;1<=i;i--) s[i]=s[i+1]+num[i];
	l=0; r=1e9+1;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		long long pos=lower_bound(num+1,num+n+1,mid)-num,cnt=0;
		cnt=(pos-1)*mid-p[pos-1];
		if(cnt<=k) l=mid;
		else r=mid;
	}
	low=l;
	l=0; r=1e9+1;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		long long pos=upper_bound(num+1,num+n+1,mid)-num,cnt=0;
		if(pos==n+1)
		{
			r=mid;
			continue;
		}
		cnt=s[pos]-(n-pos)*mid;
		if(cnt<=k) r=mid;
		else l=mid;
	}
	upp=r;
	printf("%lld",max(0LL,upp-low));
	return 0;
}

