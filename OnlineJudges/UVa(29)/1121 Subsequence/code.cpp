/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-02-18	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,S,num[100050];
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int l,r,ans,now;
	while(scanf("%d%d",&n,&S)!=-1)
	{
		for(int i=1;i<=n;i++) scanf("%d",&num[i]);
		ans=2147483647;
		now=0;
		l=1; r=0;
		while(r<n)
		{
			now+=num[++r];
			while(l<r&&S<=now-num[l]) now-=num[l++];
			if(S<=now) ans=min(ans,r-l+1);
		}
		if(ans==2147483647) ans=0;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

