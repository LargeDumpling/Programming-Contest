/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define low(x) (x&-x)
using namespace std;
int T,n,f[100050],num[20050],a[20050],b[20050],c[20050],d[20050];
long long ans;
void add(int pos)
{
	for(;pos<100050;pos+=low(pos))f[pos]++;
	return;
}
int query(int x)
{
	int sum;
	for(sum=0;x;x-=low(x))sum+=f[x];
	return sum;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(f,0,sizeof(f));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,ans=0,sizeof(d));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			a[i]=query(num[i]);
			b[i]=i-1-query(num[i]-1);
			add(num[i]);
		}
		memset(f,0,sizeof(f));
		for(int i=n;i;i--)
		{
			c[i]=n-i-query(num[i]-1);
			d[i]=query(num[i]);
			add(num[i]);
		}
		for(int i=1;i<=n;i++)
			ans+=(long long)a[i]*c[i]+(long long)b[i]*d[i];
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

