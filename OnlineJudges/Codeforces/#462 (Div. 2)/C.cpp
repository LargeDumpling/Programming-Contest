/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-14	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=2050;
int n,num[MAXN],s[MAXN],ans=1,mAx;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		s[i]=s[i-1]+(int)(num[i]==2);
	}
	for(int l=0;l<n;l++)
	{
		mAx=-2147483647;
		for(int r=l+1;r<=n;r++)
		{
			if(mAx!=-2147483647)
				ans=max(ans,mAx+l+r-2*s[l]-2*s[r]+s[n]);
			mAx=max(mAx,2*s[r]-r);
		}
	}
	s[n+1]=s[n];
	for(int i=1;i<=n+1;i++)
		ans=max(ans,i-1-s[i-1]+s[n]-s[i-1]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

