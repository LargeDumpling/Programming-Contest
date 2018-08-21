/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,ans;
long long limit;
int check(long long S)
{
	int cnt=0,tem;
	for(int i=0;i<n;i++)
	{
		tem=0;
		for(int j=0;j<m;j++)
			if((S>>(i*m+j))&1)
				tem++;
			else
			{
				tem--;
				if(tem<0)
					break;
			}
		if(tem==0)
			cnt++;
	}
	for(int j=0;j<m;j++)
	{
		tem=0;
		for(int i=0;i<n;i++)
			if((S>>(i*m+j))&1)
				tem++;
			else
			{
				tem--;
				if(tem<0)
					break;
			}
		if(tem==0)
			cnt++;
	}
	return cnt;
}
int main()
{
	long long ansS;
	while(true)
	{
		ans=0;
		while(true)
		{
			scanf("%d%d",&n,&m);
			if(n*m<=38)
				break;
			else puts("Too large");
		}
		limit=1LL<<(n*m);
		for(long long S=0;S<limit;S++) if(ans<check(S))
		{
			ans=check(S);
			ansS=S;
		}
		printf("%d\n",ans);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				if((ansS>>(i*m+j))&1)
					putchar('(');
				else putchar(')');
			putchar('\n');
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

