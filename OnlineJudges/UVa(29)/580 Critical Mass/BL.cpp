/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-07	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool check(int x)
{
	int num[31],cnt=0;
	for(num[0]=0;x;x>>=1)num[++num[0]]=x&1;
	for(int i=1;i<=num[0];i++)
	{
		if(num[i])
		{
			cnt++;
			if(cnt>=3)return true;
		}
		else if(!num[i])cnt=0;
	}
	return false;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int n,ans;
	while(scanf("%d",&n)!=-1&&n)
	{
		ans=0;
		for(int i=(1<<n)-1;i>=0;i--)if(check(i))ans++;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

