/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,d,num[105];
int main()
{
	int l,r,ans;
	scanf("%d%d",&n,&d);
	ans=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	r=1;
	for(l=1;l<=n;l++)
	{
		while(r<n&&num[r+1]-num[l]<=d) r++;
		if(num[r]-num[l]<=d)
			ans=min(ans,n-(r-l+1));
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
