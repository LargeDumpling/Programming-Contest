/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-16	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,n,x,ans,mAx;
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		scanf("%d",&x);
		ans=-1; mAx=x; n--;
		while(n--)
		{
			scanf("%d",&x);
			ans=max(ans,mAx-x);
			mAx=max(mAx,x);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

