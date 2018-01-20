/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2017-12-12	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=5050;
int n,a[MAXN],h[MAXN],cnt[MAXN],ans;
int main()
{
	scanf("%d",&n);
	h[0]=ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		h[++h[0]]=a[i];
	}
	sort(h+1,h+h[0]+1);
	h[0]=unique(h+1,h+h[0]+1)-h-1;
	for(int i=1;i<=n;i++)
		cnt[lower_bound(h+1,h+h[0]+1,a[i])-h]++;
	for(int i=1;i<=h[0];i++)
		ans=max(ans,cnt[i]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

