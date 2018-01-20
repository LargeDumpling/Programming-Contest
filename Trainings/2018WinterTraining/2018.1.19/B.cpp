/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int cnt[1050],T_T,n;
int main()
{
	int x,ans;
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(cnt,0,sizeof(cnt));
		ans=1;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		for(int i=2;i<=1000;i++)
			if(cnt[ans]<cnt[i])
				ans=i;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

