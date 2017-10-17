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
using namespace std;
int n,q,a,b,x,num[100050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int l,r,ans;
	while(scanf("%d",&n)!=-1&&n)
	{
		scanf("%d",&q);
		for(int i=1;i<=n;i++)scanf("%d",&num[i]);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&l,&r);
			ans=x=1;
			b=num[l];
			for(int i=l+1;i<=r;i++)
			{
				if(num[i]==b)x++;
				else
				{
					ans=max(ans,x);
					x=1;
					b=num[i];
				}
			}
			ans=max(ans,x);
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

