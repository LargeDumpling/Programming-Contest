/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-10-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int n,l[MAXN],r[MAXN];
long long ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	sort(l+1,l+n+1); sort(r+1,r+n+1);
	ans=n;
	for(int i=1;i<=n;i++)
		ans+=max(l[i],r[i]);
	printf("%I64d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

