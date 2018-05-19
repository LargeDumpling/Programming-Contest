/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-05-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,m,ans[MAXN];
long long a[MAXN],b[MAXN];
bool check(int k)
{
	for(int i=1;i<m;i++)
		if(a[k+i]+b[i]!=a[k+i-1]+b[i-1])
			return false;
	return true;
}
int main()
{
	freopen("Pro1.in","r",stdin);
	freopen("Pro1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(int i=0;i<m;i++)
		scanf("%lld",&b[i]);
	ans[0]=0;
	for(int i=0;i<=n-m;i++)
		if(check(i))
			ans[++ans[0]]=i;
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

