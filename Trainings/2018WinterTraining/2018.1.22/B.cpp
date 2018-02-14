/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-22	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T;
int n,num[550];
int main()
{
	freopen("overcode.in","r",stdin);
	int l,r,ans;
	scanf("%d",&T_T);
	while(T_T-->0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		sort(num+1,num+n+1);
		ans=0;
		l=1; r=6;
		while(r<=n)
		{
			if(num[r]<=num[l]+1000)
			{
				ans++;
				l=r+1;
				r=l+5;
			}
			else l++,r++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

